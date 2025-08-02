class Solution {
public:
int f(vector<int>& nums, int mid){
    int cnt = 1;
    int temp = 0 ;
    for(int i =0 ; i<nums.size();i++){
        if(temp+nums[i]<=mid){
            temp+=nums[i];
        }
        else{
            temp=nums[i];
            cnt++;
        }
    }
    return cnt;
}
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        int ans;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int split = f(nums, mid);

            if (split <= k) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};