class Solution
{
public:
    // minimizedMaximum - stub provided by LeetCode.
    int minimizedMaximum(int          n,
                         vector<int> &quantities)
    {
        // Calculate range for binary search (closed range i.e. inclusive).
        int resultFront = 1;
        int resultBack  = *max_element(quantities.begin(), quantities.end());

        // Reduce all quantities by 1, so that instead of the max products per
        // store being (quantity+stores-1)/stores, it'll be quantity/stores+1.
        // Note that when calculating the stores needed for all M quantities
        // combined, the 1 can be added at the end for all quantities combined,
        // i.e. the total becomes sum(quantity/stores) + quantities.
        // The total for stores-quantities then becomes sum(quantity/stores).
        for_each(quantities.begin(), quantities.end(),
                 [](int &quantity){--quantity;});

        // Perform binary search.
        int       resultGuess;
        int       storesMinusQuantities;
        const int nMinusQuantities = n - quantities.size();
        while (resultFront < resultBack)
        {
            // Guess max products per store required.
            resultGuess = (resultFront + resultBack) >> 1;

            // Calculate number of stores-quantities required for guess.
            storesMinusQuantities = 0;
            for (const int quantity: quantities)
                storesMinusQuantities += quantity / resultGuess;

            // Adjust range. Note that even if stores == n, there's no
            // guarantee that we've reached an optimal solution, just a working
            // solution.
            if (storesMinusQuantities <= nMinusQuantities)
                resultBack  = resultGuess;
            else
                resultFront = resultGuess+1;
        }
        return resultFront;
    }
};

static const int speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();