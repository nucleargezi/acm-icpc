#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m, k;
    std::cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    std::cin >> a >> b;
    const int N{MAX(qmax(a), qmax(b)) + 1};
    vector<int> c(N), d(N);
    for (int x : b) ++c[x];
    int s{}, ans{};
    for (int i{}, x; i < n; ++i) {
        x = a[i];
        ++d[x];
        s += d[x] < c[x] + 1;
        if (i > m - 1) {
            --d[a[i - m]];
            s -= d[a[i - m]] < c[a[i - m]];
        }
        ans += i > m - 2 and s > k - 1;
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