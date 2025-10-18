#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/pairs/furthest_pair.hpp"

// #define tests
using P = point<ll>;
struct heap {
  min_heap<ll> q;
  int k;

  heap(int N) : k(N) {}

  void add(ll x) {
    q.emplace(x);
    if (len(q) > k) pop(q);
  }
  ll get() const {
    return q.top();
  }
};
void Yorisou() {
  INT(N, K);
  VEC(P, a, N);
  int i, k;
  heap q(K);
  vector<int> I(N);
  iota(all(I), 0);
  FOR(K) {
    vector<P> p;
    for (int x : I) p.emplace_back(a[x]);
    std::tie(i, k) = furthest_pair(p);
    i = I[i], k = I[k];
    vector<int> NI;
    for (int x : I) if (x != i and x != k) NI.emplace_back(x);
    swap(I, NI);
    q.add((a[i] - a[k]).square());
    for (int x : I) {
      q.add((a[i] - a[x]).square());
      q.add((a[k] - a[x]).square());
    }
  }
  UL(q.get());
}
#include "YRS/Z_H/main.hpp"