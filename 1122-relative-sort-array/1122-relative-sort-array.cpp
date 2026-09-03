class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
        for(int i=0;i<arr1.size(); i++){
            m[arr1[i]]++;
        }
        vector<int>ans;
        for(auto e : arr2){
            while(m.contains(e) && m[e]--){
                ans.push_back(e);
                if(m[e]<=0){
                    m.erase(e);
                }
            }
        }

        
        for(auto [key,val] : m){
            while(val--){
                ans.push_back(key);
            }
        }

        return ans;
    }
};