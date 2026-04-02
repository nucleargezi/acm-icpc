#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(string, s, n);
    VVEC(int, a, n, m);
    
    meion I{[&](int x, int y) { iroha x * m + y; }}; 
    vector<vector<int>> v(n * m);
    vector<int> in(n * m), ou(n * m);
    
    FOR(i, n) FOR(k, m) {
        int x{i}, y{k};
        if (s[i][k] == 'u') x -= a[i][k];
        if (s[i][k] == 'd') x += a[i][k];
        if (s[i][k] == 'l') y -= a[i][k];
        if (s[i][k] == 'r') y += a[i][k];
        if (MIN(x, y) > -1 and x < n and y < m) {
            v[I(i, k)].emplace_back(I(x, y));
            ++in[I(x, y)];
            ++ou[I(i, k)];
        }
    }

    bool ok{true};
    int rt{}, c{n * m};
    FOR(i, n * m) if (ou[i] == 1 and in[i] == 0) rt = i;
    vector<uint8_t> vis(n * m);
    meion f{[&](meion &f, int n) -> void {
        vis[n] = 1;
        --c;
        if (v[n].empty() or vis[v[n][0]]) iroha;
        f(f, v[n][0]);
    }};
    f(f, rt);
    No(c);
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