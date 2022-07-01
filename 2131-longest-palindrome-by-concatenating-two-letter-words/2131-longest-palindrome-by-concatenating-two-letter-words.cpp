class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        // if palan get the largest length 
        // if reverse pre get both 
        
        int ans=0,si=0,mid=0;
        unordered_map<string,int>words;
        for(auto ele : w)words[ele]++;
        
        set<string>vis;
        for(auto ele : w){
            if(ele[0]==ele[1] && vis.find(ele)==vis.end()){
                int c = words[ele];
                int n = c-c%2;
                if(c!=n)mid=2;
                si += (2*(n));
                vis.insert(ele);
                continue;
            }else{
                if(ele[1]==ele[0])continue;
                string rev = ele;
                reverse(rev.begin(),rev.end());
                if(words.find(rev)!=words.end() && words[ele]>0 && words[rev]>0){
                    words[ele]--; 
                    words[rev]--;
                    // cout<<cnt<<" "<<rev<<endl;
                    ans+=(4);
                }
            }
        }
        
        return ans+si+mid;
    }
};
// 10
// ,"dd","aa","cc","bb",,,]
