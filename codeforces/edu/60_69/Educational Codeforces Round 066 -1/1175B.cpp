#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    ll ans{};
    bool ok = true;
    vector<ll> s{1};
    for (int i{}, x; i < n; ++i) {
        string op;
        std::cin >> op;
        if (ok) {
            if (op[0] == 'f') {
                std::cin >> x;
                s.emplace_back(MIN(s.back() * x, 1ll << 32));
            } else if (op[0] == 'a') {
                ans += s.back();
                ok &= ans < (1ll << 32);
            } else {
                s.pop_back();
            }
        }
    }
    std::cout << (ok ? std::to_string(ans) : "OVERFLOW!!!") << '\n';
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