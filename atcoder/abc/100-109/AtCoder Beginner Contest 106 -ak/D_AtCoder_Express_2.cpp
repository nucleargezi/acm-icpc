#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, q;
    std::cin >> n >> m >> q;
    vector<pair<int, int>> go(m);
    for (meion &[l, r] : go) {
        std::cin >> l >> r, --l, --r;
    }
    sort(go);
    vector<int> a(m);
    for (int i{}; i < m; ++i) {
        a[i] = go[i].second;
    }
    Wavelet_Matrix g(a);
    for (int i{}, l, r; i < q; ++i) {
        std::cin >> l >> r, --l;
        std::cout << g.count(lower(go, pair {l, 0}) - go.begin(),
                             lower(go, pair {r, 0}) - go.begin(), l, r)
                  << '\n';
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