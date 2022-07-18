class Solution {
public:
    set<vector<int>>ans;
     vector<vector<int> > subsetsWithDup(vector<int> &S) {
         vector<int>v;
         helper(S,v,0);
         vector<vector<int>>t(ans.begin(),ans.end());
         return t;
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
             if(i>=s.size()){
                 vector<int>t=v;
                 sort(t.begin(),t.end());
                 ans.insert(t);
                 return ;
             }
             v.push_back(s[i]);
             helper(s,v,i+1);
             v.pop_back();
             helper(s,v,i+1);
         }
};