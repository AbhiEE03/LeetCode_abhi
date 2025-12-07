class Solution {
public:
    using ll = long long;

    // normalize slope (dy, dx)
    pair<int,int> normSlope(int dy, int dx) {
        if (dx == 0) return {1, 0};  // vertical
        if (dy == 0) return {0, 1};  // horizontal
        int g = gcd(dy, dx);
        dy /= g;
        dx /= g;
        // ensure dx > 0
        if (dx < 0) dy = -dy, dx = -dx;
        return {dy, dx};
    }

    // normalize intercept (b = y*dx - x*dy)
    long long interceptKey(int x, int y, int dy, int dx) {
        // ax + by + c = 0  --> store c = y*dx - x*dy
        return (long long)y * dx - (long long)x * dy;
    }

    long long countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<long long, vector<pair<int,int>>> slopeLines;
        unordered_map<long long, vector<pair<int,int>>> midPointSlope;

        // build lines
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                auto sl = normSlope(dy, dx);
                long long ic = interceptKey(x1, y1, sl.first, sl.second);

                long long mpKey =
                    ((long long)(x1 + x2) << 32) | (unsigned)(y1 + y2);

                slopeLines[((long long)sl.first << 32) | (unsigned)sl.second]
                    .push_back({0, ic});

                midPointSlope[mpKey].push_back(sl);
            }
        }

        long long result = 0;

        // count parallel distinct lines (same slope, different intercepts)
        for (auto &it : slopeLines) {
            auto &vec = it.second;
            if (vec.size() <= 1) continue;

            map<long long, int> mp;
            for (auto &p : vec) mp[p.second]++;

            long long prev = 0;
            for (auto &x : mp) {
                result += prev * x.second;
                prev += x.second;
            }
        }

        // remove duplicates created through midpoint grouping
        for (auto &it : midPointSlope) {
            auto &vec = it.second;
            if (vec.size() <= 1) continue;

            map<pair<int,int>, int> mp;
            for (auto &sl : vec) mp[sl]++;

            long long prev = 0;
            for (auto &x : mp) {
                result -= prev * x.second;
                prev += x.second;
            }
        }

        return result;
    }
};
