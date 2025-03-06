#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) std::cin >> x, --x;

    vector<uint16_t> c(m);
    tuple<int, int, int> ans{inf<int>, -1, -1};
    for (int l{}, r{}, s{}; l < n; ++l) {
        while (r < n and s < m) {
            s += not c[a[r++]]++;
        }
        if (s == m) chmin(ans, tuple{r - l, l + 1, r});
        s -= not --c[a[l]];
    }
    meion [len, l, r] = ans;
    std::cout << l << ' ' << r << '\n';
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