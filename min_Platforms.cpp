// // //// QUESTION //// //
// Minimum number of platforms required for a railway

// Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.

// In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.

// Note: Time intervals are in the minutes , Leading zeros for minutes less than 1000 are optional (e.g., 0900 is the same as 900).

// Example 1

// Input : Arrival = [900, 940, 950, 1100, 1500, 1800] , Departure = [910, 1200, 1120, 1130, 1900, 2000]

// Output : 3

// Explanation : The first , second , fifth number train can use the platform 1.

// The third and sixth train can use the platform 2.
// The fourth train will use platform 3.
// So total we need 3 different platforms for the railway station so that no train is kept waiting.
// Example 2

// Input : Arrival = [900, 1100, 1235] , Departure = [1000, 1200, 1240]

// Output : 1

// Explanation : All the three trains can use the platform 1.

// So we required only 1 platform.
// Now your turn!

// Input : Arrival = [900, 1000, 1200] , Departure = [1000, 1200, 1240]

// Output:

// Constraints

// 1 <= N <= 105
// 0000 <= Arrival[i] <= Departure[i] <= 2359

#include <bits/stdc++.h>
using namespace std;

// Better Approach by keeping track of max Platforms at any time//
class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        // No clarity if the timings are already sorted
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0;
        int j = 0;

        int currentPlatforms = 0;
        int maxPlatforms = 0;

        // You only care until all trains have arrived
        while (i < n)
        {

            if (arr[i] <= dep[j])
            {

                currentPlatforms++;
                maxPlatforms = max(maxPlatforms, currentPlatforms);
                i++;
            }
            else
            {
                // A train departs before the next train arrives
                currentPlatforms--;
                j++;
            }
        }

        return maxPlatforms;
    }
};

// Another approach//
// Using struct and maintaining a vector of platforms
class Solution
{
public:
    struct bansi
    {
        int arr;
        int dep;
    };

    int findPlatform(vector<int> &Arrival, vector<int> &Departure)
    {
        int n = Arrival.size();
        vector<bansi> bansiwal; // dynamic list of active platforms

        // first train needs one platform
        bansiwal.push_back({Arrival[0], Departure[0]});
        int platformlimit = 1;

        for (int i = 1; i < n; i++)
        {
            bool assigned = false;

            // try to fit the train in an existing platform-
            for (int p = 0; p < bansiwal.size(); p++)
            {
                if (Arrival[i] >= bansiwal[p].dep)
                {
                    // reuse this platform
                    bansiwal[p] = {Arrival[i], Departure[i]};
                    assigned = true;
                    break;
                }
            }

            // if no platform is free, add a new one
            if (!assigned)
            {
                bansiwal.push_back({Arrival[i], Departure[i]});
                platformlimit++;
            }
        }
        return platformlimit;
    }
};
