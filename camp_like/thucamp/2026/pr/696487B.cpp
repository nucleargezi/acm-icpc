#include "YRS/all.hpp"

void Yorisou() {
  ll a, b;
  IN(a, b);
  print(a + b);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  FOR(T) Yorisou();
  return 0;
}