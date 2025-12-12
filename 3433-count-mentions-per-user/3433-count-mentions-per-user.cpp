#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isOnline(int offlineTime, int timestamp) {
        return offlineTime == 0 || timestamp >= offlineTime + 60;
    }

    void applyMessageEvent(vector<string>& event,
                           vector<int>& mentionCount,
                           vector<int>& offlineTime) {

        int timestamp = stoi(event[1]);

        vector<string> tokens;
        stringstream ss(event[2]);
        string t;

        while (ss >> t) tokens.push_back(t);

        for (string token : tokens) {

            if (token == "ALL") {
                for (int i = 0; i < mentionCount.size(); i++)
                    mentionCount[i]++;
            }

            else if (token == "HERE") {
                for (int i = 0; i < mentionCount.size(); i++)
                    if (isOnline(offlineTime[i], timestamp))
                        mentionCount[i]++;
            }

            else {
                int id = stoi(token.substr(2));
                mentionCount[id]++;
            }
        }
    }

    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {

        vector<int> mentionCount(numberOfUsers, 0);
        vector<int> offlineTime(numberOfUsers, 0);

        // Sort events by timestamp
        // OFFLINE before MESSAGE on equal timestamps
        sort(events.begin(), events.end(),
             [&](vector<string>& a, vector<string>& b) {

            int ta = stoi(a[1]);
            int tb = stoi(b[1]);

            if (ta != tb) return ta < tb;

            // tie-break:
            if (a[0] != b[0])
                return a[0] == "OFFLINE"; // OFFLINE first

            return false;
        });

        for (auto& event : events) {

            if (event[0] == "OFFLINE") {
                int timestamp = stoi(event[1]);
                int id = stoi(event[2]);
                offlineTime[id] = timestamp;
            }

            else {
                applyMessageEvent(event, mentionCount, offlineTime);
            }
        }

        return mentionCount;
    }
};
