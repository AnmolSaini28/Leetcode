class Solution {
private:
    vector<int> findRightSmaller(vector<int> &a)
    {
        int n=a.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()  && a[st.top()]>a[i])
                st.pop();
            if(st.size())
                ans[i]=a[st.top()];
            st.push(i);
        }
        return ans;
    }


public:
    vector<int> finalPrices(vector<int>& a) {
        //We Need to find the first minimum from right side 
        vector<int> rightSmaller=findRightSmaller(a);
        for(int i=0;i<a.size();i++)
            a[i]-=rightSmaller[i];
        return a;
    }
};