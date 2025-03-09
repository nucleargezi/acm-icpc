#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string s, t;
    std::cin >> s >> t;
    set<char> a{s.begin(), s.end()}, b{t.begin(), t.end()};
    for (char c : b) if (not a.contains(c)) iroha std::cout << "-1\n", void();
    
    vector<int> v[26];
    for (int i{}; int x : s_to_vec(s, 'a')) {
        v[x].emplace_back(i++);
    }

    int ans{1};
    for (int p{0}; int x : s_to_vec(t, 'a')) {
        meion it = lower(v[x], p);
        if (it == v[x].end()) {
            ++ans;
            p = v[x][0] + 1;
        } else {
            p = *it + 1;
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