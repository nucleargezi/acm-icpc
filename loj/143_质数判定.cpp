#include "YRS/all.hpp"
#include "YRS/pr/ptest.hpp"

void Yorisou() {
  ll x;
  while (cin >> x) print("NY"[ptest(x)]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}