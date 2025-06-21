class Solution {
public:
// TC=O(N).
// SC=O(1)
    int minimumDeletions(string word, int k) {
        vector<int>mp(26,0);

        for(auto it:word){          // O(N)
            mp[it-'a']++;
        }

        int mini=INT_MAX;
        
     // Greedily checking for each char.

        for(int i=0;i<26;i++){
            
            int cnt=0;
            if(mp[i]==0)
            continue;

            for(int j=0;j<26;j++){
                if(i!=j && mp[j]!=0){
                   int diff=abs(mp[i]-mp[j]);

                   if(mp[i]>mp[j])
                   cnt+=mp[j];

// you cannot do this because tu 'i' ka liya check krr rha ha so cnt+=mp[i] means tune 'i' vala char hi delete krr diya ha to phir aaga check hi kasa krrega.

                    //  if(mp[j]>mp[i])   
                    //  cnt+=mp[i];

                   else if(diff>k)
                   {
                     cnt+=(diff-k);
                   }
                }
            }

            mini=min(mini,cnt);
        }

        return mini;
    }
};