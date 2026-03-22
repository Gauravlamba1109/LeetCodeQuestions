class Solution {
public:
    int getgcd(int a, int b){
        int lag = max(a,b);
        int sma = min(a,b);

        while(true){
            int quo = lag/sma ;
            int rem = lag%sma ;
            if(rem==0){
                // cout<<"gcd="<<sma<<endl;
                return sma;
            }

            lag = sma;
            sma = rem;


        }
        return 1;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int>ans;
        int lag=nums[0];
        for(auto e: nums){
            lag=max(lag,e);
            ans.push_back(getgcd(lag,e));
        }
        
        cout<<endl;
        sort(ans.begin(),ans.end());
        int a = 0, b= nums.size()-1;
        long long res=0;
        while(a<b && a<nums.size()-1 && b>=0){
            // cout<<ans[a]<< " and "<<ans[b]<<endl;
            res += getgcd(ans[a],ans[b]);
            a++; b--;
        }

        return res;

    }
};