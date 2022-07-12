class Solution {
public:
    bool makesquare(vector<int>& m) {
//         4 parts divide 
//         such that sum of each part is equal
            
        int sum = accumulate(m.begin(),m.end(),0);
        int partsum = sum/4;
        if(sum%4) return false;
        
        sort(m.rbegin(),m.rend());
        vector<int>sumi(4,0);
        
        return possible(m,partsum,sumi,0);
    }
    
    bool possible(vector<int>&m,int part, vector<int>&sum,int i){
        if(i>=m.size())
            return ((sum[0]==sum[1]) && (sum[1]==sum[2]) && (sum[2]==part));
        
        for(int j=0;j<4;j++){
            if((m[i]+sum[j]) > part) continue;
            sum[j]+=m[i];
            if( possible(m,part,sum,i+1) ) return true;
            sum[j]-=m[i];
        }
        return false;
    }
};