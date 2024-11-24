class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        long long sum=0;
        int minval=INT_MAX;
        int negcount=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                sum+=abs(matrix[i][j]);
                minval=min(minval,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    negcount++;
                }
            }
        }
        if(negcount%2==0){
            return sum;
        }
        else{
            return sum-2*minval;
        }
    }
};