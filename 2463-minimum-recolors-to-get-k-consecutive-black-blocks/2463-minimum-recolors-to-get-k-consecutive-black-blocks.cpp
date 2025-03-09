class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // mini W in k eles 
        int prev=blocks[0];

        int ans=10000;
        int n= blocks.size();
  
        int cnt=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') cnt++;
        } //BWBBWWBBBWB
        ans=cnt;
        int l=0; int r=0;
        cout<<n<<endl;
        for(r=k;r<n;r++){
            cout<<blocks[r%n]<<": "<<r<<"=r; r-k=" <<blocks[(r-k)%n] <<" : cnt"<<cnt<<endl;
            string a = blocks.substr((r-k)%n, k); 
            cout<<a;
            cout<<blocks.substr(0,k-a.size())<<endl;
            if(blocks[r%n]=='W'){
                cnt++;
            }
            if(blocks[(r-k)%n]=='W'){
                cnt--;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};

// BWBBWWBBBWB WWWBWWBBWBWBBWBB
