class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>n;
        int m = height[0];
        for(auto e: height){
            n.push_back( max(m,e) );
            m = max(m,e);
        }
        int ans = 0;
        m = height[height.size()-1];
        for(int i=height.size()-1; i>=0; i--){
            m = max(m,height[i]);
            ans+= min(n[i],m)-height[i];
        }

        return ans;
    }
};