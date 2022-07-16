class MyCalendar {
public:
    map<int,int>m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto ele:m){
            int so = ele.second, eo = ele.first;
            
            if( so>start && so>=end && eo>end )continue;
            if( so<start && so<end && eo<=start )continue;
            return false;
        }
        m[end]=start;
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */