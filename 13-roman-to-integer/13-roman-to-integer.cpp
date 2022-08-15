class Solution {
public:
    int romanToInt(string s) {
        int sum[s.size()];
        int ans=0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='I'){
                sum[i]=1;
            }else if(s[i]=='V'){
                sum[i]=5;
            }else if(s[i]=='X'){
                sum[i]=10;
            }else if(s[i]=='L'){
                sum[i]=50;
            }else if(s[i]=='C'){
                sum[i]=100;
            }else if(s[i]=='D'){
                sum[i]=500;
            }else if(s[i]=='M'){
                sum[i]=1000;
            }
        }
        for(int i = 0;i <s.size() ; i++){
            if(i+1<s.size()){
                if(sum[i]>=sum[i+1]){
                    ans+=sum[i];
                }else if(sum[i]<sum[i+1]){
                    ans-=sum[i];
                }
            }else{
                ans+=sum[i];
            }
        }
        return ans;
    }
};