```
class Solution {
public:
int longestConsecutive(vector<int>& nums) {
if(nums.size()<2) return nums.size();
int counti=0;
set<int>s1;
for(int i=0 ; i<nums.size() ;i++){
s1.insert(nums[i]);
}
for(int i=0 ; i<s1.size() ;i++){
int curr= s1[i];
int currcount=1;
while(s1.find(curr+1)!=s1.end()){
curr=curr+1;
currcount+=1;
}
counti=max(currcount,counti);
}
return counti;
}
};
​
​
class Solution {
public:
int longestConsecutive(vector<int>& v) {
map<int,int>m;
priority_queue<int>s;
int ans = 0;
for(auto e:v){
if(m.find(e)!=m.end())continue;
s.push(e);
m[e]++;
}
​
while(!s.empty()){
int count = 1;
int start = s.top(); s.pop();
// cout<<"start ->"<<start<<endl;
while(!s.empty() && s.top()== start-1 ){
count++;
start--;
s.pop();
// cout<<start<<" "<<count<<endl;
}
ans = max(ans,count);
}
// cout<<endl;
return ans;
}
};
```