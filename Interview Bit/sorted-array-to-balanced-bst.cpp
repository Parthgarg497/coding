/*
    name= sorted array to balanced bst
    link- https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

TreeNode* constructBBST(const vector<int> &A, int l, int r){
    if(l>r) return NULL;
    
    int i= (l+r)/2;
    TreeNode* root= new TreeNode(A[i]);
    root->left= constructBBST(A, l,i-1);
    root->right= constructBBST(A,i+1,r);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return constructBBST(A,0,A.size()-1);
}
