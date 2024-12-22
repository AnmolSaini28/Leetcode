class Solution {
public:

int binarySearch(vector<pair<int, int>> &st, int h){
    int s = 0, e = st.size()-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(st[mid].first > h){
            ans = mid;
            s = mid + 1;
        }
        else
        e = mid - 1;

        mid = s + (e-s)/2;
    }

    return ans;
}

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

        int n = heights.size(), q = queries.size();
        
        vector<int> ans(q , -1);

        vector<vector<pair<int, int>>> skip(n); // for case like h[u] > h[v] 

        for(int i=0 ;i<q ;i++){
            int u = min(queries[i][0], queries[i][1]);
            int v = max(queries[i][0], queries[i][1]);

            if(heights[v] > heights[u] || u == v)
            ans[i] = v;

            else    // v > u and hights[u] > heights[v]
            skip[v].push_back({heights[u], i});  // find max of heights[u] for query i and index we have to check for index v
        }

        vector<pair<int, int>> st; 
        // take vector so that we can apply binary search 
        // take pair to avoid passing the heights vector in binary search

        for(int i=n-1 ;i>=0 ;i--){
            while(!st.empty() && heights[i] >= st.back().first)
            st.pop_back();

            for(auto pa:skip[i]){
                int h = pa.first;
                int ind = pa.second;
                  
                int val = binarySearch(st, h);
                
                if(val != -1)
                ans[ind] = st[val].second;
            }

            
            st.push_back({heights[i], i});
        }

        return ans;
    }
};