/*
    name= vertical sum of binary tree
    link- https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

vector<int> Solution::verticalSum(TreeNode* root) {
    if(!root) return {};
    map<int,int>m;
    queue<pair<TreeNode*, int>> q;
    int hd= 0;
    q.push({root,hd});
    
    while(!q.empty()){
        pair<TreeNode* ,int> p= q.front(); 
        hd= p.second;
        TreeNode * temp= p.first;
        q.pop();
        m[hd]+= temp->val;
        if(temp->left) q.push({temp->left,hd-1});
        if(temp->right) q.push({temp->right,hd+1});
    }
    
    vector<int>res;
    for(auto vec: m){
        res.push_back(vec.second);
    }
    return res;
}
