#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<int> s(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    ++s[f];
  }
  FOR(i, N) print(s[i]);
}

int main() { Yorisou(); }