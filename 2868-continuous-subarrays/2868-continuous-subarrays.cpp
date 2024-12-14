class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int , int > ma;

        int i = 0;
        int j = 0;
long long count = 0;
        while(j < n){

            ma[nums[j]]++;

while(abs(ma.rbegin()->first - ma.begin()->first) > 2){
    ma[nums[i]]--;
 if(ma[nums[i]] == 0) {
                    ma.erase(nums[i]);
                }
    i++;
}

count += j-i+1;
j++;
        }

        return count;
    }
};