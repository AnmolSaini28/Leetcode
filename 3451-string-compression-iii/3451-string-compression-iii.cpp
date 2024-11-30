class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        for(int i = 0; i < word.length(); i++){
            if (i + 1 < word.length() && word[i] == word[i + 1]) {
                count++;
            } else {
                // Handle the case when count > 9
                while (count > 9) {
                    comp += '9'; // Append '9'
                    comp += word[i]; // Append the character
                    count -= 9; // Reduce the count by 9
                }
                // Append the remaining count (which will be <= 9)
                if (count > 0) {
                    comp += std::to_string(count) + word[i];
                }
                count = 1; // Reset count for the next character
            }
        }
        
        return comp;
    }
};