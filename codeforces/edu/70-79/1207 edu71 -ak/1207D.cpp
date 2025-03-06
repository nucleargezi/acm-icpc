#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<pair<ll, ll>> t(n);
    std::cin >> t;
    sort(t);
    vector<ll> a(n), b(n);
    for (int i{}; i < n; ++i) {
        std::tie(a[i], b[i]) = t[i];
    }

    meion go = [&](const vector<ll> &a) -> mint {
        mint res{1};
        map<ll, int> M;
        for (const meion &x : a) {
            ++M[x];
        }
        for (const meion [x, y] : M) {
            res *= fact<mint>(y);
        }
        iroha res;
    };

    mint ans{fact<mint>(n) - go(a) - go(b)};
    bool f{true};
    for (int i{}; i < n - 1 and f; ++i) {
        f &= t[i].second < t[i + 1].second + 1;
    }
    for (int i{}; i < n; ++i) a[i] = n * a[i] + b[i];
    std::cout << ans + (f ? go(a) : 0) << '\n';
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