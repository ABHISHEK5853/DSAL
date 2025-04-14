#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (!root) {
            return result;
        }

        stack<Node*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            Node* current = nodes.top();
            nodes.pop();

            result.insert(result.begin(), current->val);

            for (Node* child : current->children) {
                nodes.push(child);
            }
        }

        return result;
    }
};

// Example usage
int main() {
    Node* child1 = new Node(5);
    Node* child2 = new Node(6);
    vector<Node*> children = {child1, child2};
    Node* root = new Node(1, {new Node(3, children), new Node(2), new Node(4)});

    Solution sol;
    vector<int> result = sol.postorder(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete child1;
    delete child2;
    delete root->children[0]->children[0];
    delete root->children[0]->children[1];
    delete root->children[0];
    delete root->children[1];
    delete root->children[2];
    delete root;

    return 0;
}
