class Solution {
public:
    int strStr(string hay, string nee) {
        size_t  it = hay.find(nee);
        return it;
    }
};