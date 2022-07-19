class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = "";
        string right = "", left="";
        
        int i=0,n=dominoes.size();
        while(i<n){
            if(dominoes[i]=='.'){
                right+='.';
                i++;
            }else{
                if(dominoes[i]=='L'){
                    right+='L';
                    i++;
                }else{
                    int j=i;
                    while(j<n && dominoes[j]!='L'){
                        right+='R';
                        j++;
                    }
                    i=j;
                }
            }
        }
        reverse(dominoes.begin(),dominoes.end());
        
        i=0;
        n=dominoes.size();
        while(i<n){
            if(dominoes[i]=='.'){
                left+='.';
                i++;
            }else{
                if(dominoes[i]=='R'){
                    left+='R';
                    i++;
                }else{
                    int j=i;
                    while(j<n && dominoes[j]!='R'){
                        left+='L';
                        j++;
                    }
                    i=j;
                }
            }
        }
        reverse(left.begin(),left.end());
        
        for(int i=0;i<left.size();i++){
            if(left[i]==right[i]){
                ans+=left[i];
            }else{
                if(left[i]=='.' || right[i]=='.'){
                    if(left[i]=='.')ans+=right[i];
                    else ans+=left[i];
                    continue;
                }
                
                char s = right[i];
                char e = left[i];
                
                int j=i;int ct=0;
                while(right[j]==s && left[j]==e){
                    ct++;
                    j++;
                }
                    cout<<ct<<" ";
                for(int k=0;k<ct/2;k++)ans+=s;
                if(ct%2)ans+='.';
                for(int k=0;k<ct/2;k++)ans+=e;
                i=j-1;
            }
        }
        return ans;
    }
};

// 1L1R3LR2L2
// _L_R___LR__L__
// _L_RRRRLRRRL__
// LL_RLLLLRLLL__
// LL_R___LR__L__
// __R RRR LR RR L__
// LL_R LLL LR LL L__
//      R_L LR RL
