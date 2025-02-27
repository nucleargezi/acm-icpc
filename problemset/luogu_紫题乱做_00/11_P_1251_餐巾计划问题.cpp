#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow_min_cost.hpp"

void before() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
}
// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int s = n << 1, t = n << 1 | 1;
    mcf_graph<ll, ll, false> FL(t + 1);
    for (int i = 0, x, y, w; i < n; ++i) {
        std::cin >> w;
        x = i << 1, y = x | 1;
        FL.add(s, x, w, 0);
        FL.add(y, t, w, 0);
    }
    int P, M, G, F, S;
    std::cin >> P >> M >> G >> F >> S;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n) {
            FL.add(i << 1, i + 1 << 1, inf<int>, 0);
        }
        if (i + M < n) {
            FL.add(i << 1, i + M << 1 | 1, inf<int>, G);
        }
        if (i + F < n) {
            FL.add(i << 1, i + F << 1 | 1, inf<int>, S);
        }
        FL.add(s, i << 1 | 1, inf<int>, P);
    }
    std::cout << FL.flow(s, t).second << '\n';
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
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
#ifdef guidingstar
    meion end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start; 
    std::cout << "Elapsed time: " << elapsed.count() << "s\n";
#endif
    iroha 0;
}