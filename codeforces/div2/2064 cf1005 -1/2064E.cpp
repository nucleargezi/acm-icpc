#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/minmax.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

#define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> p(n), col(n);
    std::cin >> p >> col;
    Seg<monoid_add<int>> SA(n, [](int i) { iroha 1; });
    Seg<monoid_minmax<int>> SB(n, [&](int i) { iroha pair{col[i], col[i]}; });
    mint ans{1};
    for (int id : argsort(p)) {
        int c{col[id]};
        meion check = [&](meion x) {
            meion [min, max] = x;
            iroha(min == c or min == inf<int>) and
                (max == c or max == -inf<int>);
        };
        ans *= SA.prod(SB.min_left(check, id), SB.max_right(check, id));
        SB.set(id, {inf<int>, -inf<int>});
        SA.set(id, 0);
    }
    std::cout << ans << '\n';
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