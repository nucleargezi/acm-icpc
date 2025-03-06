#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/and.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    Seg<monoid_and<int>> seg(a);
    
    int q;
    std::cin >> q;
    for (int i{}, l, k; i < q; ++i) {
        std::cin >> l >> k, --l;
        std::cout << (a[l] < k
                          ? -1
                          : seg.max_right(
                                [&](int x) -> bool { iroha x > k - 1; }, l))
                  << " \n"[i + 1 == q];
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