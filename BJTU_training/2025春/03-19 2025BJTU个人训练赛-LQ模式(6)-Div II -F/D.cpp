#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(k);
    deque<pair<ll, ll>> q;
    static bitset<1'00'000> vis;
    ll ans{};
    q.emplace_back(1, 1);
    while (not q.empty()) {
        meion [s, x] = q.front();
        q.pop_front();
        if (vis[x]) continue;
        vis[x] = 1;
        if (not x) {
            ans = s;
            break;
        }
        q.emplace_front(s, 10 * x % k);
        q.emplace_back(s + 1, (x + 1) % k);
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}