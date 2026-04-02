#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    using RE = long double;
    constexpr RE eps = 1e-8;
    vector<point<RE>> ps(n);
    std::cin >> ps;
    sort(ps);
    vector<RE> angles;
    angles.push_back(0);
    for (int i{}; i < n; ++i) {
        for (int k {i + 1}; k < n; ++k) {
            meion ang = (ps[i] - ps[k]).angle();
            for (int i{}; i < 4; ++i) {
                ang += pi / 2;
                if (ang > pi * 2 + eps) ang -= pi * 2;
                angles.emplace_back(ang + eps);
                angles.emplace_back(ang - eps);
            }
            ang = pi * 2 - ang;
            for (int i{}; i < 4; ++i) {
                ang += pi / 2;
                if (ang > pi * 2 + eps) ang -= pi * 2;
                angles.emplace_back(ang + eps);
                angles.emplace_back(ang - eps);
            }
        }
    }
    meion go = [&](const vector<RE> &ys) {
        vector<int> dp(50);
        dp[0] = 1;
        int res{1};
        for (int i{1}; i < len(ys); i++) {
            dp[i] = 0;
            for (int k{}; k < i; k++) {
                if (ys[k] < ys[i] + 1e-4) {
                    chmax(dp[i], dp[k]);
                }
            }
            chmax(res, ++dp[i]);
        }
        iroha res;
    };
    int ans{};
    for (RE ang : angles) {
        vector rps(ps);
        vector<point<RE>> ok;
        for (meion& p : rps) {
            p = p.rotate(ang);
            if (p.x > -1e-4 and p.y > -1e-4) ok.emplace_back(p);
        }
        sort(ok);
        vector<RE> ys;
        for (meion[x, y] : ok) ys.emplace_back(y);
        chmax(ans, go(ys));
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