/*
    name= Last Node in a Complete Binary Tree
    link- https://www.interviewbit.com/problems/last-node-in-a-complete-binary-tree/
    author- Parth garg
    time complexity- o(logn * logn)
    space complexity-  o(1)
    method 1;
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findHeight(TreeNode* root){
    if(!root) return 0;
    TreeNode *temp = root;
    int height= 0;
    while(temp){
        temp= temp->left;
        height++;
    }
    return height;
}
int Solution::lastNode(TreeNode* root) {
    
    while(root){
        int l= findHeight(root->left);
        int r= findHeight(root->right);
        if(l==0 && r==0) return root->val;
        else if( l > r){
            root= root->left;
        } 
        else{
            root= root->right;
        }
    }
    return root->val;
    
}
