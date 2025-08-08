class Solution {
public:
    string f(string s) {
        int l = 0, i = 0;
        string ans = "";
        int cnt = 0;
        while (i < s.size()) {
            if (s[i] != s[l]) {
                ans += to_string(cnt);
                ans += s[l];
                l = i;
                cnt = 0;
            }
            cnt++;
            i++;
        }
        if(cnt!=0){
            ans += to_string(cnt);
                ans += s[l];
        }
        return ans;
    }
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string an = countAndSay(n-1);
string ans = f(an);
         return ans;
    }
};