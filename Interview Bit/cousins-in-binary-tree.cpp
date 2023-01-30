/*
    name= Cousins in Binary Tree
    link- https://www.interviewbit.com/problems/cousins-in-binary-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(maximum width of tree)
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
vector<int> Solution::solve(TreeNode* root, int B) {
    if(!root || root->val== B) return {};
    queue<TreeNode*>q;
    vector<int>res;
    q.push(root);
    bool found= false;
    while(!q.empty()){
        int n= q.size();
        for(int i=0; i<n;i++){
            TreeNode* curr= q.front();
            if((curr->left && curr->left->val == B) || (curr->right && curr->right->val == B)){
                found= true;
            }
            else{
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            q.pop();
        }
        if(found)break; 
    }
    int n= q.size();
    for(int i=0;i<n;i++){
        res.push_back(q.front()->val);
        q.pop();
    }
    return res;
    
}
