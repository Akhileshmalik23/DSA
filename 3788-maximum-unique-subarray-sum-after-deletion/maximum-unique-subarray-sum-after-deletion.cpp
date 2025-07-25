class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[nums.size() - 1];
        int cur = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (cur!=nums[i]){
                ans = max(ans,ans+nums[i]);
                cur=nums[i];
            }
        }
        return ans;
    }
};