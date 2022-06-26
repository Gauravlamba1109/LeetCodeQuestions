class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
//         vector<vector<int>>m(cardPoints.size(),vector<int>(cardPoints.size(),0));
//         return helper(cardPoints,k,0,cardPoints.size()-1,m);
//         total - subarry = ans 
//             maximize(total-subarray) 
//             minimize subarray 

        int i=0; 
        int j=cardPoints.size()-k;
        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int sum = accumulate(cardPoints.begin(),cardPoints.begin()+j,0);
        int ans = sum;
        
        while(i<j && j<cardPoints.size()){
            sum += (cardPoints[j++]-cardPoints[i++]);
            ans = min(ans,sum);
        }
        return total-ans;
    }
    
    //rec memoery limit exceeded 
    int helper(vector<int>&cards,int k,int i,int j,vector<vector<int>>&m){
        if(i>j || cards.size()==0 || k==0) return 0;
        if(k<0) return 0;
        if(m[i][j]>0) return m[i][j];
        int fs = cards[i] + helper(cards,k-1,i+1,j,m);
        int fe = cards[j] + helper(cards,k-1,i,j-1,m);
        
        return m[i][j]=max(fs,fe);
    }
};