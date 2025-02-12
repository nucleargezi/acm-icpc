#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<tuple<int, int, int>> a;
    for (int i{}, x, y; i < n; ++i) {
        std::cin >> x >> y;
        a.emplace_back(x, 0, i);
        a.emplace_back(y, 1, i);
    }
    sort(a, greater());
    vector<pair<mint, mint>> v(n);
    map<mint, mint> m;
    for (meion [x, t, i] : a) {
        if (t) {
            m[v[i].first + x] += v[i].second;
        } else {
            if (m.empty()) v[i] = {0, 1};
            else v[i] = {m.begin()->first - x, m.begin()->second};
        }
    }
    std::cout << m.begin()->second << '\n';
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