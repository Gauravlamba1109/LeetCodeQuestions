class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return sol(nums,target,0);
    }

    int sol(vector<int>&n,int t,int i){
        // cout<<i<<endl;
        if(i==n.size()){
            if(t==0) return 1;
            else return 0;
        }
        if(i>n.size()) return 0;

            int a = sol(n,t-n[i],i+1);
            int b = sol(n,t+n[i],i+1);
        

        return a+b;
    }
};