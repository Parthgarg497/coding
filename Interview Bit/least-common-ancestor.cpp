/*
    name= Least Common Ancestor
    link-  https://www.interviewbit.com/problems/least-common-ancestor/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

int a1=-1,a2=-1;
TreeNode* findLCA(TreeNode* root, int n1,int n2){
    if(!root) return NULL;
    
    if(root->val == n1)a1= root->val;
    if(root->val == n2)a2= root->val;
    
    TreeNode* l = findLCA(root->left, n1,n2);
    TreeNode* r = findLCA(root->right,n1,n2);
    if(root->val == n1 || root->val == n2) return root;
    if(l && r) return root;
    
    if(l) return l;
    if(r) return r;
    return NULL;
}
int Solution::lca(TreeNode* root, int n1, int n2) {
    a1= -1; 
    a2= -1;
    TreeNode* lcaNode= findLCA(root, n1,n2);
    if(a1== -1 || a2==-1 || lcaNode == NULL) return -1;
    else return lcaNode->val;
    
}
