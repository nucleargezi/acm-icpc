#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  map<int, ll> mp;
  FOR(N) {
    INT(x);
    ++mp[x];
  }
  ll s = 0;
  for (var [a, b] : mp) {
    if (a < 0) s += b * mp[-a];
    else if (a == 0) s += b * (b - 1) / 2;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}