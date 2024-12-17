class Solution {
    int findLastChar(vector<int>&freq , int i){
        int idx = i -1 ;
        while(idx >= 0){
            if(freq[idx] > 0) return idx ;
            idx-- ;
        }
        return -1 ;
    }
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26, 0) ;
        for(auto ch : s){
            freq[ch - 'a']++ ;
        }

        string ans = "" ;
        bool isLeft = false ;
        int i = 25 ;
        while(i >= 0){
            auto ch = i + 'a' ;
            if(freq[i] > repeatLimit){
                isLeft = true ;
                while(isLeft){
                    int cnt = 0;
                    while(cnt < repeatLimit) ans += ch , cnt++ ;
                    freq[i] -= repeatLimit ;
                    int idx = findLastChar(freq , i) ;
                    if(idx == -1) break ;
                    ans += (idx + 'a') ;
                    freq[idx]-- ;
                    if(freq[i] <= repeatLimit) isLeft = false ;
                }
            }
            if(freq[i] > 0 && !isLeft){
                int cnt = 0 ;
                while(cnt < min(repeatLimit , freq[i])) ans += ch , cnt++ ;
                freq[i] -= min(freq[i] , repeatLimit) ;
            }
            i-- ;
        }

        return ans ;
    }
};