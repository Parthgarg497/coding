/*
    name= clone graph
    link- https://www.interviewbit.com/problems/clone-graph/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n*n) worst case for storing graph
    method 1;
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
void dfs(UndirectedGraphNode *node , map<UndirectedGraphNode*, int>&vis, map<int,UndirectedGraphNode*>&mp){
    if(node == NULL) return;
    vis[node] = 1;
    UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
    mp[node->label] = newNode;
    for(auto child : node->neighbors){
        if(vis[child] == 0){
            dfs(child, vis,mp);
        }
    }
}

void dfs2(UndirectedGraphNode *node,map<UndirectedGraphNode*, int>&vis,map<int,UndirectedGraphNode*>&mp ){
    if(node == NULL) return;
    vis[node] = 2;
    vector<UndirectedGraphNode*>clonedNeighbor;
    UndirectedGraphNode* currNode = mp[node->label];
    for(auto child : node->neighbors){
        if(vis[child] != 2){
            dfs2(child,vis,mp);
        }
        clonedNeighbor.push_back(mp[child->label]);
    }
    currNode->neighbors= clonedNeighbor;
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL) return NULL;
    map<int,UndirectedGraphNode*>mp;
    map<UndirectedGraphNode*, int>vis;
    dfs(node, vis,mp);
    dfs2(node, vis,mp);
    UndirectedGraphNode* res = mp[node->label];
    
    return res;
    
}
