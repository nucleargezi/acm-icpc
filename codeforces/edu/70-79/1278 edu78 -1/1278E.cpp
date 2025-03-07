#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph g(n);
    g.read_tree();
    tree v(g);
    vector<int> L(n), R(n);
    L[0] = 1;
    for (int r{1}; int i : v.V) {
        vector child = v.collect_child(i);
        int son{len(child)};
        r += son + 1;
        int p = R[i] = r;
        for (int x : child) {
            L[x] = --p;
        }
    }
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