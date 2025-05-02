class Solution {
public:
    string pushDominoes(string dominoes) {
        int i = 0;
        int n = dominoes.length();  
        while (i < n) {
            if (dominoes[i] != '.') {
                i++;
            } else {
                int start = i;
                int j = start;
                while (j < n && dominoes[j] == '.') {
                    j++;
                }
                char left = (start > 0) ? dominoes[start - 1] : '.';
                char right = (j < n) ? dominoes[j] : '.';

                if (left == 'R' && right == 'L') {
                    int l = start;
                    int r = j - 1;
                    while (l < r) {
                        dominoes[l++] = 'R';
                        dominoes[r--] = 'L';
                    }
                }
                else if (left == 'R' && right != 'L') {
                    for (int l = start; l < j; l++) {
                        dominoes[l] = 'R';
                    }
                }
                else if (left != 'R' && right == 'L') {
                    for (int k = start; k < j; k++) {
                        dominoes[k] = 'L';
                    }
                }
    
                i = j;  
            }
        }
        return dominoes;  
    }
};