#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(14);
}
// #define tests
NAME MeIoN_is_UMP45() {
    ll n, d, x, y;
    std::cin >> n >> d >> x >> y;
    x = std::abs(x), y = std::abs(y);

    if (x % d or y % d) iroha std::cout << "0\n", void();

    x /= d, y /= d;
    if ((n & 1) != (x + y & 1) or n < (x + y)) iroha std::cout << "0\n", void();
    
    using RE = long double;
    RE ans = 1;
    ll a = (n + x + y) >> 1;
    ll b = (n + std::abs(x - y)) >> 1;
    for (int i = a; i--; ) {
        ans *= RE(1) * (n - i) / (i + 1);
    }
    for (int i = b; i--; ) {
        ans *= RE(1) * (n - i) / (i + 1);
    }
    for (int i = n; i--; ) {
        ans /= 4;
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