class Solution {
public:
    bool makesquare(vector<int>& m) {
//         4 parts divide 
//         such that sum of each part is equal
            
        int sum = accumulate(m.begin(),m.end(),0);
        int partsum = sum/4;
        if(partsum*4!=sum) return false;
        sort(m.rbegin(),m.rend());
        return possible(m,partsum,0,0,0,0,0);
    }
    
    
    
    bool possible(vector<int>&m,int sum,int a, int b,int c,int d,int i){
        if(i==m.size()){
            if(a==b && b==c && c==d) return true;
            else return false;
        }    
        
        if((a+m[i])<=sum && possible(m,sum,a+m[i],b,c,d,i+1)) return true;
        if((b+m[i])<=sum && possible(m,sum,a,b+m[i],c,d,i+1)) return true;
        if((c+m[i])<=sum && possible(m,sum,a,b,c+m[i],d,i+1)) return true;
        if((d+m[i])<=sum && possible(m,sum,a,b,c,d+m[i],i+1)) return true;

        return false;
    }
};