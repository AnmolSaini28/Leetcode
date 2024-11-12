class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        std::vector<int64_t> vCache;
        vCache.reserve(items.size());

        // 1. build the cache
        for (std::vector<int> const &item : items)
        {
            int64_t const price = item[0];
            int64_t const beauty = item[1];

            vCache.emplace_back((price << 32) | (beauty));
        }
        // 2. sort the cache by price
        std::sort(vCache.begin(), vCache.end());

        // 3. transform beaty into max_beauty in cache
        int max_beauty = 0;
        for (int64_t &nCache : vCache)
        {
            max_beauty = std::max(max_beauty, static_cast<int>(nCache));
            nCache = (nCache & ((~0ll) << 32)) | max_beauty;
        }

        // 4. answer to query
        for (int &query : queries)
        {
            auto const itCache = std::upper_bound(vCache.rbegin(), vCache.rend(), int64_t(query + 1) << 32, std::greater<int64_t>{});
            query = itCache != vCache.rend() && ((*itCache) >> 32) <= query ? int(*itCache) : 0;
        }

        return queries;
    }
};

#include <iostream>
static auto _______ = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();