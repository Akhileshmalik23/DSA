class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = players.size() - 1, j = trainers.size() - 1;
        int ans = 0;
        while (i != -1 && j != -1) {
            if (players[i] <= trainers[j]) {
                ans++;
                i--;
                j--;
            } else {
                i--;
            }
        }

        return ans;
    }
};