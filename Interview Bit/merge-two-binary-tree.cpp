/*
    name= merge two binary tree
    link- https://www.interviewbit.com/problems/merge-two-binary-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
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
TreeNode* mergeTree(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2) return NULL;
    else if(!root1 && root2){
        return root2;
    }
    else if(root1 && !root2){
        return root1;
    }
    
    root1->left= mergeTree(root1->left, root2->left);
    root1->right= mergeTree(root1->right, root2->right);
    root1->val= (root1->val + root2->val);
    
    return root1;
    
}
TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2) {
    TreeNode* res= mergeTree(root1,root2);
    return res;
}
