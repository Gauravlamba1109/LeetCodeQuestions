class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // sort from tall to short 
        // and place ele using k value 
        sort(people.begin(),people.end(),[](const vector<int>&a,const vector<int>&b){
            return( a[0]>b[0]  || (a[0]==b[0] && a[1]<b[1])) ;
        });
        for(auto ele : people)cout<<ele[0]<<","<<ele[1]<<" ";
        
        vector<vector<int>>ans;
        for(auto ele : people){
            auto it = ans.begin();
            ans.insert(it+ele[1],ele);
        }
        
        return ans;
        
        
        // sort by height 
        // then place each on its appropiate position 
        // use the k value ; if the curr place is not taken or value is greater dec k ; 
        // ele if k==0 place it 
//         sort(people.begin(),people.end(),[](const vector<int>&a,const vector<int>&b){
//             return a[0]<b[0];
//         });
//         vector<vector<int>>ans(people.size(),vector<int>(2,-1));
        
//         for(auto ele : people){
//             int k = ele[1];
//             for(int i=0;i<ans.size();i++){
//                 if(ans[i][0]==-1 && k==0){
//                     ans[i][0]=ele[0];
//                     ans[i][1]=ele[1];
//                     break;
//                 }
//                 else if(ans[i][0]==-1 || ans[i][0]>=ele[0]) 
//                     k--;
//             }
//         }
//         return ans;
    }
};
