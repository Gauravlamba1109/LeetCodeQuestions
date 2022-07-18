class Solution {
public:
    vector<vector<int>>ans;
     vector<vector<int> > subsetsWithDup(vector<int> &S) {
         vector<int>v;
         sort(S.begin(),S.end());
         helper(S,v,0);
         return ans;
         
         
//         vector<vector<int> > totalset = {{}};
//         sort(S.begin(),S.end());
         
//         for(int i=0; i<S.size();){
//             int count = 0; // num of elements are the same
//             while(count + i<S.size() && S[count+i]==S[i])  count++;
//             int previousN = totalset.size();
//             for(int k=0; k<previousN; k++){
//                 vector<int> instance = totalset[k];
//                 for(int j=0; j<count; j++){
//                     instance.push_back(S[i]);
//                     totalset.push_back(instance);
//                 }
//             }
//             i += count;
//         }
//         return totalset;
        }
         
         void helper(vector<int>&s,vector<int>&v,int i){
             if(i==s.size()){
                 vector<int>t=v;
                 ans.push_back(t);
                 return ;
             }
             // all subsets that include s[i];
             v.push_back(s[i]);
             helper(s,v,i+1);
             v.pop_back();
             
             // that doesnt include s[i];
             while(i+1<s.size() && s[i+1]==s[i])i++;
             helper(s,v,i+1);
         }
};