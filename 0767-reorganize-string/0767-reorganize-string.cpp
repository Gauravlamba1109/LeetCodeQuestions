class Solution {
public:
    string reorganizeString(string s) {
        vector<int>f(26,0);
        for(auto e: s) f[e-'a']++;

        priority_queue<pair<int,char>>max_heap;
        for(int i=0;i<26;i++){
            if(f[i]!=0)
                max_heap.push({f[i],(char)(i+'a')});
        }

        string ans="";
        while(max_heap.size() >=2){
            pair<int,char> p1 = max_heap.top(); max_heap.pop();
            pair<int,char> p2 = max_heap.top(); max_heap.pop();
            string t = "";
            t+= p1.second;
            t+= p2.second;
            ans+= t;
            p1.first--;
            p2.first--;

            if(p1.first>0) max_heap.push(p1);
            if(p2.first>0) max_heap.push(p2);
        }

        if(!max_heap.empty()){
            pair<int,char> p = max_heap.top(); max_heap.pop();
            if(p.first>1) return "";
            ans += p.second;
        }

        return ans;
    }
};