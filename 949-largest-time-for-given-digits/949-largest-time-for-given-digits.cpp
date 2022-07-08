class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        for(int h=23;h>=0;h--){
            for(int m=59;m>=0;m--){
                if(possible(arr,h,m)){
                    string t = 
                        to_string(h/10)
                        + to_string(h%10)
                        +":"+to_string(m/10)
                        + to_string(m%10) ;
                    
                    return t;
                }
            }
        }
        return "";
    }
    
    bool possible(vector<int>&arr,int h,int m){
        vector<int>a(4);
        a[0]=h/10; a[1]=h%10 ; a[2]=m/10; a[3]=m%10;
        sort(a.begin(),a.end());
        return a==arr;
    }
};