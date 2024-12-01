class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_map<int, int> mp;

        for(auto n: arr){

            if(mp.find(n*2)!= mp.end()) return true;
            else if(n%2 == 0 && mp.find(n/2) != mp.end()) return true;

            mp[n] =1;
        }


        return false;

    }
};