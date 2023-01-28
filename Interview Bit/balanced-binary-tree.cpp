/*
    name= Balanced Binary Tree
    link- https://www.interviewbit.com/problems/balanced-binary-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

int findHeight(TreeNode* root,bool &ans){
    if(!root) return 0;
    int lh= findHeight(root->left,ans);
    int rh= findHeight(root->right,ans);
    if(abs(lh-rh)>1) ans= false;
    return 1+ max(lh,rh);
}
 
int Solution::isBalanced(TreeNode* root) {
    bool ans= true;
    int h= findHeight(root, ans);
    return ans;
}
