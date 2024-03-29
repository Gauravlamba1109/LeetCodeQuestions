class Solution {
public:
    int candy(vector<int>& ratings) {
        // give 1 candy to min ratings
        vector<int>cand(ratings.size(),1);
        priority_queue<pair<int,int>>q;
        
        for(int i=0;i<ratings.size();i++) q.push({-ratings[i],i});
        
        int n=ratings.size();
        
        while(q.size()){
            int ind = q.top().second; q.pop();
            
            if(ind-1>=0 && ratings[ind]>ratings[ind-1] && ind+1<n && ratings[ind]>ratings[ind+1] )
                cand[ind]=max(cand[ind-1],cand[ind+1])+1;
            
            else if(ind-1>=0 && ratings[ind]>ratings[ind-1] ) cand[ind]=cand[ind-1]+1;
            else if(ind+1<n &&  ratings[ind]>ratings[ind+1] ) cand[ind]=cand[ind+1]+1;
        }
        
        return accumulate(cand.begin(),cand.end(),0);
    }
};