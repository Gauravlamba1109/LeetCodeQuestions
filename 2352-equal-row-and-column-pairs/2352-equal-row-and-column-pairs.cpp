class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>m;
        for(auto v : grid){
            m[v]++;
        }
        
        int ans = 0;
        for(int j=0;j<grid[0].size();j++){
            vector<int> c;
            for(int i=0;i<grid.size();i++){
                c.push_back(grid[i][j]);
            }
            ans+=m[c];
        }        
        return ans;
        
        // cashing 
        // unordered_map<string,int>mr;
        // unordered_map<string,int>mc;

//         for(int i=0;i<grid.size();i++){
//             string row = "";
//             for(int j=0;j<grid[0].size();j++){
//                 row+=( "#" + to_string(grid[i][j]));
//             }
//             mr[row]++;
//         }
        
//         for(int j=0;j<grid[0].size();j++){
//             string col = "";
//             for(int i=0;i<grid.size();i++){
//                 col+=( "#" + to_string(grid[i][j]));
//             }
//             mc[col]++;
//         }
        
//         int ans = 0 ;
//         for(auto r : mr){
//             if(mc.find(r.first)!=mc.end()){
//                 ans+=( r.second*mc[r.first] );
//             }
//         }
//         return ans;
    }
};