class Solution {
public:



    int coinChange(vector<int>& coins, int amount) {
        int n  = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));

        for(int i =0 ; i <=amount ; ++i ){
            if(i%coins[0]==0)  dp[0][i]= i/coins[0];
        }
        for(int i =1 ; i < n ; ++i){
            for(int amt =0 ; amt<=amount; ++amt){
                int nottake = dp[i-1][amt];
                int take = 1e9;
                if(amt>=coins[i]){
                    take=1+dp[i][amt-coins[i]];
                }
                dp[i][amt]=min(take,nottake);
            }
        }
        int ans = dp[n-1][amount];
          return (ans >= 1e9) ? -1 : ans;
    }
};