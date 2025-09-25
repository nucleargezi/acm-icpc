#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/deque.hpp"

// #define tests
struct node {
  // fast_deque<int> q;
  std::deque<int> q;
  bool dir = 1;

  int size() const { return q.size(); }
  bool empty() const { return q.empty(); }

  void reverse() { dir ^= 1; }
  void clear() { q.clear(); }

  void push_back(int x) {
    if (dir) q.push_back(x);
    else q.push_front(x);
  }
  void push_front(int x) {
    if (not dir) q.push_back(x);
    else q.push_front(x);
  }
  
  int pop_front() {
    int ret;
    if (dir) ret = q.front(), q.pop_front();
    else ret = q.back(), q.pop_back();
    return ret;
  }
  int pop_back() {
    int ret;
    if (not dir) ret = q.front(), q.pop_front();
    else ret = q.back(), q.pop_back();
    return ret;
  }
};

void merge(node &a, node &b) {
  if (len(a) < len(b)) {
    while (not a.empty()) b.push_front(a.pop_back());
    swap(a, b);
  } else {
    while (not b.empty()) a.push_back(b.pop_front());
  }
  a.reverse();
  b.clear();
}

int N, M;
void yorisou() {
  vector<node> v(N);
  FOR(i, N) v[i].push_back(i + 1);
  FOR(M) {
    INT(x, y);
    --x, --y;
    merge(v[x], v[y]);
  }
  vector<int> ans;
  while (not v[0].empty()) ans.ep(v[0].pop_front());
  print(len(ans), ans);
}

void Yorisou() {
  while (IN(N, M)) yorisou();
}
#include "YRS/Z_H/main.hpp"