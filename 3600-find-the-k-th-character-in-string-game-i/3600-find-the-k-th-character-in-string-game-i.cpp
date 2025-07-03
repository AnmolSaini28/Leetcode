class Solution {
public:
    char kthCharacter(int k) {

        string s = "a";

        while(s.size()<k){
            int size = s.size();

            for(int i = 0; i < size; i++){
                if(s[i] != 'z'){
                    s += s[i] + 1;
                }else{
                    s += 'a';
                }
            }
        }
        return s[k-1];
    }
};