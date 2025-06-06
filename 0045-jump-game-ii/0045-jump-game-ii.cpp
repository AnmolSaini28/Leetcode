class Solution {
public:
    int jump(vector<int>& nums) {
        int j = 0;  
        int CE = 0; 
        int far = 0; 
        for (int i = 0; i < nums.size() - 1; i++) {  
            far = max(far, i + nums[i]);
            if (i == CE) {
                j++;
                CE = far;  
            }
        }
        return j;  
    }
};