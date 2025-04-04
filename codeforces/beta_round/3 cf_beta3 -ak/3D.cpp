#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    ll ans{}, stk{};
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    FOR(i, n) {
        char &c = s[i];
        if (c == '?') {
            LL(x, y);
            ans += y;
            c = ')';
            q.emplace(x - y, i);
        }
        if (c == '(') {
            ++stk;
        } else {
            if (stk) {
                --stk;
            } else {
                if (q.empty()) iroha UL(-1);
                meion [df, id] = q.top();
                q.pop();
                ans += df;
                s[id] = '(';
                ++stk;
            }
        }
    }
    if (stk) iroha UL(-1);
    UL(ans);
    UL(s);
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