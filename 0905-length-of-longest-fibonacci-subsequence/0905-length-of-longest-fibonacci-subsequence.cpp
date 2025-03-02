class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxi=0;
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),0));
        map<int,int>mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]=i;

        for(int i=arr.size()-1;i>=0;i--){
            for(int j=i+1;j<arr.size();j++){
                int nextval= arr[i]+arr[j];
                int len = 2;
                // cout<<arr[i]<<","<<arr[j]<<" :"<<len<<endl;
                if(mp.find(nextval) != mp.end()){
                    len = 1 + dp[j][mp[nextval]];
                    // cout<<i<<","<<j<<" :match"<<len<<endl;
                    maxi = max(maxi,len);
                }
                dp[i][j]= len;
            }
        }
        return maxi;
    }
};

