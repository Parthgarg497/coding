/*
    name= diagonal traversal
    link- https://www.interviewbit.com/problems/diagonal-traversal/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
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
void traversal(TreeNode * root, int x,int y,map<int, vector<int>>&m ){
    if(!root) return;
    m[abs(x-y)].push_back(root->val);
    traversal(root->left, x-1,y+1,m);
    traversal(root->right, x+1,y+1,m);
}
vector<int> Solution::solve(TreeNode* root) {
    if(!root) return {};
    map<int, vector<int>>m;
    vector<int>res;
    traversal(root,0,0,m);
    for(auto mp:m ){
        for(auto value : mp.second){
            res.push_back(value );
        }
    }
    
    return res;
    
}
