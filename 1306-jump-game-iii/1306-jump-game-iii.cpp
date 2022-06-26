class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(count(arr.begin(),arr.end(),0)==0) return false;
        
        //bfs
        queue<pair<int,int>>q;
        q.push({start,arr[start]});
        if(arr[start]==0) return true;
        map<string,bool>m;
        m[to_string(start)+";"+to_string(arr[start])]=1;
        
        while(q.size()>0){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                pair<int,int>f = q.front(); q.pop();
                int ind = f.first;
                int val = f.second;
                
                int newind1 = ind+ val;
                int newind2 = ind- val;
                
                if(newind1<arr.size()){
                    if(arr[newind1]==0) return true;
                    
                    string t = to_string(newind1)+";"+to_string(arr[newind1]);
                    // if(m[t]) continue;
                    
                    q.push({newind1,arr[newind1]});
                    m[t]=1;
                    
                }
                if(newind2>=0){
                    if(arr[newind2]==0) return true;
                    
                    string t = to_string(newind2)+";"+to_string(arr[newind2]);
                    if(m[t]) continue;
                    
                    q.push({newind2,arr[newind2]});
                    m[t]=1;
                    

                }
                
            }
        }
        
        return false;
    }
};