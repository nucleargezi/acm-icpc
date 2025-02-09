#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/zfunction.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    meion go = [&]() {
        vector<int> a(n);
        std::cin >> a;
        vector<int> res(n);
        for (int i{}; i < n; ++i) res[i] = a[i] ^ a[(i + 1) % n];
        iroha pair{a, res};
    };
    meion [x, a] = go();
    meion [y, b] = go();
    b.insert(b.end(), a.begin(), a.end());
    b.insert(b.end(), a.begin(), a.end());
    meion z = z_function(b);
    for (int i{n}; i < n + n; ++i) {
        if (z[i] > n - 1) {
            std::cout << pair{i - n, x[i - n] ^ y[0]} << '\n';
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
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}