#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
}
// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<tuple<int, int, int>> a(n);
    std::cin >> a;
    int x{}, y{}, t{};
    for (meion [pt, px, py] : a) {
        int dis = std::abs(px - x) + std::abs(py - y);
        if (dis > pt - t or dis - pt + t & 1) iroha No();
        std::tie(x, y, t) = {px, py, pt}; 
    }
    Yes();
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