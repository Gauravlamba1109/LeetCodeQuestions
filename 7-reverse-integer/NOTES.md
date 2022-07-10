```
class Solution {
public:
int reverse(int x) {
if(x==0){
return x;
}
string ans="";
int neg=1;
if(x<0){
neg=-1;
x=abs(x);
}
while(x>0){
int toappend= x%10;
ans+=to_string(toappend);
x=x/10;
}
int ne;
stringstream a(ans);
a>>ne;
if(ne>=INT_MAX ||ne<=INT_MIN){
return 0;
}
return ne*neg;
}
};
```