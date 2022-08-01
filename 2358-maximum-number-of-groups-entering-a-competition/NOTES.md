class Solution {
public int maximumGroups(int[] grades) {
Arrays.sort(grades);
int total = 0;
int p = 0;
int curr_total = 0;
int curr_p = 0;
int ans = 0;
for(int x : grades)
{
curr_p += 1;
curr_total += x;
if(curr_p > p && curr_total > total)
{
p = curr_p;
total = curr_total;
ans += 1;
curr_p =0;
curr_total = 0;
}
}
return ans;
}
}