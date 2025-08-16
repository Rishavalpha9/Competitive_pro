94. Binary Tree Inorder Traversal
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

if(root ==NULL)
{
    return {};

}
vector<int> rama;
vector<int> left=inorderTraversal(root->left);
rama.insert(rama.end(),left.begin(),left.end());

rama.push_back(root->val);


vector<int> right=inorderTraversal(root->right);
rama.insert(rama.end(),right.begin(),right.end());


return rama;
        
    }
};
