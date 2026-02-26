#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/ds/basic/node_pool.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr int lg = 14;
constexpr int B = 1 << lg;
struct BS {
  alignas(64) ull a[B / 64];
  BS() { memset(a, 0, sizeof a); }
  inline bool test(int x) const { return a[x / 64] >> (x & 63) & 1; }
  inline void set(int x) { a[x / 64] |= 1ull << (x & 63); }
};
using np = BS*;
node_pool_sim<BS, 1 << 12> pool;
np none_bit = pool.gen();

constexpr int Asz = 32;

struct bs {
  u16 cnt = 0;
  u8 sz = 0;
  bool op = 0; 
  u16 se[Asz];
  BS* bit = nullptr;

  void move() {
    op = 1;
    bit = pool.gen();
    FOR(i, sz) bit->set(se[i]);
  }

  inline void add(u16 x) {
    cnt++;
    if (not op) {
      int i = sz - 1;
      while (i >= 0 and se[i] > x) {
        se[i + 1] = se[i];
        i--;
      }
      se[i + 1] = x;
      sz++;
      if (sz == Asz) move();
    } else {
      bit->set(x);
    }
  }
};

inline int AND(const np x, const np y) {
  const ull* __restrict px = x->a;
  const ull* __restrict py = y->a;
  int s = 0;
  for (int i = 0; i < B / 64; i += 4) {
    s += __builtin_popcountll(px[i] & py[i]);
    s += __builtin_popcountll(px[i + 1] & py[i + 1]);
    s += __builtin_popcountll(px[i + 2] & py[i + 2]);
    s += __builtin_popcountll(px[i + 3] & py[i + 3]);
  }
  return s;
}

inline int ke(bs &a, bs &b) {
  if (not a.op and not b.op) {
    int i = 0, k = 0, s = 0;
    while (i < a.sz and k < b.sz) {
      if (a.se[i] == b.se[k]) s++, i++, k++;
      else if (a.se[i] < b.se[k]) i++;
      else k++;
    }
    return s;
  }
  if (a.op and b.op) return AND(a.bit, b.bit);
  const bs& X = a.op ? b : a;
  const bs& Y = a.op ? a : b;
  int s = 0;
  FOR(i, X.sz) if (Y.bit->test(X.se[i])) s++;
  return s;
}

struct dat {
  u16 id;
  bs d;
};

struct DS {
  int sm = 0;
  vector<dat> g;

  inline void add(int x) {
    sm++;
    u16 id = x >> lg;
    u16 e = x & (B - 1);

    if (g.empty() or id > g.back().id) {
      g.push_back({id, {}});
      g.back().d.add(e);
      return;
    }
    int sz = len(g);
    FOR(i, sz) {
      if (g[i].id == id) {
        g[i].d.add(e);
        return;
      }
      if (g[i].id > id) {
        g.insert(g.begin() + i, {id, {}});
        g[i].d.add(e);
        return;
      }
    }
  }
};

inline int ke(DS &a, DS &b) {
  if (&a == &b) return a.sm;
  int s = 0, i = 0, k = 0;
  int N = len(a.g), M = len(b.g);
  while (i < N and k < M) {
    if (a.g[i].id == b.g[k].id) {
      s += ke(a.g[i].d, b.g[k].d);
      i++, k++;
    } else if (a.g[i].id < b.g[k].id)
      i++;
    else
      k++;
  }
  return a.sm + b.sm - s;
}
#ifdef VIEW
constexpr int tsz = 10;
#else
constexpr int tsz = 1'000'000;
#endif

DS q[tsz];

void Yorisou() {
  INT(Q);
  VEC(T3<int>, ops, Q);
  vc<int> f;
  for (Z &[op, x, y] : ops) {
    --x, --y;
    if (op == 1) f.ep(y);
  }
  unique(f);
  for (Z &[op, x, y] : ops) {
    if (op == 1) y = lb(f, y);
  }
  iota(all(f), 0);
  shuffle(f);
  for (Z [op, x, y] : ops) {
    if (op == 1) {
      y = f[y];
      q[x].add(y);
    } else {
      print(ke(q[x], q[y]));
    }
  }
}
#include "YRS/aa/main.hpp"