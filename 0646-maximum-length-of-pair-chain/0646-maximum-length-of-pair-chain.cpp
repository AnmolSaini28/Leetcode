class Solution {
public:
static bool mycmp(vector<int>& arr1, vector<int>& arr2){
      if(arr1[1] < arr2[1]){
          return true;
      }
      return false;
  }
    int findLongestChain(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),mycmp);
        int cnt = 1;
        int endTime = arr[0][1];
        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i][0] > endTime){
                cnt++;
                endTime = arr[i][1];
            }
        }
        return cnt;
    }
};