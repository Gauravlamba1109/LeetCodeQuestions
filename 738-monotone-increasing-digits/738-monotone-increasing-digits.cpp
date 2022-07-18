class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int>t;
        while(n>0){
            t.push_back(n%10);
            n/=10;
        }
        reverse(t.begin(),t.end());
        
        int ending = t.size()-1;
        
        for(int i=t.size()-1 ; i>=1; i--){
            if(t[i-1]>t[i]){
                ending = i-1;
                t[i-1]--;
            }
        }
        for(int i=ending+1;i<t.size();i++){
            t[i]=9;
        }
        int x=0;
        for(auto e:t)x=x*10+e;
        return x;
    }
};