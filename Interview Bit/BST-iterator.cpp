/*
    name= bst iterator
    link- https://www.interviewbit.com/problems/bst-iterator/
    author- Parth garg
    time complexity- in avg case o(1)
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
stack<TreeNode *>st;

BSTIterator::BSTIterator(TreeNode *root) {
    TreeNode *temp= root;
    while(temp){
        st.push(temp);
        temp= temp->left;
    }
    
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(st.empty()) return false;
    else return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int returnval= st.top()->val;
    TreeNode * t= st.top();
    st.pop();
    t= t->right;
    while(t){
        st.push(t);
        t= t->left;
    }
    return returnval;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
