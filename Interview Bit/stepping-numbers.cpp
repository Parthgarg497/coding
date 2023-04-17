/*
    name= Stepping Numbers
    link- https://www.interviewbit.com/problems/stepping-numbers/
    author- Parth garg
    time complexity- o(nlogn + n)
    space complexity- o(n)
    method 1;
*/

void dfs(int a,int b, int digits,vector<int>&res, int i,int num){
    if(i<0 || i== 10 ||digits==0)return;
    num*=10;
    num+= i;
    if(num >=a && num<=b)res.push_back(num);

    dfs(a,b,digits-1,res,i-1,num);
    dfs(a,b,digits-1,res,i+1,num);

    num/= 10;

}

vector<int> Solution::stepnum(int a, int b) {
    vector<int>res;
    int digits=0;
    int num =max(a,b);
    while(num>0){
        digits++;
        num/=10;
    }
    if(a==0) res.push_back(0);
    for(int i=1;i<=9;i++){
        dfs(a,b,digits,res, i,0);
    }
    sort(res.begin(),res.end());
    return res;
}
