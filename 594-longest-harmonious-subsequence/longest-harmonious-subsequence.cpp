class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map <int, int> map;

        for(int i =0 ; i < nums.size(); i++){
            map[nums[i]]++;
        }
int ans=0;
        for(auto it = map.begin();it!=map.end();it++){
int key = it->first;
int val = it->second;
if(map.find(key+1)!=map.end()){
    ans = max(ans,val+map[key+1]);
}
        }
        return ans;
    }
};