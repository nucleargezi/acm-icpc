#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    ll k;
    string in;
    std::cin >> in >> k;
    vector s = s_to_vec(in, '0');
    vector<pair<int, i128>> a;
    for (int x : s) {
        if (a.empty() or a.back().first != x) {
            a.emplace_back(x, 1);
        } else {
            ++a.back().second;
        }
    }
    for (int i{}; i < 100; ++i) {
        for (meion &[x, y] : a) {
            y *= x;
            chmin(y, inf<ll>);
        }
    }
    for (meion &[x, y] : a) {
        if (y < k) {
            k -= y;
        } else {
            iroha std::cout << x << '\n', void();
        }
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