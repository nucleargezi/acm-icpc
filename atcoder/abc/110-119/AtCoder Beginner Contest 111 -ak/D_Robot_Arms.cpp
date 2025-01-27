#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> need;
    vector<pair<ll, ll>> a(n);
    for (meion &[x, y] : a) {
        std::cin >> x >> y;
        need.emplace_back(x + y);
        need.emplace_back(x - y);
    }
    unique(need);
    ll s{};
    for (ll x : need) s += x & 1;
    if (s and s != need.size()) iroha std::cout << "-1\n", void();
    vector<ll> v;
    ll max = MAX(-need[0], need.back()), M{max};
    for (int i{}; i < 33; ++i) {
        if (max + 1 > (1ll << i)) {
            v.emplace_back(1ll << i), max -= 1ll << i;
        }
    }
    if (max) v.emplace_back(max);
    int m = v.size();
    std::cout << m << '\n' << v << '\n';
    for (meion [x, y] : a) {
        vector<int> go(m);
        for (meion [a, b] : vector<pair<int, int>>{{x + y, 1}, {x - y, 2}}) {
            ll d = M - a >> 1;
            if (d + 1 > v.back()) {
                go[m - 1] += b;
                d -= v.back();
            } 
            for (int i{}; i < m - 1; ++i) {
                if (d >> i & 1) {
                    go[i] += b;
                    d -= 1ll << i;
                }
            }
        }
        static constexpr char s[] = {'R', 'D', 'U', 'L'};
        for (meion x : go) {
            std::cout << s[x];
        }
        std::cout << '\n';
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