/*
    name= sum of fibonacci numbers
    link- https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/
    author- Parth garg
    time complexity- o(A)
    space complexity- o(logA)
    method 1;
*/
int Solution::fibsum(int A) {
    vector<int>fib;
    fib.push_back(1);

    int temp = 2;
    while(temp<= A){
        fib.push_back(temp);
        int n= fib.size();
        temp = fib[n-1]+fib[n-2];
    }
    
    int ans= 0;
    int i= fib.size()-1;
    while(A>0){
        if(fib[i] <= A){
            ans++; 
            A-= fib[i];
        }
        i--;
    }
    
    return ans;
    
}
