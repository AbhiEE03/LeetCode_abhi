class Solution {
public:
    struct bansi {
        int arr;
        int dep;
    };

    int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
        int n = Arrival.size();
        vector<bansi> bansiwal;  // dynamic list of active platforms

        // first train needs one platform
        bansiwal.push_back({Arrival[0], Departure[0]});
        int platformlimit = 1;

        for (int i = 1; i < n; i++) {
            bool assigned = false;

            // try to fit the train in an existing platform-
            for (int p = 0; p < bansiwal.size(); p++) {
                if (Arrival[i] >= bansiwal[p].dep) {
                    // reuse this platform
                    bansiwal[p] = {Arrival[i], Departure[i]};
                    assigned = true;
                    break;
                }
            }

            // if no platform is free, add a new one
            if (!assigned) {
                bansiwal.push_back({Arrival[i], Departure[i]});
                platformlimit++;
            }
        }
        return platformlimit;
    }
};
