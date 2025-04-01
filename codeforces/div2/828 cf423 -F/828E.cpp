#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    
    meion G = [](char c) -> int {
        iroha c == 'A' ? 0 : c == 'T' ? 1 : c == 'G' ? 2 : 3;
    };

    using T = Seg<monoid_add<ll>>;
    vector seg(4, vector<vector<T>>(11));
    FOR(i, 4) FOR(k, 1, 11) FOR(k) seg[i][k].emplace_back(T(ceil(n, k)));

    meion add = [&](int x, char ch, int y) -> void {
        int c{G(ch)};
        FOR(i, 1, 11) seg[c][i][x % i].apply(x / i, y);
    };
    FOR(i, n) add(i, s[i], 1);
    
    INT(q);
    FOR(q) {
        INT(op);
        if (op == 1) {
            INT(x);
            --x;
            CH(c);
            add(x, s[x], -1);
            s[x] = c;
            add(x, s[x], 1);
        } else {
            INT(l, r);
            --l;
            S(s);
            const int N{len(s)};
            ll res{};
            FOR(i, N) {
                int M{(l + i) % N};
                int L{MAX(ceil(l - M, N), 0)}, R{MAX(ceil(r - M, N), 0)};
                res += seg[G(s[i])][N][M].prod(L, R);
            }
            UL(res);
        }
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}