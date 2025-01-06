class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.length();
        vector<int> ans(n,0);

        int leftSum=0, rightSum=0;
        int netSum=0;
        
        for(int i=0;i<n;i++){
            ans[i]+=netSum;
            leftSum+=s[i]-'0';
            netSum+=leftSum;
        }
        netSum=0;
        for(int i=n-1;i>=0;i--){
            ans[i]+=netSum;
            rightSum+=s[i] - '0';
            netSum+=rightSum;
        }


        return ans;
    }
};