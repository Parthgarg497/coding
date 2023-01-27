/*
    name= remove half nodes
    link- https://www.interviewbit.com/problems/remove-half-nodes/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

TreeNode* Solution::solve(TreeNode* root) {
    if(!root) return NULL;
    
    root->left= solve(root->left);
    root->right= solve(root->right);
    
    if(root->left == NULL && root->right != NULL){
        return root->right;
    }
    else if(root->left != NULL && root->right == NULL){
        return root->left;
    }
    return root;
    
}
