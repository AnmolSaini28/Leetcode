class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int l=0,r=0,len=0,count=0;
        unordered_map<int,int> m;
        while(r<n){
            m[arr[r]]++;
            if(m.size() > 2){
                m[arr[l]]--;
                if(m[arr[l]] == 0) m.erase(arr[l]);
                l++;
            }
            if(m.size() <= 2){
                len = max(len,r-l+1);
            }
            r++;
        }
        return len;
    }
};