/*
    name= burn a tree
    link- https://www.interviewbit.com/problems/burn-a-tree/
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
TreeNode* start= NULL;
void findTheParent(unordered_map<TreeNode*, TreeNode*>&mp, TreeNode* root,int target){
    if(!root) return ;
    
    if(root->val ==  target) start= root;
    
    if(root->left) mp[root->left] = root;
    if(root->right) mp[root->right]= root;
    
    findTheParent(mp,root->left, target);
    findTheParent(mp,root->right, target);
    
} 

int Solution::solve(TreeNode* root, int target) {
    unordered_map<TreeNode*, TreeNode*> mp;
    vector<int>vis(100001,0);
    mp[root]= NULL;
    findTheParent(mp, root, target);
    
    queue<TreeNode*> q;
    q.push(start);
    
    int time=0;
    while(!q.empty()){
        int n= q.size();
        time++;
        for(int i=0;i<n;i++){
            TreeNode* curr_node= q.front();
            vis[curr_node->val]= 1;
            q.pop();
            
            //check for left,right, parent
            if(curr_node->left && vis[curr_node->left->val] ==0) q.push(curr_node->left);
            if(curr_node->right && vis[curr_node->right->val] ==0) q.push(curr_node->right);            
            if(mp[curr_node] && vis[(mp[curr_node])->val] == 0) q.push(mp[curr_node]);
        }
    }
    return time-1;
    
}
