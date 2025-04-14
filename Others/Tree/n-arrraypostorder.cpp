

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