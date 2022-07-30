class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // method 1 is using 2 loops to create all pairs 
        // o(n2) complexity
        
        // method 2 is using mergesort algo 
        
        int cnt = mergesort(nums,0,nums.size()-1);
        
        return cnt;
    }
    
    int mergesort(vector<int>&nums,int left , int right){
        
        if(left>=right) return 0;
        
        int cnt = 0;
        int mid = (right+left)/2;
        cnt+=mergesort(nums,left,mid);
        cnt+=mergesort(nums,mid+1,right);
        cnt+= merge(nums,left,mid,right);
        
        return cnt;
    }
    
    // 1,2,3   3,1
    // i       j
        
    int merge(vector<int>&nums,int left,int mid , int right){
        // before sorting count the no of inverse pairs among left-mid and mid+1-right
        int i=left;
        int j=mid+1;
        int cnt = 0;
        while(j<=right){
            
            while(i<=mid && nums[i]<=2*(long long)(nums[j])){
                i++;
            }
            if(i<=mid){
                cnt += mid-i+1 ;
            }
            j++;
        }
        
        //merge them now 
        vector<int>m;
        i=left;
        j=mid+1;
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){m.push_back(nums[i]); i++;}
            else{m.push_back(nums[j]); j++;}
        }
        while(i<=mid)m.push_back(nums[i++]);
        while(j<=right)m.push_back(nums[j++]);
        
        i=0;
        for(int k=left;k<=right;k++){
            nums[k]=m[i++];
        }
        
        return cnt;
    }
};