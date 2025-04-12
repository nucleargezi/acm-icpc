#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    REA(a, v, l, d, w);
    RE ans{};
    if (v <= w) {
        RE t_v{v / a}, d_v{0.5L * a * t_v * t_v};
        ans = d_v >= l ? std::sqrt(2.L * l / a) : t_v + (l - d_v) / v;
    } else {
        if (0.5L * a * (w / a) * (w / a) >= d) {
            RE t0{std::sqrt(2.L * d / a)}, t1{a * t0}, t2{l - d},
                t3{(v - t1) / a}, t4{t1 * t3 + 0.5L * a * t3 * t3};
            ans += t0;
            if (t4 <= t2) {
                ans += t3 + (t2 - t4) / v;
            } else {
                RE t5{0.5L * a}, t6{-t2}, t7{t1 * t1 - 4 * t5 * t6};
                ans += (-t1 + std::sqrt(t7)) / (2 * t5);
            }
        } else {
            RE u = std::sqrt((2 * a * d + w * w) / 2.L);
            if (u > v) {
                RE t9{(2 * v * v - w * w) / (2 * a)};
                if (t9 <= d) {
                    RE t10 = (d - t9) / v;
                    ans += (v / a) + t10 + ((v - w) / a);
                } else {
                    u = std::sqrt((2 * a * d + w * w) / 2.L);
                    ans += (u / a) + ((u - w) / a);
                }
            } else {
                ans += (u / a) + ((u - w) / a);
            }
            RE t2{l - d}, t3{(v - w) / a}, t4{w * t3 + 0.5L * a * t3 * t3};
            if (t4 <= t2) {
                ans += t3 + (t2 - t4) / v;
            } else {
                RE t5{0.5L * a}, t6{-t2}, t7{w * w - 4 * t5 * t6};
                ans += (-w + std::sqrt(t7)) / (2 * t5);
            }
        }
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}