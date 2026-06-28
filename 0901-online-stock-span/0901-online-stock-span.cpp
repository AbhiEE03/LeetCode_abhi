class StockSpanner {
public:
    vector<pair<int, int>> st;
    int idx, ans;
    StockSpanner() {
        idx = -1;
        st.clear();
    }

    int next(int price) {
        idx += 1;
        while (!st.empty() && (price >= st.back().first)) {
            st.pop_back();
        }
        ans = idx - (st.empty() ? -1 : st.back().second);
        st.push_back({price, idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */