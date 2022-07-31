class NumArray {
public:
    void buildtree(vector<int>&nums, int i , int lo , int hi){
        if(lo == hi ){
            tree[i]=nums[lo];
            return ;
        }
        int mid = lo + (hi-lo)/2;
        buildtree(nums, 2*i+1, lo , mid); // left 
        buildtree(nums, 2*i+2, mid+1,hi); // right
        
        tree[i]= tree[2*i+1]+tree[2*i+2];
    }
    
    int query(int i, int j,int lo ,int hi,int treeindex){
        if(lo>j || hi<i) return 0 ; // outside range 
        if(i<=lo&&j>=hi) return tree[treeindex]; // complete inside
        
        int mid = lo + (hi-lo)/2 ;
        
        // if parts of curr range is included then goo deeper 
        if(i>mid){ // go right
            return query(i,j,mid+1,hi, 2*treeindex+2);            
        }else if(j<=mid){ // go left
            return query(i,j,lo,mid, 2*treeindex+1);
        }
        
        // now break the range 
        
        int l = query(i,mid,lo,mid, 2*treeindex+1);
        int r = query(mid+1,j,mid+1,hi, 2*treeindex+2);

        return l+r;
    }
    
    void updatetree(int treei , int lo,int hi, int i, int val){
        if(lo==hi){
            tree[treei]=val;
            return ;
        }
        
        int mid = lo+ (hi-lo)/2;
        
        if(i>mid){ // go right
            updatetree(2*treei+2, mid+1,hi, i,val );
        }else if(i<=mid){
            updatetree(2*treei+1, lo,mid , i,val );
        }
        
        tree[treei]= tree[treei*2+1]+tree[treei*2+2];
    }
        
    int n;
    vector<int>tree;
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n,0);
        buildtree(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        updatetree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */