class Solution {
public:
    struct trans{
        string name;
        int time ;
        int amt ;
        string city;
        string t;
        bool m;
        
        
        trans(string a,int b,int c,string d,string st,bool e){
            name = a;
            time = b;
            amt = c;
            city = d;
            t = st;
            m = e ; 
        }
    };
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        if(transactions.size()==0) return {} ;
        
        unordered_map<string,vector<trans*>>tran;
        
        for(auto s : transactions){
            stringstream ss(s);
            string t;
            vector<string>v;
            for(int i=0;i<4;i++){
                getline(ss,t,',');
                v.push_back(t);
            }
            trans* tt = new trans(v[0],stoi(v[1]),stoi(v[2]),v[3],s,0);
            tran[v[0]].push_back(tt);
        }
        vector<string>result;
        
        for(auto &p : tran){
            sort(p.second.begin(),p.second.end(), [](const trans*a , const trans*b){
                return a->time < b->time ;
            });
            
            for(int i=0;i<p.second.size(); i++){
                
                if(p.second[i]->amt > 1000 ){
                    result.push_back(p.second[i]->t);
                    p.second[i]->m = 1;
                }
                
                if(i>0 && p.second[i]->time <= (p.second[i-1]->time+60) ){
                    int r = i-1;
                    while(r>=0 && p.second[i]->time <= (p.second[r]->time+60) ){
                        if(p.second[i]->city != p.second[r]->city){
                            if(!p.second[r]->m){
                                result.push_back(p.second[r]->t);
                                p.second[r]->m = 1;
                            }
                            if(!p.second[i]->m){
                                result.push_back(p.second[i]->t);
                                p.second[i]->m = 1;
                            }
                        }
                        r--;
                    }
                }
            }
        }
        
        return result;
    }
};