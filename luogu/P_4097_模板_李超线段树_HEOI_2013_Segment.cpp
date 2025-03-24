#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lichao_tree.hpp"

void before() {}

// #define tests
constexpr int m1 = 39989, m2 = 1000000000;
using RE = long double;
using F = lichao_line<RE>;
NAME MeIoN_is_UMP45() {
    lichao_tree seg(0, 40000, F{0, 0});
    int lst{}, id{};
    meion f1 = [&](int& x) -> int { iroha x = (x + lst - 1 + m1) % m1 + 1; };
    meion f2 = [&](int& x) -> int { iroha x = (x + lst - 1 + m2) % m2 + 1; };
    map<F, int> M;
    
    INT(n);
    FOR(i, n) {
        INT(op);
        if (op == 1) {
            INT(x, y, xx, yy);
            f1(x), f2(y), f1(xx), f2(yy);
            if (x > xx) std::swap(x, xx), std::swap(y, yy);
            F f;
            if (x == xx) f = {0.L, 1.L * MAX(y, yy)};
            else {
                RE k{(1.L * yy - y) / (xx - x)};
                f = {k, y - k * x};
            }
            seg.chmax_segment(x, xx + 1, f);
            M[f] = ++id;
        } else {
            INT(x);
            f1(x);
            lst = M[seg.query(x).second];
            UL(lst);
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