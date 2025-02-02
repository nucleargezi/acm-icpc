#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    map<string, set<pair<int, int>>> m;
    int n;
    std::cin >> n;
    for (int i{}, x; i < n; ++i) {
        string s;
        std::cin >> s >> x;
        m[s].emplace(-x, i);
    }
    for (const meion &[x, y] : m) {
        for (meion [a, b] : y) {
            std::cout << ++b << '\n';
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