class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size()+1,vector<bool>(grid[0].size()+1,0));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>q;
        q.push({grid[0][0],0,0}); //starting
        
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(q.size()!=0){
            tuple<int,int,int> t = q.top(); q.pop();
            int c = get<0>(t);
            int i = get<1>(t);
            int j = get<2>(t);
            // cout<<i<<","<<j<<endl;
            if(i==grid.size()-1 && j==grid[0].size()-1) return c;
            for(auto d : dir){
                int ii = i+d[0];
                int jj = j+d[1];
                
                if(ii<0 || jj<0 || ii>=grid.size() || jj>=grid[0].size() || vis[ii][jj]==1) continue; 
                
                q.push({max(grid[ii][jj],c),ii,jj}); // max of curr time and time of nbr ;
                                                     // because if the height is less we can get to it in the same time 
                vis[ii][jj]=1;
            }
        }
        return -1;
    }
};