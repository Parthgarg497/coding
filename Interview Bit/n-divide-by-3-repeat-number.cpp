/*
    name=  n/3 repeat number
    link- https://www.interviewbit.com/problems/n3-repeat-number/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

int Solution::repeatedNumber(const vector<int> &A) {
    
    int num1= -1,num2=-1,count1=0,count2=0;
    int n= A.size();
    for(int i=0;i<n;i++)
    {
        if(num1== A[i]) { count1++;}
        else if(num2== A[i]) { count2++;}
        else if(count1==0) {num1= A[i]; count1++;}
        else if(count2==0) {num2= A[i]; count2++;}
        else {count1--;count2--;}
        
    }
    count1=0;
    count2=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]== num1) count1++;
        else if(A[i]== num2) count2++;
    }
    if(count1>n/3) return num1;
    else if(count2>n/3) return num2;
    else return -1;
    
    
}
