#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/mod/lag.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(N, M);
  FOR(i, M) {
    INT(x, y);
  }
  vector<mint> a{0};
  FOR(i, 1, N) {
    cout << std::format("? {} {} {}", 1, N, i) << endl;
    mint x;
    cin >> x;
    a.ep(x);
  }
  cout << "!" << endl;
  INT(K);
  cout << lagrange_interpolate_iota<mint>(a, K) << endl;
}
#include "YRS/Z_H/main.hpp"