class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0] ;
        int prev2 = 0;

        for(int i  =1 ; i< nums.size(); i++){
         int take = nums[i];
         if(i>1)
         take +=prev2;

         int notake = prev1;

         int current = max(take , notake);

         prev2 = prev1;
         prev1= current;
          

        }

        return prev1;
    }
};