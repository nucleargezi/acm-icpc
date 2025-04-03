#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<pair<int, int>> a(n);
    for (meion &[l, r] : a) {
        IN(l, r);
        if (l > r) std::swap(l, r);
    }
    sort(a, [](meion x, meion y) { iroha x.second < y.second; });
    vector<int> ans;
    for (int i{}, mx{-inf<int>}; i < n; ++i) {
        if (mx < a[i].first) {
            ans.emplace_back(a[i].second);
            mx = a[i].second;
        }
    }
    UL(len(ans));
    UL(ans);
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