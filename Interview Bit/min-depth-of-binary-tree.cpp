/*
    name= min depth of binary tree
    link-  https://www.interviewbit.com/problems/min-depth-of-binary-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

void findMinDepth(TreeNode* root, int num,int &ans){
    if(!root) return ;
    num++;
    if(!root->left && !root->right) {
        ans= min(ans, num);
    }
    
    findMinDepth(root->left, num, ans);
    findMinDepth(root->right,num,ans);
    
}

int Solution::minDepth(TreeNode* root) {
    int ans=INT_MAX;
    findMinDepth(root, 0,ans);
    return ans; 
}
