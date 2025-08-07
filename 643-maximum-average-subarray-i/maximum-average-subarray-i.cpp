class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double temp =0  , maxsum =0 ; 

        for(int i =0 ; i<k; i++)
        temp +=nums[i];

        maxsum = temp;

        for(int i = k ; i<nums.size(); i++){
            temp +=nums[i]-nums[i-k];

            maxsum = max(maxsum , temp);
        }
        return maxsum/k;
    }
};