class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        vector<vector<int>>ans(people.size(),vector<int>(2,-1));
        
        for(auto ele : people){
            int k = ele[1];
            for(int i=0;i<ans.size();i++){
                if(ans[i][0]==-1 && k==0){
                    ans[i][0]=ele[0];
                    ans[i][1]=ele[1];
                    break;
                }
                else if(ans[i][0]==-1 || ans[i][0]>=ele[0]) 
                    k--;
            }
        }
        return ans;
    }
};
