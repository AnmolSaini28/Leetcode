class Solution {
public:
    int simulate(string &s, char good1,char good2,int k){
        int score =0;
        int maxscore =0;
        for(char c:s){
            if(c==good1 || c==good2){
                score++;
                maxscore=max(score,maxscore);
            } 
            else if(k>0){
                k--;
                score++;
                maxscore=max(score,maxscore);
            }else{
                score--;
                maxscore=max(score,maxscore);
            }
        }
        return maxscore;
    }
    int maxDistance(string s, int k) {
        int s1 = simulate(s,'N','E',k);
        int s2 = simulate(s,'N','W',k);
        int s3 = simulate(s,'S','E',k);
        int s4 = simulate(s,'S','W',k);
        return max({s1,s2,s3,s4});

    }
};