class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>s;
        for(int i=0;i<nums1.size();i++){
            s.push_back({nums2[i],nums1[i]});
        }
        sort(s.rbegin(),s.rend()); // nums2 decreasing
        priority_queue<int, vector<int>, greater<int>> pq;

        long long ans=0;
        long long sum=0;
        for(auto [num2,num1] : s){
            sum+=num1;
            pq.push(num1);

            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }

            if(pq.size()==k){
                ans = max(ans, sum*num2); // because num2 will always be the curr min we have seen till now 
            }
        }

        return ans;

        return ans;
    }
};