/*
    name= Construct BST from Preorder
    link- https://www.interviewbit.com/problems/construct-bst-from-preorder/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

TreeNode* Solution::constructBST(vector<int> &A) {
    stack<TreeNode* >st;
    TreeNode* root= new TreeNode(A[0]);
    st.push(root);
    TreeNode* curr= root;
    for(int i=1;i<A.size();i++){
        if(A[i] < st.top()->val) {
            curr->left= new TreeNode(A[i]);
            curr= curr->left;
            st.push(curr);
        }
        else{
            TreeNode * prev;
            while(!st.empty() && st.top()->val < A[i]){
                prev= st.top();
                st.pop();
            }
            prev->right= new TreeNode(A[i]);
            curr= prev->right;
            st.push(curr);
        }
    }
    return root;
}