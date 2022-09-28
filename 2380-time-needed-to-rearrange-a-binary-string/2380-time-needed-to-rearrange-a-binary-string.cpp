class Solution {
public:
    
    int secondsToRemoveOccurrences(string s) {
        // faster method 
        // count zeros 
        // then if its a 1 increment second 
        
        int cnt = 0;
        int sec = 0;
        for(int i=0;i<s.size();i++){
            cnt += s[i]=='0' ;
            if(s[i]=='1' && cnt) {
                sec = max(sec+1,cnt);
            }
        }
        
        return sec;
        
        
        // brute force 
//         int cnt = 0;
        
//         while(present(s)){
//             vector<int>pairs;
//             for(int i=0;i<s.size()-1;i++){
//                 if(s[i]=='0' && s[i+1]=='1'){
//                     pairs.push_back(i);
//                 }
//             }

//             for(int i : pairs){
//                 s[i]='1'; s[i+1]='0';
//             }
//             cnt++;
//         }
        
//         return cnt;
    }
    
    
    bool present(string s){
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0' && s[i+1]=='1') return true;
        } 
        return false;
    }
};