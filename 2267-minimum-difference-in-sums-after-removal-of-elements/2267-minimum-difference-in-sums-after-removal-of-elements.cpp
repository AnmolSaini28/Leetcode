class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        long long sum1=0,sum2=0;

        priority_queue<long long> p1;
        priority_queue<long long,vector<long long>,greater<long long>> p2;

        for(int i=0;i<n/3;i++){
            sum1+=nums[i];
            p1.push(nums[i]);
            sum2+=nums[n-i-1];
            p2.push(nums[n-i-1]);
        }

        vector<long long> temp;
        temp.push_back(sum1);
        for(int i=n/3;i<2*n/3;i++){
            if(p1.top()>nums[i]){
                sum1-=p1.top();
                p1.pop();
                sum1+=nums[i];
                p1.push(nums[i]);
            }
            temp.push_back(sum1);
        }
        
        int i=temp.size()-1;
        long long ans=temp[i]-sum2;
        i--;
        while(i>=0){
            if(p2.top()<nums[n/3+i]){
                sum2-=p2.top();
                p2.pop();
                sum2+=nums[n/3+i];
                p2.push(nums[n/3+i]);
            }
            ans=min(ans,temp[i]-sum2);
            i--;
        }

        return ans;
    }
};