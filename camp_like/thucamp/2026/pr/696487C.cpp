#include "YRS/all.hpp"

using re = long double;

void Yorisou() {
  re x;
  IN(x);
  print(sqrtl(x));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int T = 1;
  // cin >> T;
  FOR(T) Yorisou();
  return 0;
}