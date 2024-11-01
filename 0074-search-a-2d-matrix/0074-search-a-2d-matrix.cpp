class Solution {
public:
    int search(vector<int>& nums, int low, int high, int target) {
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low1 = 0;
        int high1 = m-1;
        while(low1 <= high1){
            int mid1 = (low1+high1)/2;
            if(matrix[mid1][0] == target){
                return true;
            }
            else if(matrix[mid1][0] < target){
                if(matrix[mid1][n-1] == target){
                    return true;
                }
                else if(matrix[mid1][n-1] > target){
                    if(search(matrix[mid1],0,n-1,target) != -1) return true;
                    else high1 = mid1-1;
                }
                else{
                    low1 = mid1+1;
                }
            }
            else{
                high1 = mid1-1;
            }
        }
        return false;
    }
};