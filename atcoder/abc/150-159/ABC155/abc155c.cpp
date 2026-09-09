#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  map<string, int> mp;
  int mx = 0;
  FOR(N) {
    STR(s);
    chmax(mx, ++mp[s]);
  }
  for (var [s, c] : mp) if (c == mx) print(s);
}

int main() { Yorisou(); }