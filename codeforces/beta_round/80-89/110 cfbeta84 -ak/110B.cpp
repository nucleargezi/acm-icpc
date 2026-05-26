#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  string s(N, 'a');
  FOR(i, N) s[i] += i & 3;
  print(s);
}

int main() {
  Yorisou();
  return 0;
}