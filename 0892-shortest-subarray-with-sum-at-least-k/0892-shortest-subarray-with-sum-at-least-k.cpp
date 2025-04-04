class Solution { 
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();

        // find the prefix sum of the given array nums -: 
        // Size is n+1 to handle subarrays starting from index 0
        vector<long long>prefixSum(n+1,0); 

        // Calculating prefix sums
        for(int i=1; i<=n; i++){
            prefixSum[i]=prefixSum[i-1]+nums[i-1];
        }

        // Make a deque (doubly-ended queue -: which allows us to add/remove ele.s
        // from both front/end side. 
        deque<int>candiIdx;

        int len=INT_MAX;

        for(int i=0; i<=n; i++){
            // Remove candidates from front of deque where subarray sum meets target sum
            while(!candiIdx.empty() && prefixSum[i]-prefixSum[candiIdx.front()]>=k){
                len=min(len,i-candiIdx.front());
                candiIdx.pop_front();
            }
            // Maintain monotonicity by removing indices with larger prefix sums
            while(!candiIdx.empty() && prefixSum[i]<=prefixSum[candiIdx.back()]) {
                candiIdx.pop_back();
            }
            // Add current index to candidates
            candiIdx.push_back(i);
        }
        // Return -1 if no valid subarray found
        return len == INT_MAX ? -1 : len;
   }
};