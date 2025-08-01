class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int len = dp[i + 1][j + 1]; 
                if (j == -1 || nums[i] > nums[j]) {
                    len = max(len, 1 + dp[i + 1][i + 1]);
                }
                dp[i][j + 1] = len;
            }
        }

        return dp[0][0]; 
    }


    int find(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int notTake = find(i + 1, prev, nums, dp);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + find(i + 1, i, nums, dp);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }
};
