class Solution {
public:
    vector<int> countBits(int n) {
        // bit + dp solution 
        vector<int>dp;
        int offset = 1;
        dp.push_back(0);
        
        for(int i=1;i<=n;i++){
            dp.push_back(0);
            if(offset*2==i){
                offset = offset*2;
            }
            dp[i]= dp[i-offset] + 1 ;
            
        }
        return dp;
        
        
        // https://youtu.be/RyBM56RIWrM
        
        
        
        // string solution 
//         vector<int>ans;
        
//         for(int i=0;i<=n;i++){
//             string nn = bitset<32>(i).to_string();
//             ans.push_back(count(nn.begin(),nn.end(),'1'));
//         }
//         return ans;
    }

};