#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }

        stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* current = nodes.top();
            nodes.pop();

            result.push_back(current->val);

            if (current->right) {
                nodes.push(current->right);
            }

            if (current->left) {
                nodes.push(current->left);
            }
        }

        return result;
    }
};

// Example usage
int main() {
    // Create a simple binary tree:
    //     1
    //      \
    //       2
    //      /
    //     3
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node3, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, node2);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup
    delete node3;
    delete node2;
    delete root;

    return 0;
}
