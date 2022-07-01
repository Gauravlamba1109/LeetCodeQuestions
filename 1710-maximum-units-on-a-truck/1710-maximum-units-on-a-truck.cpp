class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(), [](const vector<int>a,const vector<int>b){
            return a[1]>b[1];
        });
        int ans=0;
        for(auto ele : boxTypes){
            if(truckSize>ele[0]){
                ans+=(ele[0]*ele[1]);
                truckSize-=ele[0];
            }else{
                ans+=(truckSize*ele[1]);
                return ans;
            }
        }
        return ans;
    }
};


