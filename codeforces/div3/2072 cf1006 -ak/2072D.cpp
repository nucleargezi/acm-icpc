#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    Wavelet_Matrix g(a);
    ll s{};
    for (int i{}; i < n; ++i) {
        s += i - g.prefix_count(0, i, a[i] + 1);
    }
    tuple<int, int, int> ans{s, 1, 1};
    for (int i{}; i < n; ++i) {
        for (int k{i + 1}; k < n; ++k) {
            int ts{s};
            ts -= g.prefix_count(i + 1, k + 1, a[i]);
            ts += g.count(i + 1, k + 1, a[i] + 1, inf<int>);
            chmin(ans, tuple{ts, i + 1, k + 1});
        }
    }
    meion [len, l, r] = ans;
    std::cout << pair(l, r) << '\n';
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