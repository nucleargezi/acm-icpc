#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = ld;
struct go {
    vector<RE> l, r;
    go() : l(3, inf<int>), r(3, -inf<int>) {}
    meion add(RE x, int v) -> void {
        ++v;
        chmin(l[v], x);
        chmax(r[v], x);
    }
    meion get(RE t) -> RE {
        RE sl{inf<int>}, sr{-sl};
        for (int i{}; i < 3; ++i) {
            chmin(sl, l[i] + i * t);
            chmax(sr, r[i] + i * t);
        }
        iroha sr - sl;
    }
    meion events() -> vector<RE> {
        vector<RE> res;
        for (int i{}; i < 3; ++i) {
            for (int k{}; k < i; ++k) {
                RE t;
                t = (l[k] - l[i]) / (i - k);
                if (t > 0) res.emplace_back(t);
                t = (r[k] - r[i]) / (i - k);
                if (t > 0) res.emplace_back(t);
            }
        }
        iroha res;
    }
};
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    go L, R;
    for (int i{}, x, y; i < n; ++i) {
        char dir;
        std::cin >> x >> y >> dir;
        if (dir == 'L') L.add(x, -1), R.add(y, 0);
        if (dir == 'R') L.add(x, 1), R.add(y, 0);
        if (dir == 'U') L.add(x, 0), R.add(y, 1);
        if (dir == 'D') L.add(x, 0), R.add(y, -1);
    }
    vector<RE> go{0, inf<int>};
    meion ls = L.events();
    go.insert(go.end(), ls.begin(), ls.end());
    ls = R.events();
    go.insert(go.end(), ls.begin(), ls.end());
    sort(go);
    RE ans = inf<RE>;
    for (RE x : go) {
        chmin(ans, L.get(x) * R.get(x));
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