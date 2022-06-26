```
class Solution {
public:
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
vector<int>v;
int n=graph.size();
helper(v,0,n,graph);
return paths;
}
vector<vector<int>> paths;
void helper(vector<int>&v,int node,int &n,vector<vector<int>>& graph){
v.push_back(node);
if(node==(n-1)){
paths.push_back(v);
return ;
}else{
for(auto ele : graph[node]){
helper(v,ele,n,graph);
v.pop_back();
}
}
}
};
​
​
class Solution {
public:
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
vector<int>v;
int n=graph.size();
helper(v,0,n,graph);
return paths;
}
vector<vector<int>>paths;
void helper(vector<int>&v,int node,int &n,vector<vector<int>>&graph){
v.push_back(node);
if(node==(n-1)){
paths.push_back(v);
return ;
}else{
for(auto ele:graph[node]){
helper(v,ele,n,graph);
v.pop_back();
}
}
}
};
```