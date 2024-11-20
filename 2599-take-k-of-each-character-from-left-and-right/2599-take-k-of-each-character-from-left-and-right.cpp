class Solution {
public:
    int bin(vector<int>&a,vector<int>&b,vector<int>&c,int num1,int num2,int num3,int l)
    {
        int r=a.size();
        while(r>l+1)
        {
            int mid=(l+r)/2;
            if(a[mid]<num1 || b[mid]<num2 || c[mid]<num3)
            r=mid;
            else
            l=mid;
        }
        if(a[l]>=num1 && b[l]>=num2 && c[l]>=num3)
        return l;

        return -1;
    }
    int takeCharacters(string s, int k) {
        
        int n=s.length();
        int ap=0,bp=0,cp=0;
        vector<int> a(n,0);
        vector<int> b(n,0);
        vector<int> c(n,0);

        if(k==0)
        return 0;

        if(s[n-1]=='a')
        a[n-1]=1;
        else if(s[n-1]=='b')
        b[n-1]=1;
        else
        c[n-1]=1;

        for(int i=n-2; i>=0; i--)
        {
            if(s[i]=='a')
            {
                a[i]=1+a[i+1];
                b[i]=b[i+1];
                c[i]=c[i+1];
            }
            if(s[i]=='b')
            {
                a[i]=a[i+1];
                b[i]=1+b[i+1];
                c[i]=c[i+1];
            }
            if(s[i]=='c')
            {
                a[i]=a[i+1];
                b[i]=b[i+1];
                c[i]=1+c[i+1];
            }
        }

        int in=bin(a,b,c,k,k,k,0);
        int ans;
        if(in==-1)
        ans=-1;
        else
        ans=n-in;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='a')
            ap++;
            else if(s[i]=='b')
            bp++;
            else
            cp++;

            if(ap>=k && bp>=k && cp>=k)
            ans=min(ans,i+1);

            int in=bin(a,b,c,k-ap,k-bp,k-cp,i);
            if(in>i)
            ans=min(ans,i+1+(n-in));
        }
        return ans;
    }
};