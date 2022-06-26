class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool>dead;
        unordered_map<string,bool>visited;
        
        for(auto ele : deadends) dead[ele]=1;
        
        queue<pair<string,int>>q;
        q.push({"0000",0});
        visited["0000"]=1;
        if(dead["0000"])return -1;
        while(q.size()!=0){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                string fr = q.front().first; 
                int cnt = q.front().second;
                q.pop();
                if(fr==target) return cnt;
                
                for(int j=0;j<fr.size();j++){
                    string a = fr;
                    int t = fr[j]-'0';
                    a[j]= ((t+1)%10 + '0');
                    if(dead.find(a)==dead.end() && visited[a]==0){ 
                        if(a==target) return cnt+1;
                        q.push({a,cnt+1}); visited[a]=1;
                    }
                    
                    a[j]= (abs((fr[j]-'0'+10)-1)%10 + '0');
                    if(dead.find(a)==dead.end() && visited[a]==0){ 
                        if(a==target) return cnt+1;
                        q.push({a,cnt+1}); visited[a]=1;
                    }
                }
            }
        }
        
        return -1;
    }
};