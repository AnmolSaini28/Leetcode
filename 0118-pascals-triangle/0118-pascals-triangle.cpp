class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>arr;
        vector<int>prev;
        for(int i=1;i<=numRows;i++){
            vector<int>brr;
            if(i==1){
                brr.push_back(1);
                arr.push_back(brr);
            }
            if(i==2){
                brr.push_back(1);
                brr.push_back(1);
                arr.push_back(brr);
                prev=brr;
            }
            if(i>=3){
                brr.push_back(1);
                for(int i=0;i<prev.size()-1;i++){
                    brr.push_back(prev[i]+prev[i+1]);
                }
                brr.push_back(1);
                prev=brr;
                arr.push_back(brr);
            }
        }
            return arr;
    }
};