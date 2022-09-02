class Solution {
public:
int minSetSize(vector<int>& arr) {
int sum=0;
unordered_map<int,int>m;
for(auto ele : arr){
m[ele]++;
}
vector<int>a;
for(auto ele : m){
a.push_back(ele.second);
sum+=ele.second;
}
sort(a.begin(),a.end(), greater<int>());
int des= sum - (sum/2), cnt=0 , i=0;
while(i<a.size() && des>0){
cnt++;
des-=a[i];
i++;
}
return cnt;
}
};