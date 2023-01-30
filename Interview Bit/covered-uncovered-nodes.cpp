/*
    name= covered/ uncovered nodes
    link- https://www.interviewbit.com/problems/covered-uncovered-nodes/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/
long Solution::coveredNodes(TreeNode* root) {
    long uncove=0,cov=0; 
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){   
        int n= q.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && i< (n-1))cov+= q.front()->val;
            else if(i==0 || i== n-1) uncove+= q.front()->val;
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return abs(cov-uncove);
       
}