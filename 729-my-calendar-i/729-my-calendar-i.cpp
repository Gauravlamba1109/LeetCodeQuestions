// class MyCalendar {
// public:
//     map<int,int>m;
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {
//         auto next = m.lower_bound(s);  // = to or greater than s ; starting iteratore 
//         for(auto ele:m){
//             int so = ele.second, eo = ele.first;
            
//             if(so<end && start<eo) return false;
            
//             // if valid interval then check next 
            
//         }
//         m[end]=start;
        
//         return true;
//     }
// };


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar {
    map<int, int> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound(s); 
        // first element with key not go before k (i.e., either it is equivalent or goes after).
        
        if (next != books.end() && next->first < e) return false; 
        // a existing book started within the new book (next)
        
        if (next != books.begin() && s < (--next)->second) return false; 
        // new book started within a existing book (prev)
        
        books[s] = e;
        return true;
    }
};
