class Solution {
public:
    string makeGood(string s) {
        string stack = "";
        for (int i = 0; i < s.length(); ++i) {
            if (!stack.empty() && abs(stack.back() - s[i]) == 32) {
                stack.pop_back();
            } else {
                stack.push_back(s[i]);
            }
        }
        return stack;
    }
};
