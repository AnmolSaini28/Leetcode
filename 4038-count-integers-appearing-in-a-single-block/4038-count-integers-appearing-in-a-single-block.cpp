class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int specialCount = 0;
        unordered_map <int , int> mp;
        if(n == 1) return 1;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++;
        }
        mp[nums[0]]--;
        if(mp[nums[0]] == 0) specialCount++;
        for(int i=1 ; i<n ; i++){
            mp[nums[i]]--;
            if(nums[i] != nums[i-1] && mp[nums[i-1]] != 0){
                mp[nums[i-1]]++;
            }
            if(mp[nums[i]] == 0){
                specialCount++;
            }
        }
        return specialCount;
    }
};