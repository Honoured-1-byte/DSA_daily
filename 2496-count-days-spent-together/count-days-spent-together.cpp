class Solution {
private:
    int toDayOfYear(const string& date) {
        static const int daysBeforeMonth[] = {
            0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
        };        
        int month = stoi(date.substr(0, 2));
        int day =stoi(date.substr(3, 2));        
        return daysBeforeMonth[month] + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, 
                          string arriveBob, string leaveBob) {
        int aStart = toDayOfYear(arriveAlice);
        int aEnd = toDayOfYear(leaveAlice);
        int bStart = toDayOfYear(arriveBob);
        int bEnd = toDayOfYear(leaveBob);
        int overlapStart = max(aStart, bStart);
        int overlapEnd = min(aEnd, bEnd);
        return max(0, overlapEnd - overlapStart + 1);
    }
};