class Solution {
public:
    vector<int> countBits(int n) {
        // bit + dp solution 
        vector<int>dp;
        int offset = 1; int pow = 2;
        dp.push_back(0);
        for(int i=1;i<=n;i++){
            dp.push_back(0);
            int cnt=0;
            if(offset*pow==i){
                dp[i]=1;
                offset = offset*pow;
            }else{
                dp[i]=dp[i-offset]+1;
            }
        }
        return dp;
        // string solution 
//         vector<int>ans;
        
//         for(int i=0;i<=n;i++){
//             string nn = bitset<32>(i).to_string();
//             ans.push_back(count(nn.begin(),nn.end(),'1'));
//         }
//         return ans;
    }

};