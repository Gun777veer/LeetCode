class Solution {
    public int strStr(String haystack, String needle) {
        // int n=haystack.length();
        // int m=needle.length();

        // int i=0;
        // int j=0; 
        // int count=-1;
        // int flag=0;

        // while(j<m-1){
        //     if(haystack.charAt(i)==needle.charAt(j)){
        //         i++;
        //         j++;
        //         flag=1;
        //     }
        //     else{
        //         j=0;
        //         i++;
        //         flag=0;
        //     }
        // }

        // if(flag==1){
        //     for(int a=0; a<n; a++){
        //         if(haystack.charAt(a)==needle.charAt(0)){
        //             count=a;
        //             break;
        //         }

        //         return count;
        //     }
        // }

        if(haystack.contains(needle)){
            return haystack.indexOf(needle);
        }

        return -1;

    }
}
