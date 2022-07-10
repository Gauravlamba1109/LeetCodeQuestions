class Solution {
public:
int getSum(int a, int b) {
int s,c;
while(b!=0){
s=a^b;
c=(unsigned int)(a&b)<<1;
a=s;
b=c;
}
return a;
}
};