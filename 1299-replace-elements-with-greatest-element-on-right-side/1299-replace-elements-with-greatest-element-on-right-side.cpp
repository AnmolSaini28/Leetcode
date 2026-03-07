class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector <int> res;
        int n = arr.size();
        int curr = -1;
        for(int i=n-1 ; i>=0 ; i--){
            res.push_back(curr);
            curr = max(curr,arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};