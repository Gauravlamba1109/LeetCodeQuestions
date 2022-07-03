class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0 ; i--){
            if(digits[i]==9) digits[i]=0;
            else{
                digits[i]=digits[i]+1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0]=1;
        return digits;
        

        
//         //if less than 9
//         if(digits[digits.size()-1]<9){
//             digits[digits.size()-1]+=1;
//             return digits;
//         }
//         //if greater than 9
//         else return plus(digits,digits.size()-1,0);
    
    }
    
    
    vector<int> plus(vector<int>&digits,int i,int c){
        if(i<0 && c>0){
            digits.insert(digits.begin(),c);
            return digits;
        }
        else if(i==digits.size()-1){
            digits[i]=0;
            return plus(digits,i-1,1);
        }
        else{
            int t=digits[i]+c;
            digits[i]=t%10;
            if(t/10 >0){
                return plus(digits,i-1,t/10);
            }else{
                return digits;
            }
        }
    }
};