/*
    name= Recover Binary Search Tree
    link-  https://www.interviewbit.com/problems/recover-binary-search-tree/
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
vector<int> Solution::recoverTree(TreeNode* root) {
    vector<int>res;
    stack<TreeNode*>st;
    TreeNode *prev=NULL,*curr= root;
    
    while(curr|| !st.empty()){
        
        while(curr){
            st.push(curr);
            curr= curr->left;
        }
        curr= st.top();
        st.pop();
        if(prev && prev->val > curr->val){
            res.push_back(prev->val);
            res.push_back(curr->val);
        }
        prev= curr;
        curr= curr->right;
    }
    if(res.size()==3){
        swap(res[2],res[1]);
        res.pop_back();
    }
    else if(res.size()==4){
        swap(res[3],res[1]);
        res.pop_back();
        res.pop_back();
    }
    swap(res[0],res[1]);
    return res;
}
