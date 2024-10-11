class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        int totVal = 0;
        int n = truckSize;
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i][0] < n){
                totVal += (arr[i][0]*arr[i][1]);
                n -= arr[i][0];
            }
            else{
                totVal += (n*arr[i][1]);
                break;
            }
        }
        return totVal;
    }
};