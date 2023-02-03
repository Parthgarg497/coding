/*
    name= root to leaf paths with sum
    link- https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

void findPath(TreeNode* root, vector<int>&path, int target,vector<vector<int>>&res){
    if(!root) return ;
    target -= (root->val);
    path.push_back(root->val);
    if(root->left== NULL && root->right== NULL && target==0){
        res.push_back(path);
    }
    
    findPath(root->left, path,target,res);
    findPath(root->right,path,target,res);
    path.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int target) {
    if(!root) return {};
    vector<int>path;
    vector<vector<int>>res;
    findPath(root, path,target,res);
    return res;
}
