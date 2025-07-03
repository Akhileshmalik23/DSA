class Solution {
public:

    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = geetnumber(n);
        }
        return n == 1;
    }

    int geetnumber(int n){
        int ans =0;
        while(n>0)
        {
            int digit=n%10;
            ans+= digit*digit;
            n=n/10;
        }
        return ans;
    }
}
;