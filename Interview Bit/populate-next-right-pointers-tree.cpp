/*
    name= populate next right pointers tree
    link- https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(width of tree)
    method 1;
*/

void Solution::connect(TreeLinkNode* root) {
    if(!root) return ;
    
    queue<TreeLinkNode* >q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        
        for(int i=0;i<n;i++){
            TreeLinkNode* curr= q.front();
            q.pop();
            if(i== n-1){
                curr->next= NULL;
            }
            else curr->next= q.front();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    
    
}
