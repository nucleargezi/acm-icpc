#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<pair<int, int>> a(n);
    std::cin >> a;
    map<int, int> M;
    for (meion [x, y] : a) {
        ++M[x];
    }
    ll ans{};
    for (meion [x, y] : M) {
        ans += y * (n - y);
    }
    std::cout << ans / 2 << '\n';
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