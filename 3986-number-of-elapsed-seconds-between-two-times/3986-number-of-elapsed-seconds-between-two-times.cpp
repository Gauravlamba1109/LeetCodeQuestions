class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int a = (stoi(endTime.substr(0,2))-stoi(startTime.substr(0,2)))*60*60;
        int b = (stoi(endTime.substr(3,2))-stoi(startTime.substr(3,2)))*60;
        int c = stoi(endTime.substr(6,2))-stoi(startTime.substr(6,2));
        return a+b+c;
    }
};

// 60*60 sec - 34*60 sec - 56 sec

