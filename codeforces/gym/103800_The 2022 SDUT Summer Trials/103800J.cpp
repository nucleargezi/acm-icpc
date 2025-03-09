#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/hungarian.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int m, n, q;
    std::cin >> m >> n >> q;
    map<string, int> M;
    vector v(n, vector<int>(n));
    for (int i{}, c{}; i < q; ++i) {
        string s, t;
        std::cin >> s >> t;
        if (not M.contains(s)) M[s] = c++;
        if (not M.contains(t)) M[t] = c++;
        v[M[s]][M[t]] = v[M[t]][M[s]] = 1;
    }
    meion [res, match, a, b] = hungarian<int, false>(v);
    std::cout << res / 2 << '\n';
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