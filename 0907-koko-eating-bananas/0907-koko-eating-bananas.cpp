class Solution {
public:
long long f(vector<int>x,long long hr,long long n)
    {
        long long thr=0;
        for(long long i=0;i<n;i++)
        {
            thr+=ceil((double)x[i]/(double)hr);
        }
        return thr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size(),max=INT_MIN;
        for(long long i=0;i<n;i++)
        {
            if(piles[i]>max) max=piles[i];
        }
        long long low=1,high=max;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            long long thr=f(piles,mid,n);
            if(thr<=h)
            {high=mid-1;}
            else
            low=mid+1;
            
        }
        return low;
    }
};