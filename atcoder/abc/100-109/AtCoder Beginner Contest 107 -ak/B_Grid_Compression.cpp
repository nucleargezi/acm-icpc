#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    int a[n][m];
    bool v[n], vv[m];
    memset(a, 0, sizeof a);
    memset(v, 0, sizeof v);
    memset(vv, 0, sizeof vv);
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            char c;
            std::cin >> c;
            a[i][k] = c == '#';
        }
    }
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            if (a[i][k]) goto fail;
        }
        v[i] = 1;
        fail: ;
    }
    for (int i{}; i < m; ++i) {
        for (int k{}; k < n; ++k) {
            if (a[k][i]) goto faill;
        }
        vv[i] = 1;
        faill: ;
    }
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            if (v[i] or vv[k]) continue;
            std::cout << (a[i][k] ? '#' : '.');
        }
        if (not v[i]) std::cout << '\n';
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