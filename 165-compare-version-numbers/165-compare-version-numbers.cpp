class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<int>s1;
        vector<int>s2;
        int i=0;
        while(i<v1.size()){
            if(v1[i]=='.'){i++; continue;}
            string temp="";
            while(i<v1.size() && v1[i]!='.'){
                temp+=v1[i];
                i++;
            }
            int t = stoi(temp);
            s1.push_back(t);
        }
        
        i=0;
        while(i<v2.size()){
            if(v2[i]=='.'){i++; continue;}
            string temp="";
            while(i<v2.size() && v2[i]!='.'){
                temp+=v2[i];
                i++;
            }
            int t = stoi(temp);
            s2.push_back(t);
        }
        
        
        while(s1.size()<s2.size()){
            s1.push_back(0);
        }
        while(s1.size()>s2.size()){
            s2.push_back(0);
        }
        
        
        for(int j=0;j<min(s1.size(),s2.size());j++){
            if(s1[j]==s2[j])continue;
            else{
                if(s1[j]<s2[j])return -1;
                else return 1;
            }
        }
        
        return 0;
    }
};


