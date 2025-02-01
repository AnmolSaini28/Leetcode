class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n  = nums.size();
        int previous_digit = nums[0];
        bool isTrue = true;;

        for(int i = 1 ; i < n  ; i++){
            if((nums[i]+ previous_digit) % 2 == 0){
                isTrue = false;
            }
            previous_digit = nums[i];
        }
            return isTrue;

    }

};