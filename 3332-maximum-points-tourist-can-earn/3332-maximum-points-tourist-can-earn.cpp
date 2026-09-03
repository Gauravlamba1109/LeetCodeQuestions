class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        for(int i=0;i<n;i++){
            ans = max(maxscore(stayScore,travelScore,i,k-1,n,dp),ans);
        }
        return ans;
    }

    int maxscore(vector<vector<int>>& stayScore, vector<vector<int>>& travelScore,int curr, int day,int n,vector<vector<int>>&dp){
        if(day<=-1) return 0;
        if(dp[curr][day]!=-1) return dp[curr][day];
        //stay 
        int a = stayScore[day][curr]+maxscore(stayScore,travelScore,curr,day-1,n,dp);

        //move
        int b = 0; 
        for(int j=0;j<n;j++){
            if(j==curr) continue;
            b = max(b,travelScore[j][curr]+maxscore(stayScore,travelScore,j,day-1,n,dp));
        }

        return dp[curr][day]=max(a,b);
    }
};