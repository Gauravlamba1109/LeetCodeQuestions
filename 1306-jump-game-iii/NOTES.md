```
unordered_set<int> vis;
bool canReach(vector<int>& arr, int st) {
if (st >= 0 && st < arr.size() && vis.insert(st).second) {
return arr[st] == 0 ||
canReach(arr, st + arr[st]) || canReach(arr, st - arr[st]);
}
return false;
}
​
class Solution {
public boolean canReach(int[] arr, int start) {
if(start<0 || start>=arr.length || arr[start]>=arr.length || arr[start]<0)return false;
arr[start]=-arr[start];
return arr[start]==0 || canReach(arr,start-arr[start]) || canReach(arr,start+arr[start]);
}
}
​
class Solution {
public:
bool canReach(vector<int>& arr, int start) {
if(start>=arr.size()||start<0||arr[start]>=arr.size()||arr[start]<0 )
return false;
if(arr[start]==0)