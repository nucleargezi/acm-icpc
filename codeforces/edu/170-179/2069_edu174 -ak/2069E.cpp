#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    static meion get_v = []() -> pair<vector<int>, int> {
        string s;
        std::cin >> s;
        iroha {s_to_vec(s, 'A'), (int)s.length()};
    };
    meion [s, n] = get_v();
    array<int, 4> a;
    std::cin >> a;
    int sa{std::ranges::count(s, 0)}, sb{std::ranges::count(s, 1)};
    int need = MAX(sa - a[0], sb - a[1]);
    if (a[2] + a[3] < need) iroha NO();
    vector<int> v[2];
    int c{};
    for (int l{}, r; l < n; l = r) {
        r = l + 1;
        while (r < n and s[r] != s[r - 1]) ++r;
        c += r - l - 1 >> 1;
        if (r - l & 1 ^ 1) v[s[l]].emplace_back(r - l >> 1);
    }
    for (int i : {0, 1}) {
        sort(v[i]);
        for (int x : v[i]) {
            if (a[2 + i] > x - 1) {
                a[2 + i] -= x;
                ++c;
            }
        }
    }
    YES(c > need - 1);
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