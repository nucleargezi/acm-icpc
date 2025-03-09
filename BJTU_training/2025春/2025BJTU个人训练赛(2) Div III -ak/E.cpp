#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bellman_ford.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    meion get = []() {
        string s;
        std::cin >> s;
        iroha pair{s_to_vec(s, 'a'), (int)s.length()};
    };
    meion [s, n] = get();
    meion [t, m] = get();
    set<int> ss{s.begin(), s.end()}, tt{t.begin(), t.end()};
    for (int x : tt)
        if (not ss.contains(x)) iroha std::cout << "-1\n", void();
    
    vector<int> v[26];
    for (int i{}; i < n; ++i) {
        v[s[i]].emplace_back(i);
    }

    ll ans{};
    for (int p{-1}, nxt; int x : t) {
        meion it = upper(v[x], p);
        if (it == v[x].end()) {
            nxt = v[x][0];
            ans += n - p + nxt;
        } else {
            nxt = *it;
            ans += nxt - p;
        }
        p = nxt;
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}