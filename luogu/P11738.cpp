#include "YRS/all.hpp"
#include "YRS/others/cpp_sim.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  string s((istreambuf_iterator<char>(cin)), {});
  print(cpp_sim(move(s), move(a)).run());
}

int main() { cin.tie(0)->sync_with_stdio(0), Yorisou(); }