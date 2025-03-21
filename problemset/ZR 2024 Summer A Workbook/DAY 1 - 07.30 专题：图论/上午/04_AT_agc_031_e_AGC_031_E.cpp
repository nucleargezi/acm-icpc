#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow_min_cost.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<ll> x(n), y(n), v(n);
    FOR(i, n) IN(x[i], y[i], v[i]);

    INT(m);
    map<char, int> M{{'L', 0}, {'R', 1}, {'D', 2}, {'U', 3}};
    vector c(4, vector<ll>(n));
    constexpr ll INF{1'000'000'000'000'000};
    fill(c[1], INF), fill(c[3], INF);
    FOR(i, m) {
        CHAR(t);
        LL(a, b);
        meion &v = c[M[t]];
        if (M[t] & 1) chmin(v[b], a - 1);
        else chmax(v[b], a + 1);
    }
    FOR(x, 4) FOR(i, n - 1) {
        if (x & 1) chmin(c[x][i + 1], c[x][i]);
        else chmax(c[x][i + 1], c[x][i]);
    }
    
    ll ans{};
    meion f = [&](int L) -> ll {
        const int s{L + n << 1}, t{s | 1};
        mcf_graph<ll, ll> FL(t + 1);
        FOR(i, L) {
            FL.add(s, i, 1, 0);
            FL.add(i + n + n + L, t, 1, 0);
        }
        FOR(i, n) {
            FL.add(i + L, i + L + n, 1, INF - v[i]);
            FOR(k, L) {
                if (x[i] >= c[0][k] and x[i] <= c[1][L - k - 1]) {
                    FL.add(k, i + L, 1, 0);
                }
                if (y[i] >= c[2][k] and y[i] <= c[3][L - k - 1]) {
                    FL.add(i + L + n, k + L + n + n, 1, 0);
                }
            }
        }
        meion [flow, cost] = FL.flow(s, t);
        iroha INF * flow - cost;
    };
    FOR(i, n) chmax(ans, f(i + 1));
    UL(ans);
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