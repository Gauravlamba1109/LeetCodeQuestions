class Solution {
public:
    vector<vector<int>> dp;
	int solve(vector<int> &prices,int n,int buy,int pos,int k){
		if(pos==n || buy==2*k || k==0) return 0;  // buy==2*k so that transaction occurs only k times

		if(dp[pos][buy]!=-1) return dp[pos][buy];

		int ans=0;
		if(buy%2==0){ // buy%2 == 1 means we have to sell , 
 			ans=max(-prices[pos]+solve(prices,n,buy+1,pos+1,k),solve(prices,n,buy,pos+1,k));
		}
		else{
			ans=max(prices[pos]+solve(prices,n,buy+1,pos+1,k),solve(prices,n,buy,pos+1,k));
		}
		
		return dp[pos][buy] = ans;
	}
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
		dp.assign(n,vector<int>(2*k,-1));
		return solve(prices,n,0,0,k);
    }
};