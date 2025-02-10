#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, x;
    std::cin >> n >> x;
    vector<int> a(x, -1), b(x, -1), L(n, 0);
    for (int i{}, x; i < n; ++i) {
        std::cin >> x, --x;
        if (a[x] == -1) a[x] = i;
        b[x] = i;
        L[i] = x;
    }
    for (int i{1}; i < n; ++i) chmax(L[i], L[i - 1]);
    int t{x}, p{n};
    for (int i{x}; i--; ) {
        if (a[i] == -1) {
            t = i;
            continue;
        }
        if (b[i] > p) break;
        t = i;
        p = a[i];
    }
    ll ans{};
    for (int i{}, k{-1}, s; i < x; ++i) {
        s = MAX(t - 1, i, (k > -1 ? L[k] : -1));
        ans += x - s;
        if (a[i] > -1) {
            if (k > a[i]) break;
            k = b[i];
        }
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