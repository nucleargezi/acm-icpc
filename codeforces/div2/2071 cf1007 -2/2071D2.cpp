#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll n, l, r;
    std::cin >> n >> l >> r;
    vector<ll> a(n);
    std::cin >> a;
    a.insert(a.begin(), 0);
    vector<ll> c = pre_sum<false>(a);
    int N{(n << 2) + 0721};
    for (int i{n + 1}; i < N; ++i) {
        a.emplace_back(c[i >> 1] & 1);
        c.emplace_back(c[i - 1] + a[i]);
    }
    meion f = [&](meion &f, ll p) -> ll {
        if (p < N) iroha a[p];
        if (p & 1) iroha f(f, --p);
        if (p & 3 ^ 2) iroha a[N - 2] ^ f(f, p >> 1);
        iroha a[N - 2];
    };
    meion ff = [&](meion &ff, ll l, ll r) -> ll {
        if (l > r) iroha 0;
        if (r < N) {
            iroha c[r] - c[l - 1];
        }
        if (l < N) iroha c[N - 1] - c[l - 1] + ff(ff, N, r);
        if (l & 3 ^ 2) iroha f(f, l) + ff(ff, l + 1, r);
        if (r & 3 ^ 1) iroha f(f, r) + ff(ff, l, r - 1);
        if (a[N - 2] == 0) iroha ff(ff, l / 2 + 1, r / 2 + 1);
        iroha r - l + 1 - ff(ff, l / 2 + 1, r / 2 + 1);
    };
    std::cout << ff(ff, l, r) << '\n';
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