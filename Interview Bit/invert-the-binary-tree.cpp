/*
    name= Invert the Binary Tree
    link- https://www.interviewbit.com/problems/invert-the-binary-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/
TreeNode* Solution::invertTree(TreeNode* root) {
    if(!root) return NULL;
    
    TreeNode* left= invertTree(root->left);
    TreeNode* right= invertTree(root->right);
    
    root->left= right;
    root->right= left;
    
    return root;
}
