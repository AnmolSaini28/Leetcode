class Solution {
public:
    string count(string s, string del, int m, int &ans){
        stack<char> st;
        string ss="";
     

        for(int i=0; i<s.length(); i++){
            if((!st.empty()) && (s[i]==del[1]) && (st.top()==del[0]) ){
                ans+=m;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            ss+=st.top();
            st.pop();
        }
        reverse(ss.begin(),ss.end());
          
        return ss;
    }
    
    
    int maximumGain(string s, int x, int y) {
    
    int ans=0;

        if(y>x){
           s= count(s,"ba",y,ans);
           s=count(s,"ab",x,ans);
        }
        else{
            s=count(s,"ab",x,ans);
            s=count(s,"ba",y,ans);
        }
       return ans ;
    }
};