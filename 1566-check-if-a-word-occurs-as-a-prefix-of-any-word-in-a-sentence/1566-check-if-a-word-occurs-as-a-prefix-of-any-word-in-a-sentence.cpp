class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int len = searchWord.size();
        int cnt = len, ans = 1, i = 0;
        int n = sentence.size(), j = 0;

        while (j < n) {
            if (sentence[j] == ' ') {
                ans++;
            } else {
                i = 0;
                if (j == 0 || sentence[j - 1] == ' ') {
                    while (sentence[j] == searchWord[i]) {
                        cnt--;
                        if (cnt == 0) {
                            return ans;
                        }
                        i++;
                        j++;
                    }
                    if (sentence[j] == ' ') {
                        ans++;
                    }
                    cnt = len;
                }
            }
            j++;
        }
        return -1;
    }
};