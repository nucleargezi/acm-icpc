#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  FOR(a, N + 1) {
    int b = N - a;
    if (a * (a - 1) / 2 + b * (b - 1) / 2 == K) {
      vc<int> s(N, -1);
      FOR(i, a) s[i] = 1;
      return YES(), print(s);
    }
  }
  NO();
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}