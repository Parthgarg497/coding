/*
    name= Convert Sorted List to Binary Search Tree
    link- https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* buildTree(vector<int>&vals, int start, int end){
    if(start > end) return NULL;
    int mid = (start+end)/2;
    TreeNode* newNode = new TreeNode(vals[mid]);
    newNode->left = buildTree(vals,start,mid-1);
    newNode->right = buildTree(vals,mid+1,end);
    return newNode; 
}
TreeNode* Solution::sortedListToBST(ListNode* head) {
    vector<int>vals;
    ListNode* temp = head;
    while(temp){
        vals.push_back(temp->val);
        temp= temp->next;
    }
    int n= vals.size()-1;
    TreeNode* root= buildTree(vals,0,n);
    return root;
    
}
