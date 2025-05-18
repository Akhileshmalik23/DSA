class Solution {
public:
    int colorTheGrid(int m, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateColumn(0, m, -1, temp, ans);

        int size = ans.size();
        vector<vector<int>> adj(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (listCompare(ans[i], ans[j])) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(size, 0));
        for (int i = 0; i < size; ++i)
            dp[0][i] = 1;

        int mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k : adj[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < size; ++i)
            res = (res + dp[n - 1][i]) % mod;

        return res;
    }

private:
    void generateColumn(int index, int m, int prev, vector<int>& list, vector<vector<int>>& ans) {
        if (index == m) {
            ans.push_back(list);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (i != prev) {
                list.push_back(i);
                generateColumn(index + 1, m, i, list, ans);
                list.pop_back();
            }
        }
    }

    bool listCompare(const vector<int>& list1, const vector<int>& list2) {
        for (int i = 0; i < list1.size(); ++i) {
            if (list1[i] == list2[i])
                return false;
        }
        return true;
    }
};