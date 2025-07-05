class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map;
        int ans = -1;

        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }

        for (auto& it : map) {
            if (it.first == it.second) {
                ans = max(ans, it.first); 
            }
        }

        return ans;
    }
};
