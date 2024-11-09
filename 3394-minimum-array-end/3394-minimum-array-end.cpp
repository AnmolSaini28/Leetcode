class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long a=x, i=1;
        while(n>0)
        {
            if((a&i)==0)
            {
                a+=i*(n%2);
                n=n>>1;
            }
            i=i<<1;
        }
        return a;
    }
};