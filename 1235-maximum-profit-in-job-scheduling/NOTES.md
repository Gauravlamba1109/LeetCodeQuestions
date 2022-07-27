public:
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
int n = startTime.size();
vector<vector<int>> jobs;
for (int i = 0; i < n; ++i) {
jobs.push_back({endTime[i], startTime[i], profit[i]});
}
sort(jobs.begin(), jobs.end());
map<int, int> dp = {{0, 0}};
for (auto& job : jobs) {
int cur = prev(dp.upper_bound(job[1]))->second + job[2];
if (cur > dp.rbegin()->second)
dp[job[0]] = cur;
}
return dp.rbegin()->second;
}
class Solution {
void sortByStartTime(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
vector<vector<int>> tmp;
for (int i = 0; i < startTime.size(); i++) {
tmp.push_back({startTime[i], endTime[i], profit[i]});
}
sort(tmp.begin(), tmp.end());
for (int i = 0; i < startTime.size(); i++) {
startTime[i] = tmp[i][0];
endTime[i]   = tmp[i][1];
profit[i]    = tmp[i][2];
}
}
public:
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
sortByStartTime(startTime, endTime, profit);
map<int, int> timeProfit; // dp, timeProfit[i]: maximum profit if we schedule job from timepoint i
int res = 0;
for (int i = startTime.size()-1; i >= 0; i--) {
auto iter = timeProfit.lower_bound(endTime[i]);
int val = (iter == timeProfit.end() ? 0 : iter->second) + profit[i];
timeProfit[startTime[i]] = max(timeProfit[startTime[i]], val);
timeProfit[startTime[i]] = max(timeProfit[startTime[i]], res);
res = timeProfit[startTime[i]];
}
return res;
}
};