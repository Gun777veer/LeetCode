class Solution {
public:
    struct FenwickTree {
        vector<int> bit;
        int n;
        FenwickTree(int size) : n(size), bit(size + 1, 0) {}

        void update(int i, int val) {
            for (++i; i <= n; i += i & -i)
                bit[i] += val;
        }

        int query(int i) {
            int res = 0;
            for (++i; i > 0; i -= i & -i)
                res += bit[i];
            return res;
        }

        int queryRange(int l, int r) {
            return query(r) - query(l - 1);
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; ++i) {
            pos2[nums2[i]] = i;
        }

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = pos2[nums1[i]];
        }

        vector<int> leftCount(n, 0);
        vector<int> rightCount(n, 0);
        FenwickTree leftTree(n), rightTree(n);

        // Right side count first
        for (int i = n - 1; i >= 0; --i) {
            rightCount[i] = rightTree.query(n - 1) - rightTree.query(arr[i]);
            rightTree.update(arr[i], 1);
        }

        long long result = 0;

        for (int i = 0; i < n; ++i) {
            leftCount[i] = leftTree.query(arr[i] - 1);
            result += (long long)leftCount[i] * rightCount[i];
            leftTree.update(arr[i], 1);
        }

        return result;
    }
};
