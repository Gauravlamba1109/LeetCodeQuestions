class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(count(arr.begin(),arr.end(),0)==0) return false;
        
        //bfs
        queue<int>q;
        q.push(start);
        
        if(arr[start]==0) return true;
        
        map<int,bool>m1;
        map<int,bool>m2;
        
        m1[start]=1;
        m2[start]=1;
        
        while(q.size()>0){
            // int siz = q.size();
            // for(int i=0;i<siz;i++){
                int f = q.front(); q.pop();
                int ind = f;
                
                int newind1 = ind+ arr[ind];
                int newind2 = ind- arr[ind];
                
                if(newind1<arr.size()){
                    if(arr[newind1]==0) return true;
                    if(m1[newind1]==1) continue;
                    
                    q.push(newind1);
                    m1[newind1]=1;
                }
                
                if(newind2>=0){
                    if(arr[newind2]==0) return true;
                    if(m2[newind2]==1) continue;
                    
                    q.push(newind2);
                    m2[newind2]=1;
                }
            // }
            
        }
        
        return false;
    }
};