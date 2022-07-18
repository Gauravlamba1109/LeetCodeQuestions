//backtrack
res.pop_back();
nums.insert(nums.begin()+i,choosen_one);
}
}
}
int n=nums.size();
vector<int> t;
solve(nums,n,0,t);
return ans;
}
void solve(vector<int>& nums,int n,int pos,vector<int>& t)
{
if(t.size()==n)
{
set<int> st;
for(int j=0;j<n;j++)
st.insert(t[j]);
if(st.size()==n)
ans.push_back(t);
return;
}
if(t.size()<n)
{
set<int> st;
for(int j=0;j<t.size();j++)
st.insert(t[j]);
if(st.size()!=t.size())
return;
}
for(int i=0;i<n;i++)
{
t.push_back(nums[i]);
solve(nums,n,i,t);
t.pop_back();
}
}