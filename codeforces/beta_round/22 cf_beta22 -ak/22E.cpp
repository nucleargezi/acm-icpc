#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<int> in(n), s(n), L, R;
    vector<int> vis(n, -1);
    FOR(i, n) {
        IN(s[i]);
        --s[i];
        ++in[s[i]];
    }
    int c{};
    meion f = [&](meion &f, int n) -> int {
        vis[n] = 0;
        if (vis[s[n]] == -1) {
            iroha vis[n] = f(f, s[n]);
        }
        iroha vis[n] = n;
    };
    FOR(i, n) if (not in[i]){
        ++c;
        L.emplace_back(i + 1);
        R.emplace_back(f(f, i) + 1);
    }
    int cc{c};
    FOR(i, n) if (vis[i] == -1) {
        ++c;
        L.emplace_back(i + 1);
        R.emplace_back(f(f, i) + 1);
    }
    if (c == 1 and not cc) c = 0;
    UL(c);
    FOR(i, c) UL(R[i], L[(i + 1) % c]);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}