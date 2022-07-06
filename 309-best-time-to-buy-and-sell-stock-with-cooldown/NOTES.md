int maxProfit(vector<int>& prices) {
int rest=0,hold=INT_MIN,sold=0;
for(int i=0;i<prices.size();i++){
int t=prices[i];  //curr
hold=max(hold,rest-t);
rest=rest>sold?rest:sold;
sold=hold+t;
}
return max(sold,rest);
}
​
​
​