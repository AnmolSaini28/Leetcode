
class Solution
{
    public:
        int maxChunksToSorted(vector<int> &arr)
        {
            int cuts = 0;
            int mask = 0;

            int n = arr.size();
            int val = 0;
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                mask = ((1 << arr[i]) | mask);

                int x = (1 << (i + 1)) - 1;
               
                if(arr[i] == val) found = true;

                if (found)
                {
                    if (mask == x && i != n - 1)
                    {
                        cuts++;
                        val = i + 1;
                        found = false;
                    }
                }

                
            }

            return cuts + 1;
        }
};