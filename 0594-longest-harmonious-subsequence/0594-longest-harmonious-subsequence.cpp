class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int>mp;

        for(auto num:nums)
            mp[num]++;
        
        for(auto x:mp){
            int num = x.first;
            int freq = x.second;
            int nextNum = num+1;
            if(mp.find(nextNum) == mp.end())
                continue;
            int nextFreq = mp[nextNum];
            ans = max(ans, freq+nextFreq);
        }
        
        return ans;
        
    }
};