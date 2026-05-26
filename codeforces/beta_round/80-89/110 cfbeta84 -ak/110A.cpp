#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

bool ok(ll x) {
  if (x == 0) return 0;
  for (; x; x /= 10) if (x % 10 != 4 and x % 10 != 7) return 0;
  return 1;
}
void Yorisou() {
  STR(s);
  ll x = 0;
  for (char c : s) x += (c == '4' or c == '7');
  YES(ok(x));
}

int main() {
  Yorisou();
  return 0;
}