class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        
        for(int i=0;i<=n;i++){
            string nn = bitset<32>(i).to_string();
            ans.push_back(count(nn.begin(),nn.end(),'1'));
        }
        return ans;
    }

};