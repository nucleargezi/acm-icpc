#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/SAM.hpp"

void pre_work() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
}
// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    int t, k;
    std::cin >> s >> t >> k;
    const int n = s.length();
    SAM sam;
    vector<int> sz(n << 1);
    for (int pla = 0; const char c : s) {
        pla = sam.ext(pla, c - 'a');
        sz[pla] = 1;
    }
    vector<vector<int>> v(n << 1);
    for (int i = 1; i < sam.size(); ++i) {
        v[sam[i].link].emplace_back(i);
    }
    meion dfs = [&](meion &&se, int n) -> void {
        for (int i : v[n]) {
            se(se, i);
            sz[n] += sz[i];
        }
        if (not t) sz[n] = 1;
    };
    dfs(dfs, 0);
    sz[0] = 0;
    vector<uint8_t> vis(n << 1);
    vector<ll> dp(n << 1);
    meion go = [&](meion &&se, int n) -> void {
        if (vis[n]) iroha;
        vis[n] = 1;
        dp[n] = sz[n];
        for (int i = 0, x; i < 26; ++i) {
            x = sam[n][i];
            if (x == -1) continue;
            se(se, x);
            dp[n] += dp[x];
        }
    };
    go(go, 0);
    int pla = 0;
    if (dp[pla] < k) iroha std::cout << "-1\n", void();
    string ans;
    while (k > 0) {
        for (int i = 0, x; i < 26; ++i) {
            x = sam[pla][i];
            if (x == -1) continue;
            if (k > dp[x]) {
                k -= dp[x];
            } else {
                pla = x;
                k -= sz[pla];
                ans += char('a' + i);
                break;
            }
        }
    }
    std::cout << ans << '\n';
}

// #define MeIoN_File_I
// #define MeIoN_File_O
// #define guidingstar

