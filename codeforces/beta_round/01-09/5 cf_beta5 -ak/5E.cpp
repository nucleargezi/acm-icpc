#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n);
    VEC(int, a, n);
    int id{}, mx{};
    FOR(i, n) if (chmax(mx, a[i])) id = i;
    vector<int> b = vector<int>{a.begin() + id + 1, a.end()} +
                   vector<int>{a.begin(), a.begin() + id};
    ll ans{}, l{};
    vector<int> s(n);
    vector<int> c(n);
    FOR(i, n - 1) {
        while (l and s[l] < b[i]) ans += c[l--];
        if (s[l] != b[i]) s[++l] = b[i], c[l] = 0;
        ans += c[l]++;
    }
    while (l > 1) ans += c[l--];
    UL(ans + n - 1);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}