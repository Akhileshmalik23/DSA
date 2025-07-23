class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x >= y)
            return find(s, 'a', 'b', x, y);
        else
            return find(s, 'b', 'a', y, x);
    }

    int find(string s, char first, char sec, int high, int low) {
        string intermediate = "";
        stack<char> st;
        int score = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (!st.empty() && st.top() == first && s[i] == sec) {
                st.pop();
                score += high;
            } else {
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            intermediate += st.top();
            st.pop();
        }

        for (int i = intermediate.length() - 1; i >= 0; i--) {
            if (!st.empty() && st.top() == sec && intermediate[i] == first) {
                st.pop();
                score += low;
            } else {
                st.push(intermediate[i]);
            }
        }

        return score;
    }
};
