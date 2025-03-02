#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll n, l, r;
    std::cin >> n >> l >> r;
    vector<int> a(n);
    std::cin >> a;
    a.insert(a.begin(), 0);
    for (int i{}; i < n; ++i) {
        a[i + 1] ^= a[i];
    }
    if (n & 1 ^ 1) a.emplace_back(a[n] ^ a[n >> 1]), ++n;
    meion f = [&](meion &f, ll p) -> ll {
        if (p < n + 1) iroha a[p] ^ a[p - 1];
        ll m{p >> 1};
        if(m < n + 1) {
            iroha a[m];
        }
        if (m & 1) {
            iroha a[n];
        }
        iroha a[n] ^ f(f, m);
    };
    std::cout << f(f, l) << '\n';
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