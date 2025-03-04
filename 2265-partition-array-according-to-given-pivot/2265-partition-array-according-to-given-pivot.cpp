class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>a;
        int interm=0;
        vector<int>b;

        for(auto e:nums){
            if(e<pivot)a.push_back(e);
            else if(e==pivot)interm++;
            else b.push_back(e);
        }

        vector<int>c;
        for(auto e:a)c.push_back(e);
        while(interm--)c.push_back(pivot);
        for(auto e:b)c.push_back(e);

        return c;
    }
};
// 9,5,3=>
// 12,10,14,10
