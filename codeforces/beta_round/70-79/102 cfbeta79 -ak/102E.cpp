#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/f/line_sol22.hpp"

void Yorisou() {
  LL(a, aa, b, bb, c, cc);
  FOR(4) {
    swap(a, aa), a = -a;
    FOR(4) {
      swap(c, cc), c = -c;
      if (line_sol22(c, -cc, b - a, cc, c, bb - aa)) return YES();
    }
  }
  NO();
}

int main() {
  Yorisou();
  return 0;
}