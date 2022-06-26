class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(count(arr.begin(),arr.end(),0)==0) return false;
        //bfs
        queue<int>q;
        q.push(start);
        
        if(arr[start]==0) return true;
        
        while(q.size()>0){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int ind = q.front(); q.pop();
                
                if(arr[ind]<0) continue;
                
                int newind1 = ind+ arr[ind];
                int newind2 = ind- arr[ind];

                arr[ind] = -arr[ind];
                
                if(newind1<arr.size()){
                    if(arr[newind1]==0) return true;
                    q.push(newind1);
                }
                
                if(newind2>=0){
                    if(arr[newind2]==0) return true;
                    q.push(newind2);
                }
            }
        }
        return false;
    }
};