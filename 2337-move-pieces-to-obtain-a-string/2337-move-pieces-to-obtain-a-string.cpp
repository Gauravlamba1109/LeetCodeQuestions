class Solution {
public:
    bool canChange(string start, string target) {
        vector<pair<int,char>>a;
        vector<pair<int,char>>b;

        for(int i=0;i<start.size();i++){
            if(start[i]!='_')a.push_back({i,start[i]});
            if(target[i]!='_')b.push_back({i,target[i]});
        }
        if(a.size()!=b.size()) return false;
        
        for(int i=0;i<a.size();i++){
            if(a[i].second != b[i].second) return false;
            
            if(a[i].second=='L'){
                if( a[i].first-b[i].first < 0 ) return false;
            }else{
                if( a[i].first-b[i].first > 0 ) return false;
            }
        }
        return true;
    }
};