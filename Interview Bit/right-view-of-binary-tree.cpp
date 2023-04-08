/*
    name= Right view of Binary tree
    link- https://www.interviewbit.com/problems/right-view-of-binary-tree/
    author- Parth garg
    time complexity- o(v)
    space complexity- o(v)
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
vector<int> Solution::solve(TreeNode* root) {
    vector<int>res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        
        int n= q.size();
        for(int i=0;i<n;i++){
            TreeNode* node= q.front();
            if(i== n-1) res.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            q.pop();
        }
    }
    return res;
    
}
