class Solution {
public:
    void sortwith(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        vector<vector<int>>t;
        for(int i=0;i<profit.size();i++)t.push_back({startTime[i],endTime[i],profit[i]});
        sort(begin(t),end(t));
        for(int i=0;i<profit.size();i++){
            startTime[i]=t[i][0];
            endTime[i]=t[i][1];
            profit[i]=t[i][2];
        }
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        // sort using starttime
        sortwith(startTime,endTime,profit);
        
        // make a map ; start->max_profit
        map<int,int>m;
        int maxp=0;
        
        // to the curr node see the one starting just after this and has max profit 
        // add it to curr profit
        // starting from end because we will process with the task occuring at the end first 
        // and using that we will make the one before it and so on 
        
        for(int i=profit.size()-1;i>=0;i--){
            int currp = profit[i];
            int e = endTime[i];
            int s = startTime[i];
            
            auto startingJustAfterend = m.lower_bound(e);
            int profitofit = (startingJustAfterend==m.end())?
                                    0 : startingJustAfterend->second ;
            int profitifcurrincluded = currp + profitofit;
            
            // store res for curr 
            m[s] = max({m[s],profitifcurrincluded,maxp});
            maxp = m[s];
        }
        
        return maxp;
    }
};