#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> q;
    vector<int> c(n + 1);
    for (int i{}, t, l, r; i < m; ++i) {
        std::cin >> t >> l >> r;
        if (t) ++c[l], --c[r];
        else q.emplace_back(l, r);
    }
    c = pre_sum<false>(c);
    for (int &x : c) x = not not x;
    vector cc = pre_sum<false>(c);
    for (meion [l, r] : q) {
        if (cc[r - 1] - cc[l - 1] == r - l) iroha NO();
    }
    YES();
    for (int i{}, s{n + 2}; i < n; ++i) {
        std::cout << (c[i] ? s : --s) << " \n"[i + 1 == n];
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
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}