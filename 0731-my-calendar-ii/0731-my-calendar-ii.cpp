#include <vector>
#include <algorithm>

class MyCalendarTwo {
private:
    std::vector<std::pair<int, int>> calendar;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        int startIndex = findInsertIndex(start);
        int endIndex = findInsertIndex(end);
        
        for (int i = startIndex; i < endIndex; i++) {
            if (abs(calendar[i].second) > 1) {
                return false;
            }
        }

        int startFrequency = 1;
        if (startIndex > 0) {
            startFrequency = calendar[startIndex - 1].second + 1;
        }
        
        int endFrequency = -1;
        if (endIndex < calendar.size()) {
            endFrequency = calendar[endIndex].second - 1;
        }

        if (startFrequency > 2 || -endFrequency > 2) {
            return false;
        }

        for (int i = startIndex; i < endIndex; i++) {
            calendar[i].second += 1; 
        }

        calendar.insert(calendar.begin() + startIndex, {start, startFrequency});
        calendar.insert(calendar.begin() + endIndex + 1, {end, endFrequency});
        
        return true;
    }

private:
    int findInsertIndex(int time) {
        int low = 0, high = calendar.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (calendar[mid].first < time) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};