/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // empty
        if (!root) return {};

        vector<vector<int>> ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            vector<int> temp;

            // traverse on siblings and insert its children
            for (int i = 0; i<n; i++) {
                // access front
                auto front = q.front();
                q.pop();

                // store in temp
                temp.push_back(front->val);

                // store all if children exists
                for (auto child : front->children) {
                    q.push(child);
                }
            }

            // curr level(siblings) are ready in temp
            ans.push_back(temp);
        }

        return ans;
    }
};