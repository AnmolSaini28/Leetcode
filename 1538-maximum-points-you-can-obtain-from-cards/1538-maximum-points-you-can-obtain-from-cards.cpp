class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        for(int i=0 ; i<k ; i++){
            ans += cardPoints[i];
        }
        int curr = ans;
        for(int i=k-1 ; i>=0 ; i--){
            curr = curr-cardPoints[i];
            curr = curr+cardPoints[n-k+i];
            ans = max(ans,curr);
        }
        return ans;
    }
};