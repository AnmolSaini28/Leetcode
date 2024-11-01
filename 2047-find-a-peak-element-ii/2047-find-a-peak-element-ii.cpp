class Solution {
public:
    int check(int mid, vector<vector<int>>& mat){
        int m=mat.size(); // denotes the number of rows
        int maxEle=INT_MIN;
        int maxIdx=-1;
        for(int i=0;i<m;i++){
            if(maxEle<mat[i][mid]){
                maxEle=mat[i][mid];
                maxIdx=i;
            }
        }
        return maxIdx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // TC O(nlogm) SC O(1)
        int m=mat.size(); // denotes the number of rows
        int n=mat[0].size(); // denotes the number of col
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int maxRowIdx=check(mid,mat);
            int left=mid-1>=0 ? mat[maxRowIdx][mid-1] : -1;
            int right=mid+1<n ? mat[maxRowIdx][mid+1] : -1;
            if(left<mat[maxRowIdx][mid] && right<mat[maxRowIdx][mid]) return{maxRowIdx,mid};
            else if(left>mat[maxRowIdx][mid]) hi=mid-1;
            else lo=mid+1;
        }
        return {-1,-1};
    }
};