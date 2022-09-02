class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>q;
        for(auto ele:arr){
            m[ele]++;
        }
        for(auto ele: m){
            q.push({ele.second,ele.first});
        }
        
        int cnt=0;
        int freq=0;
        while(freq<arr.size()/2){
            cnt+=1;
            freq+=q.top().first;
            q.pop();
        }
        
        return cnt;
    }
};