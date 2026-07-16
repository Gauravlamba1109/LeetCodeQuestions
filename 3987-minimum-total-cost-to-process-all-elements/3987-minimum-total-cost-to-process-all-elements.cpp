class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long mod = 1000000007;
        long cost = 0;
        // int times= 0;
        // int res = k;
        // for(int i=0;i<nums.size();i++){
        //     // cout<<nums[i]<<" k="<<k<<" "<<endl;
        //     if(nums[i]>k){
        //         int extra = nums[i]-k;
        //         int t = extra/res;
        //         int m = extra%res;
        //         if(t==0 || m>0 ) t++;
        //         k+=(res*t);
        //         times=(times+t)%mod;
        //         // cout<<"t="<<t<<endl;
        //     }
        //     k-=nums[i];
        //     if(k<0 || (k==0 && (i+1)<nums.size())){
        //         k+=res;
        //         times++;
        //     }
        // }

        long long t = 0;
        for(auto e: nums) {t+=e;}
        long long times = (t+k-1)/k % mod ;
        // here we exclude the last k addition, mean only times-1 times we have to increase 

        cout<<times<<endl;
        cost=((long)times*(times-1)/2)%mod;
        return cost;
    }
};
