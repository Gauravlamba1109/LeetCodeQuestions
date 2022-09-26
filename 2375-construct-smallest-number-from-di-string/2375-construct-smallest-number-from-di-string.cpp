class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        for(int i=0;i<=pattern.size();i++){
            ans+=(i+'1');
        }
        
        int i;
        for(i=0;i<pattern.size();i++){
            if(pattern[i]=='D'){
                // reverse increment
                int start = i;
                int end = start;
                while(pattern[end]=='D')end++;
                reverse(ans.begin()+start,ans.begin()+end+1);
                i=end;
            }
        }
        return ans;
        
        
//        vector<int> ans;
//         ans.push_back(1);
//         int curr = 1;
        
//         for(int i=0;i<pattern.size();i++){
//             if(pattern[i]=='I'){
//                 int t = curr+1;
//                 while(find(ans.begin(),ans.end(),t)!=ans.end())
//                     t++;
//                 ans.push_back(t);
//                 curr = t;
//             }
            
//             else{
//                 int t = curr-1;
//                 if(find(ans.begin(),ans.end(),t)==ans.end() && t>0){
//                     ans.push_back(t);
//                     curr = t;
//                 }
//                 else{
//                     ans.push_back(t);
//                     int n = ans.size();
//                     int ind = n-2;
//                     while(ind>=0 && ans[ind]>ans[ind+1] ){
//                         ans[ind+1]++;
//                         ind--;
//                     }
//                     ans[ind+1]++;
//                     curr = ans.back();
//                 }
//             }
//         }
        
//         string a="";
//         for(auto e : ans)a+=to_string(e);
//         return a;
            
    }
};
