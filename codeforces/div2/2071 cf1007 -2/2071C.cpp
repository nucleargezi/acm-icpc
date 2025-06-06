#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, s, t;
    std::cin >> n >> s >> t, --s, --t;
    graph<int> g(n);
    g.read_tree();
    tree v(g, t);
    for (int t{}; int x : std::views::reverse(argsort(v.deep))) {
        std::cout << ++x << " \n"[++t == n];
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