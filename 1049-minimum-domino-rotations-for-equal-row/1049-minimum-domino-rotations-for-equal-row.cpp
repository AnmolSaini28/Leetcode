class Solution {
public:
    int f(vector<int>& top, vector<int>& bottom,int element){
    int count = 0;
    int n = top.size();
    for(int i = 0 ;i<n ;i++){
        if(top[i]!=element and bottom[i]!=element){
            return -1;
        }
        if(top[i]!=element and bottom[i]==element){
            count++;
        }

    }
    return count;
    }
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        map<int,int>t;
        map<int,int>b;
        int n = top.size();
        for(int i = 0 ;i<n; i++){
            t[top[i]]++;
            b[bottom[i]]++;
        }
     int maxFreq = 0;
    vector<int> elementsWithMaxFreq;

    // First, find the maximum frequency
    for (auto &pair : t) {
        maxFreq = max(maxFreq, pair.second);
    }

    // Now, collect all elements with that max frequency
    for (auto &pair : t) {
        if (pair.second == maxFreq) {
            elementsWithMaxFreq.push_back(pair.first);
        }
    }
    int ans = INT_MAX;
    for(int i = 0 ; i<elementsWithMaxFreq.size();i++){
        int tTOb=f(top,bottom,elementsWithMaxFreq[i])==-1 and elementsWithMaxFreq.size()>1?INT_MAX:f(top,bottom,elementsWithMaxFreq[i]);
        int bTot=f(bottom,top,elementsWithMaxFreq[i])==-1 and elementsWithMaxFreq.size()>1?INT_MAX:f(bottom,top,elementsWithMaxFreq[i]);
       ans=min(min(ans,tTOb),bTot );

    }
    return ans==INT_MAX?-1:ans;
    }
};