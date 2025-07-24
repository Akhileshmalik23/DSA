class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int hold = -prices[0];
        int nothold = 0;

        for(int i = 1; i<n; i++){
            int p = prices[i];
            int newh  = max(hold,nothold-p);
            int newnh = max(nothold,hold+p);

            hold =  newh;
            nothold = newnh;

        }
        return nothold;
    }
};