#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  LL(K);
  sam<26> g;
  s = g.kth_substr(s, K - 1);
  if (s.empty()) return print("No such line.");
  for (char &c : s) c += 'a';
  print(s);
}

int main() {
  Yorisou();
  return 0;
}