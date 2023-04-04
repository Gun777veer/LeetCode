class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        int n1=t.length();

        if(n!=n1){
            return false;
        }

        if(s==t){
            return true;
        }

        map<char, int> m,m1;

        for(int i=0; i<n; i++){
            m[s[i]]++;
            m1[t[i]]++;
        }

        if(m1.size()!=m.size()){
            return false;
        }


        // for(auto i=m.begin(), auto j=m1.begin(); i!=m.end(); ++i){
            
        // }

        for(int i=1; i<n; i++){
            if((s[i]==s[i-1] && t[i]!=t[i-1]) || (t[i]==t[i-1] && s[i]!=s[i-1])){
                return false;
            }

            else if(s[i]==t[i]){
                return false;
            }
        }

        return true;


    }
};
