class Solution {
public:
    int findLucky(vector<int>& arr) {

        map<int,int> temp;
        int res=-1;

        for(int i=0;i<arr.size();i++)
            temp[arr[i]]++;

        for(auto x:temp)
        {
            int num=x.first;
            int freq=x.second;
            if(num==freq)
                res=max(res,num);
        }

        return res;
        
    }
};