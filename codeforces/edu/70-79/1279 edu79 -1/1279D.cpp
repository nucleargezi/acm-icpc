#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<vector<int>> v(n);
    map<int, int> M;
    for (int i{}, sz; i < n; ++i) {
        std::cin >> sz;
        v[i].resize(sz);
        for (int &x : v[i]) {
            std::cin >> x;
            ++M[--x];
        }
    }
    mint ans;
    for (int i{}; i < n; ++i) {
        for (int x : v[i]) {
            ans += mint(M[x]) / len(v[i]);
        }
    }
    std::cout << ans / n / n << '\n';
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