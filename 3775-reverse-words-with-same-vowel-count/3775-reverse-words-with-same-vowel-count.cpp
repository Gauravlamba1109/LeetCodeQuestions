class Solution {
public:
    string reverseWords(string s) {
        // use string streams of cpp 
        stringstream ss(s);
        string w;
        ss >> w ; // extract the first word from stringstream and store in w
        int cnt = cal(w);

        string ans = w;
        while(ss >> w){
            ans+=' ';
            if(cal(w)==cnt) reverse(w.begin(),w.end());
            ans+=w;
        }
        return ans;
    }

    int cal(string& a){
        int t=0;
        for(char ele : a){
            if(ele =='a' || ele =='e' ||ele =='i' ||ele =='o' ||ele =='u') t++;
        }
        return t;
    }
};