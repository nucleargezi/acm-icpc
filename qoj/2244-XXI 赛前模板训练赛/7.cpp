#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/SA.hpp"

// #define tests
void Yorisou() {
  S(s);
  vector<int> a;
  for (char c : s) a += c - 'a';
  SA sa(a);
  for (int &x : sa.p) ++x;
  print("{}", sa.p);
}
#include "MeIoN_Lib/Z_H/main.hpp"