class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> hash(n);
       int maxLen = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

       vector<int> result;
        result.push_back(nums[lastIndex]);
         while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            result.push_back(nums[lastIndex]);
        }
        return result ;
    }
};