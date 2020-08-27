/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        if (_clone.find(node) == _clone.end()) {
            _clone[node] = new Node(node->val);

            for (auto n : node->neighbors) {
                _clone[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return _clone[node];
    }

    private:
    unordered_map<Node*, Node*> _clone;
};
// @lc code=end

