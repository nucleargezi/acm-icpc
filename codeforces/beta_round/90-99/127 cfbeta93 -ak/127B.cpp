#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  map<int, int> mp;
  FOR(N) {
    INT(x);
    ++mp[x];
  }
  int s = 0;
  for (var [a, b] : mp) s += b >> 1;
  print(s >> 1);
}

int main() {
  Yorisou();
  return 0;
}