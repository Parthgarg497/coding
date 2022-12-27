/*
    name= nearest smaller element
    link- https://www.interviewbit.com/problems/nearest-smaller-element/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/


vector<int> Solution::prevSmaller(vector<int> &a) {
    stack<int> st;
    int n= a.size();
    vector<int>result(n);
    
    result[0]= -1;
    st.push(a[0]);
    
    for(int i=1;i<n;i++)
    {
        if(a[i]<= st.top() )
        {
            while(!st.empty() && a[i] <=st.top())
            {
                st.pop();
            }
            if(st.empty()) result[i]= -1;
            else result[i]= st.top(); 
        }
        else 
        {
            result[i]= st.top();
        }
        
        st.push(a[i]);
    }
    return result;
    
}
