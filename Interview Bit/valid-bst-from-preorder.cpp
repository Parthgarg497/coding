/*
    name= Valid BST from Preorder
    link- https://www.interviewbit.com/problems/valid-bst-from-preorder/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(height of tree)
    method 1;
*/


int Solution::solve(vector<int> &arr) {
    if(arr.size()==1) return 1;
    stack<int>st;
    st.push(arr[0]);
    int prev=-1;
    for(int i=1;i<arr.size();i++){
        if(st.empty() || arr[i] < st.top()){
            st.push(arr[i]);
        } 
        else{
            while(!st.empty() ){
                if(st.top() <= prev) return 0;
                else if(st.top()<arr[i]){
                    prev= st.top();
                    st.pop();
                }
                else break;
            }
            st.push(arr[i]);
        }
    }
    while(!st.empty()){
        if(st.top() <= prev) return 0;
        else{
            prev= st.top();
            st.pop();
        }
    }
    return 1;
}
