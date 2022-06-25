class Solution {
public:
    bool canMeasureWater(int j1c, int j2c, int target) {
        queue<int>q;
        q.push(0);
        map<int,bool>m;
        m[0]=1;
        
        while(q.size()>0){
            int c = q.front(); q.pop();
            
            if(c==target) return 1;
            
            int c_j1cA = min(c+j1c,j1c+j2c);
            int c_j1cS = max(c-j1c,0);
            int c_j2cA = min(c+j2c,j1c+j2c);
            int c_j2cS = max(c-j2c,0);
            
            if(m[c_j1cA]==0) {q.push(c_j1cA); m[c_j1cA]=1;}
            if(m[c_j1cS]==0) {q.push(c_j1cS); m[c_j1cS]=1;}
            if(m[c_j2cA]==0) {q.push(c_j2cA); m[c_j2cA]=1;}
            if(m[c_j2cS]==0) {q.push(c_j2cS); m[c_j2cS]=1;}
            
        }
        
        return false;
    }
};