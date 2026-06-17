#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/zfunction.hpp"
#include "YRS/string/hs.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  if (N < 3) return print("Just a legend");
  vc<int> z = z_function(s);
  FOR(i, 1, N) if (i + z[i] == N) z[i] -= 1;
  z.erase(bg(z));
  int pr = QMAX(z);
  hash_t hs(s);
  int rs = -1;
  FOR(i, pr) if (hs(0, i + 1) == hs(N - i - 1, N)) rs = i + 1;
  print(rs == -1 ? "Just a legend" : s.substr(0, rs));
}

int main() {
  Yorisou();
  return 0;
}