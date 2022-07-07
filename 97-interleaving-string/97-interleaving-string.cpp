class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size()+s2.size())==0 && s3.size()==0) return true; 
        if((s1.size()+s2.size())!=s3.size()) return false;
        vector<vector<int>>m(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(s1,s2,s3,0,0,0,m);
    }
    bool helper(string s1,string s2,string s3, int i ,int j , int k,vector<vector<int>>&m){
        if(k==s3.size()-1){
            if((i<s1.size() && s1[i]==s3[k]) || (j<s2.size() && s2[j]==s3[k])) return m[i][j]=true;
            return m[i][j]= false;
        }
        char t = s3[k];
        if(m[i][j]!=-1) return m[i][j];
        
        if(s1[i]==t && s2[j]==t){
            bool f1 = helper(s1,s2,s3,i+1,j,k+1,m);
            bool f2 = helper(s1,s2,s3,i,j+1,k+1,m);
            return m[i][j]= f1||f2;
        }else if(s1[i]==t){
            return m[i][j]= true && helper(s1,s2,s3,i+1,j,k+1,m);
        }else if(s2[j]==t){
            return m[i][j]= true && helper(s1,s2,s3,i,j+1,k+1,m);
        }
        
        return m[i][j]=false;
    }
};