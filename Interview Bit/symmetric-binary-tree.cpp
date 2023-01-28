/*
    name= symmetric binary tree
    link- https://www.interviewbit.com/problems/symmetric-binary-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

bool check(TreeNode* l, TreeNode* r){
    if((l && !r) || (!l && r)) return false;
    else if(!l && !r) return true;
    if(l->val != r->val) return false;
    else{
        return check(l->left, r->right) & check(l->right, r->left);
    }
} 

int Solution::isSymmetric(TreeNode* root) {
    if(!root) return 1;
    TreeNode* l= root->left; 
    TreeNode* r= root->right;
    return check(l,r);
}
