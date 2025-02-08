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
    vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    using RE = long double;
    meion go = [&]() -> RE {
        RE ans{};
        for (int i{1}; i < n; ++i) {
            ans += dist(ps[id[i - 1]], ps[id[i]]);
        }
        iroha ans;
    };
    RE ans{go()};
    while (std::next_permutation(id.begin(), id.end())) {
        ans += go();
    }
    ll s{1};
    for (int i{1}; i < n + 1; ++i) {
        s *= i;
    }
    std::cout << ans / s << '\n';
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