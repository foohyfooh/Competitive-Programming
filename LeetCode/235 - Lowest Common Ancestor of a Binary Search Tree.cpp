/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // If root less than p and q then go right
    if(root->val < p->val && root->val < q->val)
      return lowestCommonAncestor(root->right, p, q);
    // If root greater than p and q then go right
    if(root->val > p->val && root->val > q->val)
      return lowestCommonAncestor(root->left, p, q);
    // Since both diverge this should be the ancestor
    return root;
  }
};
