#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  string s;
  FOR(i, N) {
    if (a[i]) {
      while (a[i] > 1) {
        s += 'P';
        --a[i];
        if (i == N - 1) s += "LR";
        else {
          s += 'R';
          if (a[i + 1]) s += 'P', --a[i + 1];
          s += 'L';
        }
      }
      if (a[i]) s += 'P';
    }
    if (i + 1 < N) s += 'R';
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}