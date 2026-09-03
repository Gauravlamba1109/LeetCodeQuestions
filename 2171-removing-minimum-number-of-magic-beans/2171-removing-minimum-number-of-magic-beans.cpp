class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        
        long long total = 0;
        
        for (int x:beans) total += x;
        
        long long ans=LLONG_MAX;
        int n=beans.size();
        
        for (int i=0;i<n;i++) {
            long long remainingBags = n - i; // all eles onto the right needs to be normalized, we can leave the left side ones because they will become 0 anyways 
            // in case of duplicates [2, 2, 3, 10] -> at i=0 we will have our answer, at i=1 it assumes 2 is emptied, so no harm here 
            long long remove = total - 1LL * beans[i] * remainingBags;
            ans = min(ans, remove);
        }

        return ans;
    }
};