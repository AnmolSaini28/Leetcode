class Solution {
public:
    char solve(long long k, vector<int>&op){
        if(k==1)return 'a';
        long long sub = 1;
        long long t = ceil(log(k)/log(2));
        for(int i=0;i<t-1;i++)sub<<=1;
        char a =  solve(k-sub, op);
        if(t>0 and t<=op.size() and op[t-1]==0)return a;
        if(a=='z')return 'a';
        return a+1;
    }
    char kthCharacter(long long k, vector<int>& operations) {     
        return solve(k, operations);
    }
};
