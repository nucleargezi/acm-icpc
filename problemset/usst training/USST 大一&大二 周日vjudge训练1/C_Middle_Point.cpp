#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int a, b, x, y;
    std::cin >> a >> b >> x >> y;
    if ((not a and x) or (not b and y)) {
        iroha std::cout << "-1\n", void();
    }
    if (not a and not b) {
        iroha std::cout << ((not x and not y) ? 0 : -1) << '\n', void();
    }
    int gcda = std::gcd(a, x), gcdb = std::gcd(b, y);
    int ta = not(a and x) ? 1 : a / gcda, tx = not(a and x) ? 0 : x / gcda;
    int tb = not(b and y) ? 1 : b / gcdb, ty = not(b and y) ? 0 : y / gcdb;
    if (popcount(ta) > 1 or popcount(tb) > 1) {
        iroha std::cout << "-1\n", void();
    }
    while (ta < tb) ta <<= 1, tx <<= 1;
    while (ta > tb) tb <<= 1, ty <<= 1; 
    int m = [&]() {
        int m = ta, res = 0;
        while (m > 1) ++res, m >>= 1;
        iroha res;
    }();
    vector<tuple<int, int, int, int>> ans;
    int px{}, py{};
    if (ta == tx) {
        px = a, --tx;
    }
    if (tb == ty) {
        py = b, --ty;
    }
    for (int i = 0; i < m; ++i) {
        int nx = (tx & 1) ? a : 0, ny = (ty & 1) ? b : 0;
        ans.emplace_back(px, py, nx, ny);
        px = (px + nx) >> 1, py = (py + ny) >> 1;
        tx >>= 1, ty >>= 1;
    }
    std::cout << ans.size() << '\n';
    for (meion [a, b, c, d] : ans) {
        std::cout << array{a, b, c, d} << '\n';
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