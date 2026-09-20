class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int n = s.size();
        vector <int > arr(n,0);
        for (int i = 0; i < n; i++) {
            arr[i] = (26 - (s[i] - 'a')) * (i + 1);
            sum += arr[i];
        }
        return sum;
    }
};