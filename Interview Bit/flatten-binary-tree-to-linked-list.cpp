/*
    name= flatten binary tree to linked list
    link- https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

TreeNode* Solution::flatten(TreeNode* root) {
    TreeNode* res= root;
    
    while(root){
        if(root->left && root->right){
            TreeNode* t= root->left;
            while(t->right){
                t = t->right;
            }
            t->right= root->right;
        }
        if(root->left) root->right= root->left;
        root->left= NULL;
        root= root->right;
    }
    return res;
}
