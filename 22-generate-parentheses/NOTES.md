class Solution {
public:
int no;
vector<string> generateParenthesis(int n) {
vector<string> v;
no=n;
s(n,n,"",v);
return v;
}
void s(int o,int c,string op,vector<string>& v){
if(op.length() == 2*no){
v.push_back(op);
return;
}
if(o>0){
s(o-1,c,op+"(" ,v);
}
if(c>o){
s(o,c-1,op+")",v);
}
}
};