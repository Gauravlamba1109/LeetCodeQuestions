class Solution {
public:
    bool canPartitionKSubsets(vector<int>& m, int k) {
        if(m.size()==0) return false;
        
        int sum = accumulate(m.begin(),m.end(),0);
        if(sum%k) return false;
        
        int partsum = sum/k;
        sort(m.rbegin(),m.rend());
        
        vector<int>ans(k,partsum);
        
        return possible(m,partsum,ans,0);
    }

    
    bool possible(vector<int>&m,int sum,vector<int>&ans,int i){
        if(i==m.size()){
            vector<int>t(ans.size(),0);
            return t==ans;
        }    
        int j=0;
        for(auto& ele : ans){
            if((ele-m[i])>=0){
                int k=j-1;
                while(k>=0){ 
                    if(ans[k]==ele)
                        break; 
                    k--;
                }
                if(k!=-1){
                    j++;
                    continue;
                }
                ele-=m[i];
                if(possible(m,sum,ans,i+1)) return true;
                ele+=m[i];
            }
            j++;
        }
        
        return false;
    }
};