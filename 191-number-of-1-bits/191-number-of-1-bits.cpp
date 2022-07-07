class Solution {
public:
    int hammingWeight(uint32_t n) {
        string mask = bitset<32>(INT_MAX).to_string();
        string nn = bitset<32>(n).to_string();
        mask[0]='1';
        // cout<<mask<<" "<<nn<<endl;
        int cnt=0;
        for(int i=0,j=0;i<32,j<32;i++,j++){
            if(mask[i]==nn[j])cnt++;
        }
        
        return cnt;
    }
    
};