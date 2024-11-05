class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0,r=0,len=0,changes=0,maxf=0;
        vector <int> m(26,0);
        while(r < n){
            m[s[r]-'A']++;
            maxf = max(maxf,m[s[r]-'A']);
            changes = (r-l+1)-maxf;
            if(changes <= k){
                len = max(len,r-l+1);
            }
            else{
                m[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return len;
    }
};