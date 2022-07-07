class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& a, vector<int>& queries) {
        // * Sort queries and intervals.
        // * Iterate queries from small to big,
        // * and find out all open intervals [l, r],
        // * and we add them to a priority queue.
        // * Also, we need to remove all closed interval from the queue.
        // * 
        // * In the priority, we use
        // * [interval size, interval end] = [r-l+1, r] as the key.
        // * 
        // * The head of the queue is the smallest interval we want to return for each query.
        // *
        // Complexity
        // Time O(nlogn + qlogq)
        // Space O(n+q)
        // where q = queries.size()

        priority_queue<vector<int>>pq;
        unordered_map<int,int>res;
        vector<int>q= queries , res2;
        
        sort(a.begin(),a.end());
        sort(q.begin(),q.end());
        
        int i=0, n=a.size();
        
        for(int qq:q){
            while(i<n && a[i][0]<=qq){
                pq.push({(-a[i][1]+a[i][0]-1),a[i][1]});
                i++;
            }
            while(!pq.empty() && pq.top()[1]<qq) pq.pop();
            res[qq]=pq.size()?-pq.top()[0]:-1 ;
        }
        
        for(int qq:queries) res2.push_back(res[qq]);
        return res2;
    }
};