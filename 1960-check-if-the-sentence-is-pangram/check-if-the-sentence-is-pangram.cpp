class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();
        if (n < 26)
            return false;

        vector<int> vect(26,0);
        for(int i =0 ; i< n;i++){
            vect[sentence[i]-'a']=1;
        }
        for(int i =0 ; i<26;i++){
            if(vect[i]==0)
            return false;
        }

        return true;
    }
};