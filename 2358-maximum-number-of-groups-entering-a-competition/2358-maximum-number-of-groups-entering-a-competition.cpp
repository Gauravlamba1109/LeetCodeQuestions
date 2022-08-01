class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int prevsum=0;
        int prevele=0;
        int currsum=0;
        int currele=0;
        int i=0;
        int cnt=0;
        while(i<grades.size()){
            while(i<grades.size() && (currsum<=prevsum || currele<=prevele) ){
                currsum+=grades[i];
                currele+=1;
                i++;
            }
            cnt++;
            prevsum=currsum;
            prevele=currele;
            currsum=0;
            currele=0;
            i++;
        }
        return cnt;
    }
};

// [10,6,12,7,3,5]
// 3,5,6,7,10,12

//     3
//     5 6
//     7 10 12