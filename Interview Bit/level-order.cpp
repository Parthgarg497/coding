/*
    name= level order
    link- https://www.interviewbit.com/problems/level-order/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*>q;
    q.push(A);
    vector<vector<int>>res;
    while(!q.empty()){
        int n= q.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            TreeNode* node= q.front();
            temp[i]= node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            q.pop();
        }
        res.push_back(temp);
    }
    return res;
}