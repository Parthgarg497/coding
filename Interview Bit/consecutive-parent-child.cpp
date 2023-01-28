/*
    name= Consecutive Parent - Child
    link-  https://www.interviewbit.com/problems/consecutive-parent-child/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

int Solution::consecutiveNodes(TreeNode* root) {
    if(!root) return 0;
    
    int ans= consecutiveNodes(root->left) +consecutiveNodes(root->right);
    if(root->left && abs(root->left->val - root->val) ==1){
        ans++;
    }
    if(root->right && abs(root->right->val - root->val) ==1){
        ans++;
    }
    return ans;
}
