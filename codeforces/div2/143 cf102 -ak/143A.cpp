#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, aa, b, bb, c, cc);
  FOR(i, 1, 10) FOR(k, 1, 10) FOR(j, 1, 10) FOR(l, 1, 10) {
    if (set<int>({i, k, j, l}).size() != 4) continue;
    if (i + k == a and j + l == aa and i + j == b and k + l == bb and i + l == c and k + j == cc) {
      return print(i, k), print(j, l);
    }
  }
  print(-1);
}

int main() {
  Yorisou();
  return 0;
}