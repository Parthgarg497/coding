/*
    name= reorder data in log files
    link-  https://www.interviewbit.com/problems/reorder-data-in-log-files/
    author- Parth garg
    time complexity- 
    space complexity- 
    method 1;
*/


bool comp(string a,string b)
{
        string s1,s2;
        // int i=0;
        // while(a[i]!= '-')i++;
        // s1= a.substr(i);
        // int j=0;
        // while(b[j]!= '-')j++;
        // s2= b.substr(j);
        s1= a.substr(a.find('-'));
        s2= b.substr(b.find('-'));
        if(s1 == s2) return a<b;
        else return s1<s2;          
    
}

vector<string> Solution::reorderLogs(vector<string> &A) {
    int n= A.size();
    if(A.size()==1) return A;
    int i=n-1,j=n-2;
    while(A[i].back()>= '0' && A[i].back()<= '9' )i--;
    j= i-1;
    while(j>=0)
    {
        if(A[j].back()>= '0' && A[j].back()<='9') 
        {
            swap(A[i],A[j]);
            i--;
            j--;
        }
        else j--;
    }
    sort(A.begin(),A.begin()+i+1,comp);
    return A;
}
