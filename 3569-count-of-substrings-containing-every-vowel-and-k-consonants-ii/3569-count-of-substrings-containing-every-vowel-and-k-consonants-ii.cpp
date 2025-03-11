class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long a = atleastk(word,k);
        long long b = atleastk(word,k+1);
        return (long long)(a-b);
    }

    long long atleastk(string word, int k) {
        if(word.size()<(5+k) ) return 0;
        
        map<char,int>vow;
        string v = "aeiou";

        int i=0,j=0, cons=0;
        long long ans=0;
        while(j<word.size()){
            if(v.contains(word[j])){
                vow[word[j]]++;
            }else{
                cons++;
            }

            // if cur str is valid 
            while(vow.size()==5 & cons>=k ){
                // now we be greedy and move the starting pointer towards j 
                // to see how many we can remove b4 we hit invalid string 
                ans += (word.size()-j);
                if(v.contains(word[i])){
                    vow[word[i]]--;
                }else{
                    cons--;
                }
                if(vow[word[i]]==0) 
                    vow.erase(word[i]);
                
                i++;
            }

            j++;
        }

        return ans;

    }
    
};