class Solution {
public:
bool isAnagram(string s, string t) {
if(s.size()!=t.size()){
return false;
}
int arr[27]={0};
for(int i = 0 ; i <s.size() ; i++){
arr[s[i]-'a']++;
arr[t[i]-'a']--;
}
for(auto& c : arr){
if(c!=0){
return false;
}
}
return true;
}
};
​
class Solution {
public:
bool isAnagram(string s, string t) {
sort(s.begin(),s.end());
sort(t.begin(),t.end());
return t==s;
}
};
​
​
​
bool isAnagram(string s, string t) {
// map<int,int>m;
// if(s.size()!=t.size()) return false;
// for(int i=0;i<s.size();i++){
//     m[s[i]]++;
//     m[t[i]]--;
// }
// for(auto ele:m)if(ele.second)return 0;
// return 1;
}
​
​