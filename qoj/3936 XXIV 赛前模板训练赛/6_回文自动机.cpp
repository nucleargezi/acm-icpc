#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/string/pam.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  pam ss(s);
  ll rs = 0;
  for (Z [c, sz] : ss.ke_lps()) chmax(rs, 1ll * c * sz * sz);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}