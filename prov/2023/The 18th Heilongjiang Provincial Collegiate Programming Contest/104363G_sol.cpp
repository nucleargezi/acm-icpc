#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using P = point<ll>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<P> ps(n);
    std::cin >> ps;
    P al;
    for (meion &p : ps) al += p;
    vector<ll> a(n);
    for (int i{}; i < n; ++i) {
        a[i] = ps[i].det(al);
    }
    sort(a, greater());
    a = pre_sum(a);
    using RE = long double;
    RE ans{};
    for (int i{1}; i < n; ++i) {
        chmax(ans, (RE)a[i] / i / (n - i));
    }
    std::cout << ans / 2 << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}