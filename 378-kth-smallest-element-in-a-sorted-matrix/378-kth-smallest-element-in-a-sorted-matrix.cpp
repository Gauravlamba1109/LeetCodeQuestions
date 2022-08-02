class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // vector<int> v;
        // for(auto c : matrix){
        //     for(auto d : c){
        //         v.push_back(d);
        //     }
        // }
        // sort(v.begin(),v.end());
        // return v[k-1];
        
        // make a set of k ele 
        // if new ele < last ele of set dele last ele 
        // and put the ele in set 
        
        priority_queue<int>s;
        for(int i=0;i<matrix.size();i++){
            if(s.size()>=k && matrix[i][0]>s.top())continue;
            for(int j=0;j<matrix[0].size();j++){
                if(s.size()>=k && matrix[i][j]>s.top())continue;
                if(s.size()<k){
                    s.push(matrix[i][j]);
                }else{
                    if(s.top()>matrix[i][j]){
                        s.pop();
                        s.push(matrix[i][j]);
                    }
                }
            }
        }
        return s.top();
    }
};