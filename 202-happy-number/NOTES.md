n=n/10;
}
if(seen.find(t)!=seen.end())return 0;
return isHappy(t);
}
}
};
​
​
class Solution {
public:
bool isHappy(int n) {
set<int>s;
while(n!=1 && s.find(n)==s.end()){
s.insert(n);
int ts=0;
while( n> 0 ){
int d=n%10;
n/=10;
ts+= d*d ;
}
// cout<<ts<<" ";
n=ts;
}
return n==1;
}
};
```