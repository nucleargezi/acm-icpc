#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> v(m);
    std::cin >> v;
    sort(v);
    int rr{inf<int>};
    int ans{};
    for (meion [l, r] : v) {
        if (rr > l) {
            chmin(rr, r);
        } else {
            ++ans;
            rr = r;
        }
    }
    std::cout << ++ans << '\n';
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