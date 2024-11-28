typedef pair<int,pair<int,int>> pi;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        int value=0;
        if(grid[0][0]==1) value=1;
        dist[0][0]=value;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({dist[0][0],{0,0}});
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            int dis=a.first,r=a.second.first,c=a.second.second;
            for(int i=0;i<4;i++){
                int nr=r+dx[i],nc=c+dy[i];
                int val=0;
                if(nr>=0&&nr<m&&nc>=0&&nc<n){
                    if(grid[nr][nc]==1) val=1;
                    if(val+dis<dist[nr][nc]){
                        dist[nr][nc]=val+dis;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};