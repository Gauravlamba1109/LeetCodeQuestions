class Solution {
public:
    const long long int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);

        sort(verticalCuts.begin(),verticalCuts.end());
        sort(horizontalCuts.begin(),horizontalCuts.end());
        
        int hm = 0;
        for(int i=0;i<horizontalCuts.size()-1;i++){
            hm= max(hm,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        int vm = 0;
        for(int i=0;i<verticalCuts.size()-1;i++){
            vm= max(vm,verticalCuts[i+1]-verticalCuts[i]);
        }
        long v= hm%mod * vm%mod;
        return (int)v;
        
        //         vector<bool>hor(h+1,0);
//         vector<bool>ver(w+1,0);

//         for(auto hc : horizontalCuts) hor[hc]=1;
//         for(auto vc : verticalCuts) ver[vc]=1;
        
//         int hm = 0;
//         int vm = 0;
//         int prev = 0;
//         for(int i=0;i<hor.size();i++){
//             if(hor[i]==1){
//                 hm = max(hm, i-prev);
//                 prev=i;
//             // cout<<i<<"->"<<prev<<"=prev "<<hm<<endl;
//             }
//         }
//         hm = max(hm,h-prev);
//         // cout<<hor.size()<<"->"<<prev<<"=prev "<<hm<<endl;

//         prev=0;
//         for(int i=0;i<ver.size();i++){
//             if(ver[i]==1){
//                 vm = max(vm, i-prev);
//                 prev=i;
//             // cout<<i<<"->"<<prev<<"=prev "<<vm<<endl;
//             }
//         }
//         vm = max(vm,w-prev);
//         // cout<<ver.size()<<"->"<<prev<<"=prev "<<hm<<endl;

//         // cout<<hm<<" * "<<vm<<endl;
//         return hm*vm;
    }
};