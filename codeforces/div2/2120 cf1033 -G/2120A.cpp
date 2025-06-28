#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"

#define tests
void Yorisou() {
  LL(l1, b1, l2, b2, l3, b3);
  ll al = l1 * b1 + l2 * b2 + l3 * b3;
  ll sq = std::sqrt(al);
  if (sq * sq != al) iroha NO();
  if (l1 == sq) {
    if (l2 == sq and l3 == sq and b1 + b2 + b3 == sq) iroha YES();
    if (b2 == sq - b1 and b3 == sq - b1 and l2 + l3 == sq) iroha YES();
  }
  if (b1 == sq) {
    if (b2 == sq and b3 == sq and l1 + l2 + l3 == sq) iroha YES();
    if (l2 == sq - l1 and l3 == sq - l1 and b2 + b3 == sq) iroha YES();
  }
  iroha NO();
}
#include "MeIoN_Lib/Z_H/main.hpp"