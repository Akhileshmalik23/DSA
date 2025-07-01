class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1; 
        
        for(int i = 0; i<word.size();i++){if(word[i+1]==word[i]){
                ans+=1;
            }

        }
        
        return ans;
    }
};