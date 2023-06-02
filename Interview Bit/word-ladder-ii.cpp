/*
    name= word ladder ii
    link- https://www.interviewbit.com/problems/word-ladder-ii/
    author- Parth garg
    time complexity- 
    space complexity- 
    method 1;
*/

const int INF = 1e9;
vector<vector<string> > Bfs(string &src ,string &dest, vector<string> &C){
    unordered_set<string>st;
    for(int i=0;i<C.size();i++){
        if(C[i].length() == src.length())
            st.insert(C[i]);
    }

    int n= src.length();
    vector<string>usedOnLevel;
    vector<vector<string> >res;
    queue<vector<string>>q;
    q.push({src});
    // usedOnLevel.push_back(src);
    int level=0;
    bool flag = false;
    while(!q.empty()){
        level++;
        int sz = q.size(); 
        for(int z= 0;z<sz;z++){
            vector<string>top = q.front();
            q.pop();

            string s = top.back();
            usedOnLevel.push_back(s);
            int d = 0; 
            for(int i=0;i<n;i++){
                if(dest[i] != s[i])d++;
            }
            if(d == 1){
                top.push_back(dest);
                res.push_back(top);
                flag = true;
            }
            
            for (auto stng : st){
                int count = 0;
                for(int j= 0;j<n;j++){
                    if(s[j] != stng[j]) count++;
                }
                if(count == 1 ){
                    // cout<<level<<" "<< stng<<endl;
                    top.push_back(stng);
                    q.push(top);
                    top.pop_back();
                }
            }
            top.clear();
        }
        for(auto stng : usedOnLevel){
            st.erase(stng);
        }
        usedOnLevel.clear();
        if(flag)break;
    }
    return res;
}


vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    if(start == end){
        vector<vector<string>>res;
        vector<string>temp;
        temp.push_back(start);
        res.push_back(temp);
        return res;
    }
    
    vector<vector<string>>res= Bfs(start,end,dict);
    return res;
}
