class Solution {
public:
    string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>m;
        for(auto w: words){
            string t = "";
            for(auto e: w){
                t+=arr[e-'a'];
            }
            m.insert(t);
        }
        return m.size();
    }
};