class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int maxi = 0 ; 
//<!-- Here we create a unordered map which consist of key equal to bit position and value equal to the number of bitset in that particular location  -->
        unordered_map<int,int> mp ; 
// We run the loop from 0 position to 32 position because maximum bit will be 32  
        for(int i = 0 ; i < 32 ; i++)
        {
//<!-- Then run the loop for iterating each element of nums vector  -->
            for(int j = 0 ; j < nums.size() ; j++)
            {
//<!-- Here we check the bitset is present or not if present then we save the freq into the map -->
                if(nums[j] & (1 << i)) 
                {
                    mp[i]++ ; 
                }
            }
        }
//<!-- Here we find max in the value  -->
        for(auto x : mp)
        {
            if( maxi < x.second)
            {
                maxi = x.second ;
            }
        }
    return maxi ; 
    }
};