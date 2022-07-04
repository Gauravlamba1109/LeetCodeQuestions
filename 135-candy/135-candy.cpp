class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>cand(ratings.size(),1);
        
        for(int i=0;i<ratings.size();i++){
            // if only left is less => left+1;
            if(i-1>=0 && ratings[i-1]<ratings[i])cand[i]=cand[i-1]+1;
            // if only right is less => right+1;
            // if(i+1<ratings.size() && ratings[i+1]<ratings[i]){
            //     d[i]=1;
            // }
            // if both less => max(left,right)+1;
        }
        
        for(int i=ratings.size()-1;i>=0;i--){
            // if only left is less => left+1;
            // if only right is less => right+1;
            if(i+1<ratings.size() && ratings[i+1]<ratings[i])cand[i]=cand[i+1]+1;
            
            // if both less => max(left,right)+1;
            if((i+1<ratings.size() && ratings[i+1]<ratings[i]) && (i-1>=0 && ratings[i-1]<ratings[i]) ) cand[i]=max(cand[i+1],cand[i-1])+1;
        }
        // for(auto c:cand)cout<<c<<" ";
        // cout<<endl;
        // for(auto c:ratings)cout<<c<<" ";
        // cout<<endl;
        
        int sum = accumulate(cand.begin(),cand.end(),0);
        return sum;
    }
};

