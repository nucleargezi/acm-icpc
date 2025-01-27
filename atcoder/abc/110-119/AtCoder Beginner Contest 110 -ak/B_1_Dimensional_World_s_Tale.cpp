#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    vector<int> X(n), Y(m);
    std::cin >> X >> Y;
    int l = qmax(X), r = qmin(Y);
    chmax(l, x), chmin(r, y);
    std::cout << (l < r ? "No War\n" : "War\n");
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