#include "YRS/all.hpp"
#include "YRS/pr/ptable.hpp"

void Yorisou() {
  INT(N, Q);
  vc<int> t = ptable(N);
  FOR(Q) {
    INT(x);
    print(t[x - 1]);
  }
}

int main() {
  Yorisou();
  return 0;
}