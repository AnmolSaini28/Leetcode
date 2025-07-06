class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq1; // frequency map for nums1
    unordered_map<int, int> freq2; // frequency map for nums2

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for (int n : nums1) freq1[n]++;
        for (int n : nums2) freq2[n]++;
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;
        if (freq2[oldVal] == 0) freq2.erase(oldVal);

        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int cnt = 0;
        for (auto [a, freqA] : freq1) {
            int b = tot - a;
            if (freq2.count(b)) {
                cnt += freqA * freq2[b];
            }
        }
        return cnt;
    }
};