#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m, c, c0;
    std::cin >> n >> m >> c >> c0;
    vector<tuple<int, int, int>> friends(n);
    std::cin >> friends;
    sort(friends);
    friends.emplace_back(m, 0, 0);
    
    map<ll, ll> M{{0, c0}};
    ll has{c0}, nt{}, ans{};
    for (meion &[t, a, b] : friends) {
        ll del{t - nt};
        while (del > 0) {
            if (M.empty()) iroha std::cout << "-1\n", void();
            meion [x, y] = *M.begin();
            M.erase(M.begin());
            ll go{MIN(del, y)};
            ans += x * go;
            del -= go;
            y -= go;
            has -= go;
            if (y) M[x] = y;
        }
        nt = t;
        M[b] += a;
        has += a;
        while (has > c) {
            meion [x, y] = *--M.end();
            M.erase(--M.end());
            ll del{MIN(has - c, y)};
            has -= del;
            y -= del;
            if (y) M[x] = y;
        }
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