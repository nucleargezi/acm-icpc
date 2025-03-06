#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    map<int, int> M;
    vector<int> a(n);
    std::cin >> a;
    a.emplace_back(0);
    for (int x : a) {
        ++M[x];
    }
    unique(a);
    n = (int)a.size() - 1;
    mint ans, s = 1;
    for (int i{}; i < MIN(m, n); ++i) {
        s *= M[a[i]];
    }
    for (int i{1}; i < n - m + 2; ++i) {
        s /= M[a[i - 1]];
        s *= M[a[i + m - 1]];
        if (a[i] == a[i + m - 1] - m + 1) ans += s;
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