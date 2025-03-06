#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
pair<vector<vector<int>>, int> ans[14];
bitset<13> mp[13], pm[13], vis;
void naive_solution(int n) {
    int cnt{};
    vector<vector<int>> cons;
    vector<int> LX(n << 1), RX(n << 1);
    meion dfs = [&](meion &dfs, int x) -> void {
        if (x == n) {
            if (cnt++ < 3) {
                cons.emplace_back();
                for (int i{}; i < n; ++i) {
                    for (int k{}; k < n; ++k) {
                        if (mp[i][k]) {
                            cons.back().emplace_back(k + 1);
                        }
                    }
                }
            }
        } else {
            for (int i{}; i < n; ++i) {
                if (vis[i]) continue;
                mp[x][i] = 1;
                ++LX[x + i];
                ++RX[x + n - i - 1];
                vis[i] = 1;
                if (LX[x + i] < 2 and RX[x + n - i - 1] < 2) {
                    dfs(dfs, x + 1);
                }
                mp[x][i] = 0;
                --LX[x + i];
                --RX[x + n - i - 1];
                vis[i] = 0;
            }
        }
    };
    dfs(dfs, 0);
    ans[n] = {cons, cnt};
    
    // print table

    // std::cout << std::format("ans[{}] = ", n);
    // std::cout << "{{";
    // for (bool ok = true; meion &v : cons) {
    //     if (ok) ok = false;
    //     else std::cout << ", ";
    //     std::cout << "{";
    //     std::cout << v[0];
    //     for (int i{1}; i < n; ++i) {
    //         std::cout << ", " << v[i];
    //     }
    //     std::cout << "}";
    // }
    // std::cout << "}, " << cnt;
    // std::cout << "};\n";
}
NAME MeIoN_is_UMP45() {
    for (int i{6}; i < 14; ++i) {
        naive_solution(i);
    }
    int n;
    std::cin >> n;
    meion [v, cnt] = ans[n];
    for (meion s : v) {
        std::cout << s << '\n';
    }
    std::cout << cnt << '\n';
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