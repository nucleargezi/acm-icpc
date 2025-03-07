#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string p, h;
    std::cin >> p >> h;
    sort(p);
    for (int i{}; i < len(h) - len(p) + 1; ++i) {
        string s(h.substr(i, len(p)));
        sort(s);
        if (s == p) iroha YES();
    }
    NO();
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