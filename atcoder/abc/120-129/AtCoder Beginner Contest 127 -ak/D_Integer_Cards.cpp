#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    map<ll, int> M;
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        ++M[x];
    }
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y;
        int s{};
        vector<pair<ll, int>> del;
        for (meion [a, b] : M) {
            if (a < y) {
                int d = MIN(x - s, b);
                del.emplace_back(a, d);
                s += d;
            } else {
                break;
            }
            if (s == x) break;
        }
        for (meion [x, y] : del) {
            M[x] -= y;
            if (not M[x]) M.extract(x);
        }
        M[y] += s;
    }
    ll ans{};
    for (meion [x, y] : M) ans += x * y;
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