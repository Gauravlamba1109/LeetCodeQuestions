class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // for the curr index 
        // if its a 1 then we add it at 32-i index in ans
        // 
        uint32_t ans = 0;
        for(int i=0;i<32;i++){
            int bit = (n>>i)&1 ;  // if the last digit 1 or 0 
            if(bit){
                ans = ans| bit<<(31-i);
            }
        }
        return ans;
        
        
        
        // accepted soltion 
//         uint32_t t=0;
//         int power =31;
        
//         while(n!=0){
//             t+= (n%2) <<power;
//             n=n>>1;
//             power -= 1;
//         }
//         return t;
    }
};