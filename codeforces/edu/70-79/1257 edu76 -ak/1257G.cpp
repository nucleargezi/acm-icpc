#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/ntt_fft.hpp"

void before() {}

// #define tests
using poly = vector<modint<mod99>>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    map<int, int> m;
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        ++m[x];
    }
    vector<pair<int, int>> a{m.begin(), m.end()};
    meion dfs = [&](meion &dfs, int l, int r) -> poly {
        if (l + 1 == r) iroha poly(a[l].second + 1, 1);
        int m = l + r >> 1;
        iroha convolution(dfs(dfs, l, m), dfs(dfs, m, r));
    };
    std::cout << dfs(dfs, 0, len(a))[n >> 1] << '\n';
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