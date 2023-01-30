/*
Keep a queue of the encountered nodes and their level
Until queue is empty
  Pop the top element
  Add its value to the list of values at the correct level
  Add the element's children to the queue
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr) return {};
    vector<vector<int>> vals;
    queue<pair<TreeNode*, int>> nodes;
    nodes.push(make_pair(root, 0));
    while(!nodes.empty()){
      pair<TreeNode*, int> curr = nodes.front(); nodes.pop();
      if(vals.size() == curr.second) vals.push_back({});
      vals[curr.second].push_back(curr.first->val);
      if(curr.first->left != nullptr) nodes.push(make_pair(curr.first->left, curr.second + 1));
      if(curr.first->right != nullptr) nodes.push(make_pair(curr.first->right, curr.second + 1));
    }
    return vals;
  }
};
