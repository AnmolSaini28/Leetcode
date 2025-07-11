#define ll long long

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int,vector<int>, greater<int>> free;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> use;
        
        for(int i=0;i<n;i++){
            free.push(i);
        }

        map<int, int> mp;
        ll time = 0;
        for(int i=0;i<meetings.size();i++){
            time = meetings[i][0];  
            while(!use.empty() && time >= use.top().first){
                free.push(use.top().second);
                use.pop();
            }
            if(free.empty()){
                auto [endtime, node] = use.top();
                use.pop();
                mp[node]++;
                use.push({endtime + (meetings[i][1] - meetings[i][0]), node});
            }
            else{
                int node = free.top();
                free.pop();
                mp[node]++;
                use.push({meetings[i][1], node});
            }
        }

        int maxi = INT_MIN;
        int maxival = -1;
        for(auto x: mp){
            if(x.second > maxi){
                maxival = x.first;
                maxi = x.second;
            }
        }
        return maxival;
    }
};