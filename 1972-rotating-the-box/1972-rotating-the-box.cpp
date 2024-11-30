class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(), m=box[0].size();
        vector<map<int, int>> mp(n);
        int cnt=0;
        vector<vector<char>> temp(n, vector<char> (m, '.'));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(box[i][j]=='#'){
                    cnt++;
                }
                else if(box[i][j]=='*'){
                    mp[i].insert({j, cnt});
                    cnt=0;
                }

                if(j==m-1){
                    mp[i].insert({-1, cnt});
                    cnt=0;
                }
            }
        }

        // for(auto &x: mp){
        //     for(auto &y: x){
        //         cout<<y.first<<" "<<y.second<<endl;
        //     }
        // }

        for(int i=0; i<n; i++){
            for(auto &x: mp[i]){
                int j, d;
                if(x.first==-1) j=m-1;
                else{
                    j=x.first-1;
                    temp[i][j+1]='*';
                } 
                d=j-x.second;

                for(; j>d; j--){
                    temp[i][j]='#';
                }
            }
        }

        vector<vector<char>> ans(m, vector<char> (n));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[j][n-i-1]=temp[i][j];
            }
        }

        return ans;
    }
};