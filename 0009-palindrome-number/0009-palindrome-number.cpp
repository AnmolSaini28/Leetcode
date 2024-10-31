class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x > 0 || x < 0){
            int ld = x%10;
            if((pow(2,31)-1)/10 < ans || -pow(2,31)/10 > ans){
                return 0;
            }
            ans = ans*10+ld;
            x = x/10;
        }
        return (int) ans;
    }
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int rev = reverse(x);
        return (rev == x);
    }
};