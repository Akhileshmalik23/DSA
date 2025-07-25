class Solution {
public:
int sol(int m , int n  , vector<vector<int>> &dp){
    if(m==0&& n ==0){
        return 1;
    }
    if(n<0||m<0)return 0;

    if(dp[m][n]!=-1) return dp[m][n];

    int up = sol(m-1,n,dp);
    int down = sol(m,n-1,dp);

   return dp[m][n]= up+down;
    
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return sol(m-1,n-1,dp);
    }
};