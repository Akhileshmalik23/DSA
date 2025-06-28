class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> valueIndex;
        for (int i = 0; i < nums.size(); i++) {
            valueIndex.push_back({nums[i], i});
        }

        sort(valueIndex.rbegin(), valueIndex.rend());

        vector<pair<int, int>> topk(valueIndex.begin(), valueIndex.begin() + k);
        sort(topk.begin(), topk.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<int> result;
        for (auto& p : topk) {
            result.push_back(p.first);
        }

        return result;
    }
};
