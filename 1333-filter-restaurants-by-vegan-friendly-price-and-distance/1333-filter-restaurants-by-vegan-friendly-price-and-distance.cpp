class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int vf, int mP, int mD) {
//         [1,  4,    1 ,   40, 10]
//         id,rating,vf,price,dist
        priority_queue<pair<int,int>>m;
        // rating - index 
        
        for(auto res : restaurants){
            if(vf && res[2]==vf){
                if(res[3]<=mP && res[4]<=mD){
                    m.push({res[1],res[0]});
                }
            }
            else if(vf==0){
                if(res[3]<=mP && res[4]<=mD){
                    m.push({res[1],res[0]});
                }
            }
        }
        
        vector<int>ans;
        while(m.size()){
            ans.push_back(m.top().second);
            m.pop();
        }
        return ans;
    }
};