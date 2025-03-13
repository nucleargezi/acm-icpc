#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, k);
    VEC(int, a, n);
    VEC(int, c, k);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<vector<int>> ans;
    for (sort(a, greater()); int x : a) {
        if (q.empty() or q.top().first == c[x - 1]) {
            q.emplace(0, len(ans));
            ans.emplace_back();
        }
        meion [sz, idx] = q.top();
        q.pop();
        ans[idx].emplace_back(x);
        q.emplace(sz + 1, idx);
    }

    UL(len(ans));
    for (meion &v : ans) {
        UL(len(v), v);
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}