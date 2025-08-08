class Solution {
public:
    int compress(vector<char>& chars) {
        int indx =0 ; 
        for(int  i =0 ; i< chars.size();){
            char ch=chars[i];
            int cnt =0;
            while(i<chars.size()&& chars[i]==ch){
                i++;
                cnt++;
            }
            if(cnt==1){
                chars[indx++]=ch;
            }
            else{
                chars[indx++]=ch;
                string dig=to_string(cnt);
                for(char num:dig)
                chars[indx++]=num;
            }
        }
        chars.resize(indx);
        return indx;
    }
};