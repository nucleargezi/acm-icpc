#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/pck/02_path_color.hpp"

NAME MeIoN_is_UMP45() {
    int w, n;
    std::cin >> w >> n;
    vector<ll> a(n);
    std::cin >> a;
    int m;
    std::cin >> m;
    vector<int> c(m);
    std::cin >> c;
    int s{n + m}, t{n + m + 1};
    MaxFlow<ll> g(t + 1, s, t);
    meion L = [&](int i) { iroha i; };
    meion R = [&](int i) { iroha n + i; };
    for (int i{}; i < n; ++i) g.add(s, L(i), a[i]);
    for (int i{}; i < m; ++i) g.add(R(i), t, c[i]);
    for (int i{}; i < m; ++i) {
        int sz;
        std::cin >> sz;
        vector<int> ok(n, 1);
        for (int _{sz}; _--; ) {
            int x;
            std::cin >> x;
            ok[--x] = 0;
        }
        for (int k{}; k < n; ++k) if (ok[k]) g.add(L(k), R(i), inf<ll>);
    }
    ll f = g.flow();
    if (f < w) std::cout << "BANSAKUTSUKITA\n";
    else std::cout << "SHIROBAKO\n";
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}