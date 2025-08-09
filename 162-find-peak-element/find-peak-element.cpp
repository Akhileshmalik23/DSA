class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans;
        if (nums.size() == 1)
            return 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 && nums[i] > nums[i + 1])
                return i;
            else if (i == nums.size() - 1 && nums[i - 1] < nums[i]) {
                return i;
            }
            else if(i>=1&&i<=nums.size()-2 &&nums[i]>nums[i+1]&&nums[i-1]<nums[i]) {
                return i;
            }

        }
        return 0;
    }
};