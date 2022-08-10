class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1000000007;
        sort(arr.begin(),arr.end());
        vector<long long>m(arr.size(),1);
        int i=0;
        for(auto ele : arr)m[i++]=1;
        
        for(int i=0;i<arr.size();i++){
            // root = arr[i]; 
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]!=0)continue;
                // left = arr[j]
                // right*left = head
                // right = head/left 
                if(find(arr.begin(),arr.end(),(arr[i]/arr[j]))!=arr.end()){
                    int t = find(arr.begin(),arr.end(),(arr[i]/arr[j]))-arr.begin();
                    m[i]= ((long long)(m[i]+ (long long)(m[j]*m[t])%mod)%mod);
                }
            }
        }
        
        int s = 0;
        for(auto ele: m){
            s=(s+ele)%mod;
        }
        return s;
    }
};