class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotateTop = 0, rotateBottom = 0;

        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;  // Can't make this domino match the target
            } else if (tops[i] != target) {
                rotateTop++;  // Need to rotate to get target on top
            } else if (bottoms[i] != target) {
                rotateBottom++;  // Need to rotate to get target on bottom
            }
        }

        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = check(tops[0], tops, bottoms);
        if (res != -1 || tops[0] == bottoms[0]) return res;
        return check(bottoms[0], tops, bottoms);
    }
};
