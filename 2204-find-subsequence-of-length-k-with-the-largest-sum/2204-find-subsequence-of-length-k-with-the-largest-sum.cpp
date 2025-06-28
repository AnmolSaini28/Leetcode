class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Min heap: (value, index)

        // Keep only the k largest elements
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            if (pq.size() > k)
                pq.pop();
        }

        // Collect elements from the heap
        vector<pair<int,int>> temp;
        while (!pq.empty()) {
            temp.push_back(pq.top());
            pq.pop();
        }

        // Sort by original index to maintain order
        sort(temp.begin(), temp.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        });

        // Extract values
        vector<int> ans;
        for (auto item : temp)
            ans.push_back(item.first);

        return ans;
    }
};