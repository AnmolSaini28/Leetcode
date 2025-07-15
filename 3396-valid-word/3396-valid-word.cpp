class Solution {
public:
    bool isValid(string word) {
        int charVal = 0;
        bool digit = false;
        bool vowel = false;
        bool consonanat = false;
        bool upper = false;
        bool lower = false;
        for(int i=0 ; i<word.length() ; i++){
            if(word[i]>='0' && word[i] <='9'){
                digit = true;
            }
            if(word[i]>='a' && word[i]<='z'){
                lower = true;
                //charVal++;
                if(word[i] =='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                vowel = true;
                }
                else{
                    consonanat = true;
                }
            }
            if(word[i]>='A' && word[i]<='Z'){
                upper = true;
                //charVal++;
                if(word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i] =='O' || word[i] =='U'){
                vowel = true;
            }
                else{
                    consonanat = true;
                }
            }
            if(word[i] == '@' || word[i] == '$' || word[i] == '#'){
                return false;
            }
            charVal++;
        }
        if(charVal >= 3 && vowel == true && consonanat == true){
            if(digit == true || upper == true || lower == true)
            return true;
        }
        else{
            return false;
        }
        return false;
    }
};