class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>me(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        return helper(strs,0,0,m,n,0,me);
    }
    
    int helper(vector<string>& v, int cur0, int cur1 , int tar0, int tar1 , int pos,vector<vector<vector<int>>>&m){
        
        if((cur0)>tar0 || (cur1)>tar1 || pos == v.size()){
            return 0 ;
        }
        if(m[pos][cur0][cur1]) return m[pos][cur0][cur1];
        
        int z0 = count(v[pos].begin(),v[pos].end(),'0');
        int z1 = count(v[pos].begin(),v[pos].end(),'1');
        
        
        if(pos==(v.size()-1)){
            if(cur0+z0<=tar0 && cur1+z1<=tar1){ 
                m[pos][cur0][cur1]=1;
                return 1;
            }
            m[pos][cur0][cur1]=0;
            return 0;
        }
        
        
        int inc = INT_MIN ;
        int noc = helper(v,cur0, cur1, tar0 , tar1 , pos+1,m);
        
        if((cur0+z0)<=tar0 && (cur1+z1)<=tar1)
            inc = 1+helper(v,cur0+z0, cur1+z1, tar0 , tar1 , pos+1,m);
        
        m[pos][cur0][cur1]= max(inc,noc);
        
        return m[pos][cur0][cur1];
    }
};