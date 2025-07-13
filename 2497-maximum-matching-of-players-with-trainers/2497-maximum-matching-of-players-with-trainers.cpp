class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int ans=0,i=0,j=0;
        while(i<p.size()&&j<t.size()){
            if(t[j]<p[i])j++;
            else{
                ans++;
                j++;i++;
            }
        }
        return ans;
        
    }
};