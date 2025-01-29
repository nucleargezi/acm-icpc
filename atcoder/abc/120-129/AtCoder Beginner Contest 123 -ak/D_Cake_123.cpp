#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int x, y, z, K;
    std::cin >> x >> y >> z >> K;
    meion [a, b] = [&]() {
        vector<ll> a(x), b(y), c(z), ret;
        std::cin >> a >> b >> c;
        for (ll x : a) {
            for (ll y : b) {
                ret.emplace_back(x + y);
            }
        }
        sort(ret, greater());
        ret.resize(K);
        iroha tuple{ret, c};
    }();
    vector<ll> v;
    for (ll x : a) {
        for (ll y : b) {
            v.emplace_back(x + y);
        }
    }
    sort(v, greater());
    v.resize(K);
    for (ll x : v) {
        std::cout << x << '\n';
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