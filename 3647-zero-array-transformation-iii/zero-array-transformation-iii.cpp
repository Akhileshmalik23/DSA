class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> available;
        priority_queue<int, vector<int>, greater<int>> used;
        int query_index = 0;
        int used_count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            while (query_index < queries.size() &&
                   queries[query_index][0] == i) {
                available.push(queries[query_index][1]);
                ++query_index;
            }

            while (!used.empty() && used.top() < i) {
                used.pop();
            }

            nums[i] -= used.size();

            while (nums[i] > 0 && !available.empty()) {
                if (available.top() >= i) {
                    nums[i]--;
                    used.push(available.top());
                    available.pop();
                    used_count++;
                } else {
                    break;
                }
            }

            if (nums[i] > 0)
                return -1;
        }

        return queries.size() - used_count;
    }
};