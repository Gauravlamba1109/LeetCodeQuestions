class Solution {
public:
    int getSum(int a, int b) {
        // 1001     | a (9)
        // 1011     | b (11)
        // _____________
        // 0010     | a^b (2)
        // we forgot the carries so we get them now by 
        // 0101     | a&b carries at each pos 
        // these carries are added at next pos so 
        // shift them left 
        // 01010    | a&b<<1
        // now we have 
        //  0010    | a^b 
        // 01010    | a&b<<1 ; carries at appropoate pos 
        // ______________
        // 01000    | ^    c
        // 00010    | & => 000100 | &<<1   d
        // now again untill & !=0 
        // 01010    | c^d
        // 00000    | c&d <<1 
        
        while(b!=0){
            int t = (unsigned int)(a&b)<<1;
            a = a^b;
            b = t ;
        }
        
        return a;
    }
};