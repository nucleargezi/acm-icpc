#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = len(s);
    
    meion move = [](ll &x, ll &y, char dir) -> void {
        x += dir == 'D' ? 1 : dir == 'A' ? -1 : 0;
        y += dir == 'S' ? 1 : dir == 'W' ? -1 : 0;
    };
    meion update = [](ll &a, ll &b, ll &c, ll &d, ll e, ll f, ll g, ll h) -> void {
        chmin(a, e), chmax(b, f);
        chmin(c, g), chmax(d, h);
    };
    
    vector<tuple<ll, ll, ll, ll>> ps{{0, 0, 0, 0}}, cp(ps);
    for (ll x{}, y{}; char c : s) {
        meion [l, r, u, d] = ps.back();
        move(x, y, c);
        update(l, r, u, d, x, x, y, y);
        ps.emplace_back(l, r, u, d);
    }
    for (ll x{}, y{}; char c : std::ranges::views::reverse(s)) {
        meion [l, r, u, d] = cp.back();
        if (c == 'D') ++r, ++l;
        if (c == 'A') --l, --r;
        if (c == 'S') ++d, ++u;
        if (c == 'W') --u, --d;
        update(l, r, u, d, 0, 0, 0, 0);
        cp.emplace_back(l, r, u, d);
    }
    reverse(cp);
    
    ll ans{inf<ll>};
    meion upd_ans = [&](ll x, ll y, ll a, ll b, ll c, ll d, ll e, ll f, ll g, ll h) -> void {
        update(a, b, c, d, e + x, f + x, g + y, h + y);
        chmin(ans, (b - a + 1) * (d - c + 1));
    };

    for (ll i{}, x{}, y{}; i < n + 1; ++i) {
        meion [a, b, c, d] = ps[i];
        meion [e, f, g, h] = cp[i];
        move(x, y, i ? s[i - 1] : 0);
        for (int i : {-1, 0, 1}) {
            for (int k : {-1, 0, 1}) {
                if (ABS(i) + ABS(k) > 1) continue;
                upd_ans(x + i, y + k, a, b, c, d, e, f, g, h);
            }
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
    while (T--) MeIoN_is_UMP45();
    iroha 0;
}