/* 日々を貪り尽くしてきた
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆⠣⡀⠀⣀⣀⣤⣤⣤⣶⣶⣶⣶⣶⣶⣶⣶⣶⣦⣤⣤⣤⣄⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠤⠤⣄⣀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣠⠋⣸⣷⣤⡀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠋⠉⠉⠛⠓⠦⡀⠈⠢⡀⠀⠀⠀⠀⠀⠀⠀⣀⠤⠐⠂⠉⠉⠉⠉⠁⠒⠂⠤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣠⢁⣼⣿⣿⣿⣿⣦⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠛⠛⠉⠉⠁⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢄⡈⢆⠀⠀⠀⠀⠠⠊⠁⠀⠀⠀⠀⣀⣠⣤⠤⠤⠤⠤⣈⠐⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠈⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠢⣧⠀⠀⡔⠁⠀⠀⠀⣠⣴⡿⠿⠭⠤⣄⡀⠀⠀⠀⠉⢺⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠁⠀⠙⠻⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⠤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⡰⠀⠀⠀⣠⠞⠋⠀⠀⠀⠀⠀⠀⠙⢦⠀⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠋⠙⢄⠀⠀⠀⠀⠀⠀⠈⠳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⠢⠤⢀⣰⡆⣀⣀⣀⠀⢀⡃⠀⠀⡰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢀⣴⣿⣿⣿⣿⡿⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠋⠉⢣⠀⠀⠀⠀⠀⠱⢄⠀⠀⠀⠀⠀⠀⠈⠢⡀⠀⠀⠀⠀⠀⠐⡀⠀⠀⠀⠀⠀⠀⡴⠥⣷⠎⠉⠀⠀⠀⠈⠑⢴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⡟⠁⠀⠀⢠⠃⠀⠀⠀⠀⠀⠈⣹⣿⡿⣿⣿⠿⠟⠛⠋⡟⠁⠀⠀⠀⠀⠀⠀⠱⡀⠀⠀⠀⠀⠈⠳⡀⠀⠀⠀⠀⠀⠀⠈⢢⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⠀⠀⠀⠀⠀⠀⠀⢣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⡌⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢛⢿⣿⣿⠟⠀⠀⠀⢀⠇⠀⡞⠀⠀⠀⠀⠀⣿⠏⠀⠀⠀⠀⠀⠀⢠⠇⠀⠀⠀⠀⠀⠀⠀⠀⠙⡄⠀⠀⠀⠀⠀⠙⣦⡀⠀⠀⠀⠀⠀⠀⡑⡄⠀⠀⠀⠀⢳⠀⠀⠀⠀⢀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣄⡀⠀⠀⠀⠀⠀⠀⠀⣀⠊⠀⠀⠀⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣠⠶⠋⠁⠀⠀⠀⠀⠎⠀⣸⠃⠀⠀⠀⠀⢰⡟⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣄⠀⠀⠀⠀⠀⠘⢿⣦⡀⠀⠀⠀⠀⠘⡌⢆⠀⠀⠀⠈⢏⠉⠁⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⢠⣏⠉⠉⠑⠒⠤⠤⠤⠤⠊⠀⠀⠀⠀⡰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⡰⠀⢠⣿⠀⠀⠀⠀⠀⣿⠃⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡄⠀⠀⠀⠀⠀⠀⠹⣿⣄⠀⠀⠀⠀⠱⡜⣧⡱⠀⠀⠘⡄⠀⠀⠀⠀⠀⠑⠦⣀⡀⠀⢀⣠⣴⢿⢿⣷⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⡠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢠⠃⠀⣾⡇⠀⠀⠀⠀⢠⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡈⢆⠀⠀⠀⠀⠀⠹⣿⣦⡀⠀⠀⠀⢱⠬⣷⣅⠀⠀⢣⠀⠀⠀⠀⠀⠀⠀⣸⡿⠋⠉⠁⡿⠈⢮⢻⡻⠿⣿⣶⣒⡒⠒⠒⠂⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡈⠀⣸⣿⠀⠀⠀⠀⠀⢸⡏⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢧⠸⡄⠀⠀⠀⠀⠀⢹⡄⠉⠇⠂⠤⣀⠃⠘⣿⡄⠀⠈⡆⠀⠀⠀⠀⢠⡾⠋⠀⠀⠀⠀⠇⠀⢸⠧⡝⢦⡀⠀⠀⠀⠉⠐⠒⠂⠀⢀⣀⠲⠖⠊⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⠇⠀⡿⡇⠀⠀⠀⠀⠀⡿⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡆⢱⡀⠀⠀⠀⠀⠀⢳⠀⠸⡄⠀⠀⠉⢢⣸⣿⡀⠀⢸⠀⠀⢀⠴⠋⠀⠀⠀⠀⢀⡸⠀⠀⠈⡇⠈⠲⣌⠲⢄⡀⠀⠉⠉⠭⣉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⠀⠀⡇⡇⠀⠀⠀⠀⠀⡇⡇⠀⠀⠀⠰⠀⠀⠀⠀⢸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠀⣇⠀⠀⠀⠀⠀⠈⡇⠀⠈⠑⠲⢤⣤⣽⡏⢃⠀⠈⡄⠐⠀⠀⠀⠀⠀⠀⠀⣾⠃⠀⠀⠀⢳⠀⠀⠀⠙⠢⣝⡲⢤⣀⣀⠀⠉⠀⠒⠠⠤⠄⠀⠀⢤⠔⠀⠀⠀
⠀⠀⠀⠀⠀⡇⠀⢠⢰⢠⠀⠀⠀⠀⢠⡇⡇⠀⠀⠀⠀⡄⠀⠀⠀⠘⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡆⠸⡄⠀⠀⢸⡀⠀⢻⠀⠀⠀⠀⠀⢫⡩⠵⣮⡆⠀⢱⠐⢄⣀⡀⣀⣀⣀⡾⠃⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠉⠛⠲⠯⣭⡭⠛⠋⠁⢀⣀⠤⠐⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⡇⠀⢸⣸⡘⠀⠀⠀⠀⠀⣧⠃⠀⠀⠀⠀⣇⠀⠀⠀⠀⡟⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢧⠀⣇⠀⠀⢸⡇⠀⠈⡇⠀⣀⠄⠂⠁⠳⣄⠈⢻⠀⠈⡆⠢⢽⣄⢀⣀⡙⢦⡒⠒⠦⢔⡊⠉⠳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⡇⡇⠀⠀⠀⣀⣀⣿⣰⠀⠀⠀⠀⢸⠀⠀⠀⠀⣇⠘⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⣿⠀⠀⢸⣿⠀⣀⣷⠊⠀⠀⠀⠀⠀⠀⠉⠉⡇⡀⣧⣤⣼⠿⢇⡤⠀⠑⣇⠐⠒⢒⣡⣀⣱⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⡀⠀⢸⡇⡇⠀⢯⠭⠭⠵⢶⡞⡇⠀⠀⠀⠈⡇⠀⠀⠀⢸⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⣿⠀⠀⢸⣿⡟⠁⢸⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⣷⢻⡿⠁⠀⠛⠀⠀⠀⠈⣖⢶⣿⣿⡿⠿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⡇⠀⢸⡇⢧⠀⠀⠀⠀⣀⣤⣷⣿⠀⠀⠀⠀⣿⡀⠀⠀⠘⡆⠀⠈⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⡏⠀⠀⠊⡻⢸⠀⣼⠀⠀⣠⣶⣿⣿⣿⣿⣟⢛⠉⡎⡁⠀⠀⠀⠀⠀⠀⠀⣘⠀⠀⠀⠀⠀⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢃⠀⢸⢹⠸⠀⠀⢰⣿⢿⣛⣿⣽⡦⠀⠀⠀⢹⣷⠀⠀⠀⢱⠀⠀⠀⠳⡀⠀⠀⠰⡀⠀⠀⠀⠀⡼⢰⢧⡀⠀⠀⡇⠸⡎⡇⣴⣿⡿⢛⣿⣿⣿⣿⣿⠸⠀⠇⡇⠀⠀⠀⠀⠀⠀⠀⣿⡆⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠸⡀⠈⢸⠀⠇⠀⠀⠰⠟⠋⠉⣧⠹⡄⠀⠀⠸⣿⢳⡒⠉⠙⡍⠉⠉⠉⠛⣆⠀⠀⠘⢦⡀⠀⢠⢧⡟⠀⢳⡀⢠⠃⢠⢣⢳⡿⠛⢶⣿⣿⣿⣿⣿⣿⠃⡏⠀⢡⠀⠀⠀⠀⢀⠇⢸⡏⣿⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢃⠀⡘⡀⢸⠀⠀⠀⠀⠀⠀⠸⡄⢧⠀⠀⠀⣿⠀⠱⡄⠀⠘⡄⠀⠀⠀⠈⠳⡄⠀⠈⠻⡢⣼⣿⠁⠀⠀⠑⣼⠀⢸⡎⠀⠀⠀⠀⠻⢿⣿⣿⣿⠿⠂⢣⠀⢺⠀⠀⠀⠐⠋⣠⣿⠇⢹⡆⠀⠀⠀⠀⠘⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⢆⡇⡇⠀⣆⠀⠀⠀⠀⠀⠀⢳⡈⢧⠀⠀⢸⠀⠀⠈⠢⡀⠙⣄⠀⠀⠒⠒⠨⠳⢄⣀⡼⠫⣙⡦⢄⣀⠀⠈⠳⢯⠁⠀⠀⠀⠀⠀⠈⠉⠁⠀⠀⠀⢸⠀⢸⠀⠀⣾⣐⡴⠟⠉⠀⠀⣧⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠘⣇⢿⡀⢸⡄⠀⠀⠀⠀⠀⠈⢧⠘⢆⠀⠘⡇⠀⠀⠀⠈⠓⠬⣢⡀⠀⠀⠀⠀⠐⠉⠑⠲⢬⠷⣦⣞⡉⠒⠲⠿⠭⠶⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡀⢸⠀⣰⣿⣿⣄⠀⠀⠀⠀⢿⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣸⡼⣗⢺⣿⡛⠛⠛⠛⠲⢦⢸⣧⠈⢆⠀⢱⣄⠀⠀⠀⠀⠀⠀⣉⣑⣢⣤⣤⡤⠀⠀⢠⢇⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⣸⢰⣿⡏⢸⣿⣧⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⢱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⡶⠋⠑⡌⡟⣿⡿⣧⠀⠀⠀⠀⠀⠀⢻⣷⡈⢣⠈⣿⣷⣤⣴⣿⠿⠿⠛⠟⠛⠉⠀⠀⠀⠠⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⣿⢿⣿⡇⣿⣿⣿⣧⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣰⠋⠀⠀⠀⠇⢰⡇⢧⠹⣧⠀⠀⠀⠀⠀⠀⢻⣷⣄⠳⡹⣿⣸⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⡿⠘⣿⣷⣿⣿⣿⣿⣦⠀⠘⣿⡆⠠⡀⠀⠀⠀⠈⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⡀⠠⠁⠀⠀⠀⠀⠸⡘⣇⢸⠀⠘⣷⡀⠀⠀⠀⠀⠀⢻⡎⠢⡙⢿⣿⢿⠙⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⡇⡇⠀⣿⣿⣿⣿⣿⠿⠛⠀⠀⣿⣧⠀⠱⡀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠠⣾⢛⣷⠶⠀⠀⠀⠀⠀⢱⠘⣼⠀⠀⣿⡷⣄⠀⠀⠀⠀⠀⠹⡄⠙⢮⡹⣇⠉⣦⣵⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠂⠀⠀⠀⠀⠀⣠⣾⣦⢁⡇⢰⣿⡟⠋⠉⠀⠀⠀⠀⠀⢸⠈⣇⠀⠘⣆⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣿⠟⠸⠀⠀⠀⠀⠀⠀⣾⣧⢹⡄⢠⡟⣷⡘⢦⡀⠀⠀⠀⠀⠹⡄⠀⠈⠪⣷⢽⠀⠻⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⠐⠀⠀⠀⠀⠀⠀⠀⢀⠔⠁⢸⣿⢸⠀⠸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠸⠀⠘⢆⠀⠈⢷⡀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠁⠀⠀⠀⠀⠀⠀⠀⢰⠛⣿⣇⠹⣼⠃⠹⣷⠀⠙⢦⠀⠀⠀⠀⠙⣄⠀⠀⠈⢹⠿⣦⣈⠑⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠁⠀⠀⠈⡇⣾⠀⠀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠈⢿⣦⡀⠀⠈⢆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡌⠀⠸⣿⣷⡘⢦⡀⠹⡇⠀⠀⢹⣦⡀⠀⠀⠈⢢⡀⠀⢸⠀⠈⠉⠛⠦⣭⡙⠓⠶⢤⠤⣠⣤⣀⣀⣀⣀⣀⣀⣀⡀⠀⣀⠜⠁⠀⠀⠀⠀⢰⢣⣧⡀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠙⢿⣦⡀⠀⠳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⠃⠀⣸⣿⡿⣿⠶⣝⢦⣽⣆⠀⠀⢿⣏⠲⢤⡀⠀⠙⠢⣼⡀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄⠘⣿⡄⠀⠀⢘⣿⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⡼⡘⠋⠳⣄⢸⡀⠀⠀⠀⡆⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠘⣎⠢⣄⠘⢦⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡎⠀⢠⣿⡟⠀⠈⠳⣮⣹⣿⠛⢧⡄⠈⢻⡀⠀⠉⠓⠦⢤⣈⣙⡓⠦⣄⣀⣀⡀⠀⠀⠀⢧⠀⠸⡷⠀⣴⠟⢿⡀⠀⠀⠀⠀⠀⠀⠀⣀⡴⡿⣹⠃⠀⠀⠘⢧⡇⠀⠀⠀⡇⠀⠀⠀⠀⡇⠀⠀⠀⢀⣀⣀⣀⣀⣀⣈⣆⠀⠑⢤⡙⢿⣷⣦⣄⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢰⠀⢠⣿⡟⠀⠀⠀⠀⠈⣿⡟⠀⠀⠙⣦⡀⠱⡄⠀⠀⠀⠀⠀⢻⠉⠉⠉⠉⠉⠁⠀⠀⠀⢸⠀⠀⢱⡞⠁⠀⠀⠉⠓⠶⢤⣄⣀⡠⠞⠁⣰⡿⠁⠀⠀⠀⠀⠨⡇⠀⠀⠀⡇⠀⠀⠀⠀⣿⠁⠈⠉⠁⠀⠀⠀⠀⠀⠀⠉⠳⢄⠀⠈⠲⣿⣿⣿⣿⣶⣤⣀⠀
⠀⠀⠀⠀⠀⠀⢠⢃⠔⣻⡿⠀⠀⠀⠀⠀⢰⣿⠀⡇⠀⢠⣿⣿⠦⣘⢦⡀⠀⠀⠀⠸⡦⠴⠶⠶⠶⠶⠶⠶⠶⠞⠒⠺⣏⠀⠀⠀⠀⠀⠀⢰⡟⠉⠀⠑⣶⣼⠟⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⢠⠁⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠣⡀⠀⠀⠙⠿⣿⣿⡧⠈⠓
⠀⠀⠀⠀⠀⠀⡞⠀⣰⣿⠁⠀⠀⠀⠀⠀⢸⡏⠀⡇⠀⢸⣿⣿⠀⠈⠙⠛⠲⠤⡀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⠀⢠⣏⡀⠀⢠⡴⠟⣷⡀⠀⠀⠀⠀⠀⠀⣸⢇⠀⠀⣸⠀⠀⠀⠀⡀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⠀⠀⠀⠀⠈⠻⢿⡀⠀
⠀⠀⠀⠀⠀⡜⠀⢠⢻⠇⠀⠀⠀⠀⠀⠀⢸⠃⠀⢣⠀⢸⣿⢿⠀⠀⠀⢀⠀⠀⠀⠀⡞⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣷⡀⠀⠀⠀⣿⣿⣿⣦⣀⣀⣴⣿⣷⡄⠀⠀⠀⠀⢠⣿⠈⢦⠀⡇⠀⠀⠀⢸⡇⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⠀⠀⠀⠀⠀⠀⠙⢦
⠀⠀⠀⠀⢰⠀⠠⠃⡞⠀⠀⠀⠀⠀⠀⠀⣾⠀⠀⠈⡆⡿⣿⠘⡇⠀⠀⣨⠀⠀⠀⠀⢷⡹⡀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣧⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⢀⣾⡇⠠⡈⢠⠃⠀⠀⠀⢸⣧⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢠⠃⡠⠃⢀⡇⠀⠀⠀⠀⢀⡄⠀⡇⠀⠀⠀⢸⡇⡏⠀⢧⠀⠀⣿⡆⠀⠀⠀⠘⡗⣝⣄⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣀⣼⣿⣿⣿⣿⡿⠟⠉⢿⣿⣿⣿⣿⣆⢀⣾⣿⠃⠀⢡⡏⠀⠀⠀⠀⢸⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢆⠀⠀⠀⠀⠀⠀
⠀⠀⢀⠆⡰⠁⠀⢸⠁⠀⠀⠀⠀⢸⡇⠀⡇⠀⠀⠀⠀⣧⡇⠀⠸⡀⠀⣿⣷⡀⠀⠀⠀⢹⡀⠙⠳⠦⣄⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⡏⠀⢀⡼⠀⠀⠀⠀⠀⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣦⡀⠀⠀⠀⠀
⠀⠀⡌⡐⠁⠀⠀⡾⠀⠀⠀⠀⠀⢸⢻⠀⣧⠀⠀⠀⠀⣾⡇⠀⠀⡇⠀⢻⣿⣧⠀⠀⠀⠀⢳⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⣀⣀⠀⣼⣿⣿⣿⣿⣿⡿⠀⢀⣾⠃⠀⠀⠀⠀⣰⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡝⢦⡀⠀⠀
⠀⡰⡜⠁⠀⠀⢀⡇⠀⠀⠀⠀⠀⡏⠘⡇⢹⠀⠀⠀⢸⣿⢸⠀⠀⠘⡄⠘⣿⣿⣧⠀⠀⠀⠀⢣⡀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠿⣿⡟⠻⣿⣿⣿⣿⣿⣿⠃⣠⣿⠏⠀⠀⠀⠀⢀⣿⣿⠇⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⣆⡙⠢⡀
⢰⡵⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⢠⠇⠀⢳⡘⡆⠀⢀⠇⢻⡼⡀⠀⠀⠱⡀⠹⡟⣿⣧⡀⠀⠀⠀⠳⡀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⢿⣿⠀⢸⣿⣿⣿⣿⣧⣾⣿⠏⠀⠀⠀⠀⢀⣾⣿⣿⡄⠀⠀⢸⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠤⠒⠉⠀⠀⢳⠀⠈                                                                            */
int main() {
#ifdef guidingstar
    meion start = std::chrono::high_resolution_clock::now();
#endif
#ifdef MeIoN_File_I
    freopen("in","r",stdin);
#endif
#ifdef MeIoN_File_O
    freopen("outt","w",stdout);
#endif
    pre_work();
#ifdef tests
#ifdef fast
    fin >> T;
#else
    std::cin >> T;
#endif
#endif
    while (T--) { MeIoN_is_UMP45(); }
#ifdef guidingstar
    meion end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start; 
    std::cout << "Elapsed time: " << elapsed.count() << "s\n";
#endif
    iroha 0;
}