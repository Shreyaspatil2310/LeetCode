class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int>bucket;
        set<pair<int,int>>freet;
        for (int i = 0; i < times.size(); i++) {
            times[i].push_back(i);
            bucket.insert(i);
        }
        sort(times.begin(), times.end());
        for (int i = 0; i < times.size(); i++) {
            //these seats were become available before.
            while(freet.size() > 0 && (*freet.begin()).first <= times[i][0]) {
                auto el = *freet.begin();
                bucket.insert(el.second);
                freet.erase(freet.begin());
            }
            int chair = *bucket.begin();
            bucket.erase(bucket.begin());
            if (times[i][2] == targetFriend)
                return chair;
            freet.insert({times[i][1], chair});
        }
        return -1;
    }   
};