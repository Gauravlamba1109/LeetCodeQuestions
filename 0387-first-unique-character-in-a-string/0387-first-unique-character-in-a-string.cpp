class Solution {
public:
    int firstUniqChar(string s) {
        int arr[27]= {0} ;
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a']==0) arr[s[i]-'a']=1;
            else if(arr[s[i]-'a']==1) arr[s[i]-'a']=-1 ;
        }
        for(int i=0;i<s.size();i++){
            if( arr[s[i]-'a']== 1 ) return i;
        }

        return -1;
    }
};