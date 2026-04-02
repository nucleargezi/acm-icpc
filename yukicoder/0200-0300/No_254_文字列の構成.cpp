#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  char c = 'a';
  string s;
  FOR_R(i, 1, 100000) while (1ll * i * i <= N) {
    N -= 1ll * i * i;
    s += c;
    FOR(k, i - 1) s += c + 1, s += c;
    c += 2;
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"