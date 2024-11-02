class Solution {
public:
    bool isCircularSentence(string s) {
        
        
        stringstream ss(s);

        string temp;
        string prev="";
        int cnt=0;
        string first;
        while(getline(ss,temp,' '))
        {  
            if(prev=="")
            prev=temp;
              else
              {
                if(prev[prev.size()-1]!=temp[0])
                return false;

                prev=temp;
              }
          cnt++;
         if(cnt==1)
        first=temp;
       
        }
 if(cnt==1&&prev[prev.size()-1]!=temp[0])
                return false;
 
        return true&&(temp[temp.size()-1]==first[0]);
    }
};