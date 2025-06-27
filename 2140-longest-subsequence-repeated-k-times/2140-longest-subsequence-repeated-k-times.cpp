class Solution {
public:
    bool isSubsequence(string& s, string& sub) {
        int i = 0, j = 0;
        while (i < s.size() && j < sub.size()) {
            if (s[i] == sub[j]) j++;
            i++;
        }
        return j == sub.size();
    }

    bool isGood(string& temp, string& s, int k){
        string repeated = "";
        for(int i = 0; i < k; i++) repeated += temp;
        return isSubsequence(s, repeated);
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector <int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;

        for(int i = 0; i < 26; i++){
            if(freq[i] < k) freq[i] = 0;
            else freq[i] /= k;
        }

        queue <string> q;
        string ans;
        q.push("");

        while(!q.empty()){
            string str = q.front(); q.pop();
            vector <int> newFreq = freq;
            for(char c : str) newFreq[c - 'a']--;
            for(int j = 25; j >= 0; j--){
                char c = 'a' + j;
                if(newFreq[j] == 0) continue;
                if(str.length() == 7) continue;
                str.push_back(c);
                if(isGood(str, s, k)){
                    q.push(str);
                    if(str.length() > ans.length()){
                        ans = str;
                    }
                }
                str.pop_back();
            }
        }

        return ans;
    }
};