#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    std::cin >> a;
    a = pre_sum(a);
    ll ans{inf<ll>};
    for (int i {1}, k {2}, j {3}; k < n; ++k) {
        while (i + 1 < k and
               ABS(a[k] - a[i] - a[i]) > ABS(a[k] - a[i + 1] - a[i + 1]))
            i++;
        while (j + 1 < n and ABS(a[n] - a[j] - a[j] + a[k]) >
                                 ABS(a[n] - a[j + 1] - a[j + 1] + a[k]))
            j++;
        chmin(ans,
              MAX(a[i], MAX(a[k] - a[i], MAX(a[j] - a[k], a[n] - a[j]))) -
                  MIN(a[i], MIN(a[k] - a[i], MIN(a[j] - a[k], a[n] - a[j]))));
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