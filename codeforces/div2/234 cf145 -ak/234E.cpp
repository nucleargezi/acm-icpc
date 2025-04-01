#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, x, a, b, c);
    using T = pair<ll, string>;
    vector<T> teams(n);
    FOR(i, n) {
        S(s);
        LL(x);
        teams[i] = {x, s};
    }
    vector<vector<string>> ans;
    while (not teams.empty()) {
        sort(teams, greater());
        vector<int> I;
        FOR(4) {
            x = (a * x + b) % c;
            I.emplace_back(x % (len(teams) >> 2));
        }
        FOR(i, 4) I[i] += len(teams) / 4 * i;
        vector<string> s;
        for (int x : I) s.emplace_back(teams[x].second);
        ans.emplace_back(s);
        for (int x : std::views::reverse(I)) {
            teams.erase(teams.begin() + x);
        }
    }
    FOR(i, len(ans)) {
        UL(string("Group ") + char('A' + i) + ':');
        FOR(k, len(ans[i])) UL(ans[i][k]);
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}