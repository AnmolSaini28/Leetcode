class Solution {
public:
    
    long long f(long long x,long long y)
    {
        if(y==0)
         return 1;
        long long res=f(x,y/2);
        long long a= (res*res)% (long long)(1e9+7);
        
        if(y%2==1)
         a*=x % (long long)(1e9+7);
        return a;

    }
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        int i=0,j=nums.size()-1;
        long long sum=0;

        while(i<=j)
        {
            if(nums[i]+nums[j]<=target)
            {
                int  x = f(2,(j-i));  
                sum+=x ;
                sum%=(long long)(1e9+7);
                i++; 
            }
            else
                j--;
        }
        return sum;
       
    }
};