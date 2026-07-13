class Solution {
public:
    string base = "123456789";
    vector<int> sequentialDigits(int low, int high) {
        string l = to_string(low) ;
        string h = to_string(high);
        vector<int>ans;
        // increasing window size
        for(int i=l.size(); i<=h.size(); i++){
            // numbers with each window // should start with l[0] // substr( pos and len )
            for(int j=0; j<base.size(); j++){
                string t = base.substr(j,i) ;
                if(t.size()!=i) continue;
                int a = stoi(t);
                if( a>=low && a<=high){
                    ans.push_back(a);
                }
            }
        }

        return ans;
    }
};