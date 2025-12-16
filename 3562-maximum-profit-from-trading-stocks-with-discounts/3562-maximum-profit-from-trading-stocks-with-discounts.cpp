class Solution {
public:
    int maxProfit(int n,
                  vector<int>& present,
                  vector<int>& future,
                  vector<vector<int>>& hierarchy,
                  int budget) {

        vector<vector<int>> tree(n);
        for (auto &e : hierarchy) {
            tree[e[0] - 1].push_back(e[1] - 1);
        }

        function<pair<vector<int>, vector<int>>(int)> dfs =
        [&](int u) -> pair<vector<int>, vector<int>> {

            vector<int> dp_no(budget + 1, 0);   // no discount from parent
            vector<int> dp_yes(budget + 1, 0);  // discount available

            for (int v : tree[u]) {
                auto [cno, cyes] = dfs(v);
                dp_no = merge(dp_no, cno);
                dp_yes = merge(dp_yes, cyes);
            }

            vector<int> new_no = dp_no;
            vector<int> new_yes = dp_no;

            int full = present[u];
            int half = present[u] / 2;

            int gain_full = future[u] - full;
            int gain_half = future[u] - half;

            // Buy at full price (requires parent discount)
            for (int b = full; b <= budget; b++) {
                new_no[b] = max(new_no[b], dp_yes[b - full] + gain_full);
            }

            // Buy at discounted price
            for (int b = half; b <= budget; b++) {
                new_yes[b] = max(new_yes[b], dp_yes[b - half] + gain_half);
            }

            return {new_no, new_yes};
        };

        // 🔥 FIX: call dfs ONCE
        auto result = dfs(0);
        return *max_element(result.first.begin(), result.first.end());
    }

private:
    vector<int> merge(const vector<int>& A, const vector<int>& B) {
        int n = A.size();
        vector<int> res(n, -1e9);

        for (int i = 0; i < n; i++) {
            if (A[i] < 0) continue;
            for (int j = 0; i + j < n; j++) {
                if (B[j] < 0) continue;
                res[i + j] = max(res[i + j], A[i] + B[j]);
            }
        }
        return res;
    }
};
