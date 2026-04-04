#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  STR(s);
  FOR(i, N - 1) if (s[i] == s[i + 1]) return YES();
  FOR(i, N - 3) if (s[i] == s[i + 2] and s[i + 1] == s[i + 3]) return YES();
  NO();
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"