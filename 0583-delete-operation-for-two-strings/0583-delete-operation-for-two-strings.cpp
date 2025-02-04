class Solution {
public:
int LCS(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();
    if(n == 0 || m == 0) return 0;
    vector <vector <int>> dp(n + 1 , vector <int> (m+1, 0));

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}
    int minDistance(string word1, string word2) {
        int lcs = LCS(word1 , word2);
        int n = word1.length();
        int m = word2.length();
        return (n-lcs) + (m-lcs);
    }
};