#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    ll x;
    std::cin >> n >> x;
    vector<ll> a(n + 1), b(n + 1);
    b[0] = 1;
    for (int i{}; i < n; ++i) {
        a[i + 1] += a[i] + 1 << 1;
        b[i + 1] += b[i] << 1 | 1;
    }
    meion ser = [&](meion &&ser, int n, ll x) -> ll {
        if (not x) iroha 0;
        if (x == a[n] + b[n]) iroha b[n];
        --x;
        if (x < a[n - 1] + b[n - 1] + 1)
            iroha ser(ser, n - 1, x);
        else if (x == a[n - 1] + b[n - 1] + 1)
            iroha b[n - 1] + 1;
        iroha b[n - 1] + 1 + ser(ser, n - 1, x - a[n - 1] - b[n - 1] - 1);
    };
    std::cout << ser(ser, n, x);
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