#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/maxinum_anti_chain.hpp"

constexpr int N = 50000 + 1;
vector<int> e[N];

void before() {
    FOR(i, 1, N) {
        for (int k{2}; i * k < N; ++k) {
            e[i * k].emplace_back(i);
        }
    }
}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    debug(n);
    debug(a);
    vector<int> I(qmax(a) + 1, -1);
    FOR(i, n) I[a[i]] = i;
    graph<int, true> g(n << 1);
    FOR(i, n) {
        for (int x : e[a[i]]) {
            if (I[x] == -1) continue;
            g.add(I[x], i);
            g.add(I[x], i + n);
            g.add(I[x] + n, i + n);
        }
        g.add(i, i + n);
    }
    g.build();
    UL(n - len(maximum_anti_chain(g)));
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