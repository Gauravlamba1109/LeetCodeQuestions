class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& a, vector<int>& queries) {
        priority_queue<vector<int>>pq;
        unordered_map<int,int>res;
        vector<int>q= queries , res2;
        
        sort(a.begin(),a.end());
        sort(q.begin(),q.end());
        
        int i=0, n=a.size();
        
        for(int qq:q){
            while(i<n && a[i][0]<=qq){
                int l = a[i][0], r = a[i++][1];
                pq.push({l-r-1,r});
            }
            while(pq.size() && pq.top()[1]<qq) pq.pop();
            res[qq]=pq.size()? -pq.top()[0]:-1 ;
        }
        
        for(int qq:queries) res2.push_back(res[qq]);
        return res2;
    }
};