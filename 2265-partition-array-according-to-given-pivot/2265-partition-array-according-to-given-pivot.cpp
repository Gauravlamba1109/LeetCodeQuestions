class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>a(nums.size(),0);
        int interm=0;
        
        int i=0;
        while(i<nums.size()){
            int e = nums[i];
            if(e<pivot) a[i]=1;
            else if(e==pivot){interm++;a[i]=-1;}
            else a[i]=0;
            i++;
        }

        vector<int>c;
        i=0;
        while(i<nums.size()){
            int e = a[i];
            if(e==1){
                c.push_back(nums[i]);
            }
            i++;
        }
        while(interm--)c.push_back(pivot);

        i=0;
        while(i<nums.size()){
            int e = a[i];
            if(e==0){
                c.push_back(nums[i]);
            }
            i++;
        }
        return c;
    }
};
// 9,5,3=>
// 12,10,14,10
