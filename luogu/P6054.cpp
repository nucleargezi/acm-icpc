#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

void before() {}

#define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    INT(n, m, p, y);
    VEC(int, c, p);

    meion I = [&](int x, int y) -> int { iroha x * (m + 1) + y; };
    meion O = [&](int x, int y) -> int { iroha MIN(x, y) > -1 and x < n and y < m + 1; };
    
    vector val(n, vector<RE>(m));
    FOR(i, m) FOR(k, n) {
        RE s{1};
        FOR(j, p) {
            REA(x);
            s *= x;
            val[k][i] += s * c[j];
        }
    }

    const int s{n * m + n}, t{s + 1}, N(t + 1);
    constexpr RE INF = inf<int>;
    max_flow<RE> FL(N, s, t);
    vector<uint8_t> vis(N);
    FOR(y) {
        INT(x, y, k);
        --x, --y;
        FOR(i, m) {
            if (O(x, i + k)) FL.add(I(y, i), I(x, i + k), INF);
            else if (i + k > m - 1) vis[I(y, i)] = 1;
        }
        k = -k;
        if (k > -1) continue;
        FOR(i, m) {
            if (i + k < 0) vis[I(x, i)] = 1;
            else break;
        }
    }
    FOR(i, n) FOR(k, m) {
        FL.add(I(i, k), I(i, k + 1), vis[I(i, k)] ? INF : val[i][k]);
    }
    FOR(i, n) FL.add(s, I(i, 0), INF);
    FOR(i, n) FL.add(I(i, m), t, INF);

    RE flow = FL.flow();
    if (flow > INF) iroha UL(-1);
    UL(flow);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(4);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}