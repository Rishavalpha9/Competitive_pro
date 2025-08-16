145. Binary Tree Postorder Traversal
----------------------------------------------------------------------------------------------------------------------------------------------------------------
  class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

if(root==NULL)
{
    return {};
}
vector<int> sita;
vector<int> left=postorderTraversal(root->left);

sita.insert(sita.end(),left.begin(),left.end());
vector<int> right=postorderTraversal(root->right);

sita.insert(sita.end(),right.begin(),right.end());

sita.push_back(root->val);

return sita;
        
    }
};
