#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
void Yorisou() {
  INT(N, M);
  REAL(p);
  int t = round(p * 100);
  map<string, int> mp;
  FOR(N) {
    STR(s);
    INT(x);
    if (x * t / 100 >= 100) mp[s] = x * t / 100;
  }
  FOR(M) {
    STR(s);
    chmax(mp[s], 0);
  }
  print(si(mp));
  for (var [a, b] : mp) print(a, b);
}

int main() {
  Yorisou();
  return 0;
}