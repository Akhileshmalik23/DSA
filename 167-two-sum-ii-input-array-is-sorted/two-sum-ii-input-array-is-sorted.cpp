class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l =1 , r =numbers.size();

        while(l<r){
            if(target==numbers[l-1]+numbers[r-1]){
                return {l,r};
            }
            else if(target<numbers[l-1]+numbers[r-1]){
                r--;
            }
            else{
                l++;
            }
        }
        return {l,r};
    }
};