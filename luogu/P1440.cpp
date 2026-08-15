#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/swag.hpp"
#include "YRS/al/m/min.hpp"

void Yorisou() {
  INT(N, K);
  swag_queue<Min<int>> q;
  FOR(i, N) {
    INT(x);
    if (si(q) > K) q.pop();
    print(i ? q.prod() : 0);
    q.ep(x);
  }
}

int main() {
  Yorisou();
  return 0;
}