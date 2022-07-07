Explanation
* Sort queries and intervals.
* Iterate queries from small to big,
* and find out all open intervals [l, r],
* and we add them to a priority queue.
* Also, we need to remove all closed interval from the queue.
*
* In the priority, we use
* [interval size, interval end] = [r-l+1, r] as the key.
*
* The head of the queue is the smallest interval we want to return for each query.
*
Complexity
Time O(nlogn + qlogq)
Space O(n+q)
where q = queries.size()
​
vector<int> minInterval(vector<vector<int>>& A, vector<int>& queries) {
priority_queue<vector<int>> pq;
unordered_map<int, int> res;
vector<int> Q = queries, res2;
sort(A.begin(), A.end());
sort(Q.begin(), Q.end());
int i = 0, n = A.size();
for (int q : Q) {
while (i < n && A[i][0] <= q) {
int l = A[i][0], r = A[i++][1];
pq.push({l - r - 1, r});
}
while (pq.size() && pq.top()[1] < q)
pq.pop();
res[q] = pq.size() ? -pq.top()[0] : -1;
}
for (int q : queries)
res2.push_back(res[q]);
return