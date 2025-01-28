#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    ll K;
    std::cin >> n >> K;
    vector<ll> a(n);
    std::cin >> a;
    
    ll go{}, ans{};
    for (int bit{60}; ~bit; bit--) {
        ll c{1ll << bit}, s{}, t{};
        for (ll x : a) {
            t += c & x ^ c;
            s += c & x;
        }
        if ((c | go) < K + 1 and chmax(s, t)) {
            go |= c;
        }
        ans += s;
    }
    std::cout << ans << '\n';
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