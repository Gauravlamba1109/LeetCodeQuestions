class Solution {
public:
    string countAndSay(int n) {
        string dp[32];
        for(int i=0;i<32;i++)dp[i]="";
        
        dp[1]="1";
        dp[2]="11";
        dp[3]="21";
        
        for(int i=4;i<=n;i++){
            string say = dp[i-1];
            unordered_map<char,int>m;
            int j=0;
            string tosay="";
            while(j<say.size()){
                int k= j;int cnt=0;
                while(say[j]==say[k]){ cnt++;k++; }
                tosay += (to_string(cnt)+(say[j]));
                j=k;
            }
            dp[i]=tosay;
            
            //      11
            //     21
            //     1211
            //     111221

        }
        
        return dp[n];
    }
};
