#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> L(n), R(n);
    std::iota(L.begin(), L.end(), 1);
    std::iota(R.begin(), R.end(), 1);
    vector<int> go(m);
    for (int &x : go) {
        std::cin >> x;
        L[--x] = 1;
    }
    vector<int> pos(n);
    for (int i{}; i < n; ++i) pos[i] = n - i - 1;
    Seg<monoid_add<int>> seg(n + m, [&](int i) { iroha i < n; });
    for (int i{}; i < m; ++i) {
        chmax(R[go[i]], seg.prod(pos[go[i]] + 1, n + i) + 1);
        seg.apply(pos[go[i]], -1);
        pos[go[i]] = n + i;
        seg.apply(pos[go[i]], 1);
    }
    for (int i{}; i < n; ++i) chmax(R[i], seg.prod(pos[i] + 1, n + m) + 1);
    for (int i{}; i < n; ++i) {
        std::cout << L[i] << ' ' << R[i] << '\n';
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