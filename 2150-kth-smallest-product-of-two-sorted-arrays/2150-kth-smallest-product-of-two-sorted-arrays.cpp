class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long high = 1e10 + 4;
        long long low = -1*high;
        long long x = low + (high - low)/2;
        long long ans = high;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(low <= high){
            x = low + (high - low)/2;
            bool possible = false;

            long long count = 0; 
            for(int i = 0; i<n1; i++){
                int a = nums1[i];
                if(a > 0){
                    long long threshold = floor((double) x / a);
                    int no = upper_bound(nums2.begin(), nums2.end(), threshold) - nums2.begin();
                    count += no;
                }else if(a < 0){
                    long long threshold = ceil((double) x / a);
                    int no = lower_bound(nums2.begin(), nums2.end(), threshold) - nums2.begin();
                    count += (n2 - no);
                }else{
                    if(x >= 0){
                        count += n2;
                    }
                }

                if(count >= k){
                    possible = true;
                    break;
                }
            }

            if(possible){
                ans =  x;
                high = x-1;
            }else{
                low = x+1;
            }
        }

        return ans;
    }
};