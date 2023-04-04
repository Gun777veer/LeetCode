class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n=arr.size();

        int t=0;

        for(int i=0; i<n; i++){
            t+=arr[i];
        }

        int l=0;


        for(int i=0; i<n; i++){
            if(l==t-l-arr[i]){
                return i;
            }
            l+=arr[i];
        }

         return -1;
    }
};
