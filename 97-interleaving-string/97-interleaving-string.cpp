class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int si1=s1.size(),si2=s2.size(),si3=s3.size();
        
        if((si1+si2)==0 && si3==0) return true; 
        if((si1+si2)!=si3) return false;
        
        vector<vector<int>>m(si1+1,vector<int>(si2+1,-1));
        
        return helper(s1,s2,s3,0,0,0,m);
    }
    bool helper(string s1,string s2,string s3, int i ,int j , int k,vector<vector<int>>&m){
        if(k==s3.size()-1){
            if((i<s1.size() && s1[i]==s3[k]) || (j<s2.size() && s2[j]==s3[k])) return m[i][j]=true;
            return m[i][j]= false;
        }
        if(m[i][j]!=-1) return m[i][j];
        
        char t = s3[k];
        
        if(s1[i]==t && s2[j]==t){
            bool f1 = helper(s1,s2,s3,i+1,j,k+1,m);
            bool f2 = helper(s1,s2,s3,i,j+1,k+1,m);
            return m[i][j]= f1||f2;
        }
        
        else if(s1[i]==t) return m[i][j]=helper(s1,s2,s3,i+1,j,k+1,m);
        else if(s2[j]==t) return m[i][j]=helper(s1,s2,s3,i,j+1,k+1,m);
        
        return m[i][j]=false;
    }
};