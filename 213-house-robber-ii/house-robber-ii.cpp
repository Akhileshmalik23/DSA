class Solution {
public:
int f(vector<int>&nums){

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < nums.size(); i++){
            int take = nums[i];
            if(i>1)
            take += prev2;

            int notake = prev1;

            int current = max(take,notake);

            prev2=prev1;
            prev1= current;
        }

        return prev1;

}
    int rob(vector<int>& nums) {
        vector<int> temp1 ;
        vector<int> temp2;
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        for(int i  =0 ; i<nums.size();i++){
            if(i!=0)
            temp1.push_back(nums[i]);

            if(i!=nums.size()-1)
            temp2.push_back(nums[i]);
        }

        return max(f(temp1),f(temp2));
    }
};