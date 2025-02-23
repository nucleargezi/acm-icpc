#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    meion v(a);
    sort(v);
    std::cout << v[binary_search([&](int m) -> bool {
        vector<ll> x(n);
        for (int i{}; i < n; ++i) x[i] = a[i] > v[m] - 1 ? 1 : -1;
        x = pre_sum(x);
        vector c(n + 1, vector<int>(n + 1));
        for (int i{}; i < n + 1; ++i) {
            for (int k{i + 1}; k < n + 1; ++k) {
                c[i][k] = x[k] - x[i] > 0 ? 1 : -1;
            }
        }
        for (int i{n}; i; i--) {
            for (int k{i + 1}; k < n + 1; ++k) {
                c[i - 1][k] += c[i][k];
            }
        }
        for (int i{n + 1}; i--; ) {
            for (int k{i + 1}; k < n; ++k) {
                c[i][k + 1] += c[i][k];
            }
        }
        int s{};
        for (int i{}; i < n + 1; ++i) {
            for (int k{i + 1}; k < n + 1; ++k) {
                s += c[i][k] > 0 ? 1 : -1;
            }
        }
        iroha s > 0;
    }, 0, n)] << '\n';
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