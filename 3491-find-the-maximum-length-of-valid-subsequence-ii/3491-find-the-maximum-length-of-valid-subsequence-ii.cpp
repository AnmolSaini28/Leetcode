class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // 1. Bucket indices by their value mod k
        vector<vector<int>> mod(k);
        for (int i = 0; i < n; i++) {
            mod[nums[i] % k].push_back(i);
        }
        
        int res = 0;
        // 2. Try every unordered pair of residues (u, v)
        for (int u = 0; u < k; u++) {
            if (mod[u].empty()) continue;
            for (int v = u; v < k; v++) {
                if (mod[v].empty()) continue;
                
                // Decide which residue starts (smaller first index)
                int i = u, j = v;
                if (mod[v][0] < mod[u][0]) 
                    swap(i, j);
                
                // 3. Simulate alternating picks between mod[i] and mod[j]
                int a = mod[i][0];     // last chosen index
                int count = 1;         // length so far
                int turn = 1;          // 1 means pick from j next, 2 means from i
                res = max(res, count);
                
                while (true) {
                    if (turn % 2 == 1) {
                        auto it = upper_bound(mod[j].begin(), mod[j].end(), a);
                        if (it == mod[j].end()) break;
                        a = *it;
                    } else {
                        auto it = upper_bound(mod[i].begin(), mod[i].end(), a);
                        if (it == mod[i].end()) break;
                        a = *it;
                    }
                    count++;
                    res = max(res, count);
                    turn++;
                }
            }
        }
        
        return res;
    }
};