use std::io::{self, Read, Write};
use std::str::FromStr;

struct SegTree<T> {
  size: usize,
  dat: Vec<T>,
  op: fn(T, T) -> T,
  p: T,
}

impl<T: Copy> SegTree<T> {
  fn new(n: usize, p: T, op: fn(T, T) -> T) -> Self {
    let size = n.next_power_of_two();
    let dat = vec![p; 2 * size];
    SegTree { size, dat, op, p }
  }

  fn apply(&mut self, pos: usize, val: T) {
    let mut idx = pos + self.size;
    self.dat[idx] = val;
    idx /= 2;
    while idx > 0 {
      let left = self.dat[2 * idx];
      let right = self.dat[2 * idx + 1];
      self.dat[idx] = (self.op)(left, right);
      idx /= 2;
    }
  }

  fn prod(&self, mut l: usize, mut r: usize) -> T {
    let mut resl = self.p;
    let mut resr = self.p;
    l += self.size;
    r += self.size;
    while l < r {
      if l & 1 == 1 {
        resl = (self.op)(resl, self.dat[l]);
        l += 1;
      }
      if r & 1 == 1 {
        r -= 1;
        resr = (self.op)(self.dat[r], resr);
      }
      l /= 2;
      r /= 2;
    }
    (self.op)(resl, resr)
  }
}

fn yorisou() {
  let mut sc = Scanner::new();
  let mut out = io::BufWriter::new(io::stdout().lock());

  let n: usize = sc.next();
  let mut a = Vec::new();
  for _ in 0..n {
    let x: ll = sc.next();
    let h: ll = sc.next();
    a.push((x, h));
  }
  let bas = a.iter().map(|&(x, _)| x).min().unwrap();
  for x in &mut a {
    x.0 -= bas;
  }

  let mut f = Vec::new();
  for &(x, h) in &a {
    f.push(x);
    f.push(h + x);
  }
  f.sort_unstable();
  f.dedup();

  let lower = |x: ll| f.binary_search(&x).unwrap();
  let m = f.len();
  let mut seg_max: SegTree<usize> = SegTree::new(m, 0usize, usize::max);
  let mut seg_add: SegTree<usize> = SegTree::new(m, 0usize, |a, b| a + b);
  let mut ii: Vec<usize> = (0..n).collect();
  ii.sort_unstable_by_key(|&i| a[i].0);
  for &i in ii.iter().rev() {
    let (x, h) = a[i];
    let l = lower(x);
    let r = lower(x + h);
    seg_max.apply(l, r);
    seg_max.apply(l, seg_max.prod(l, r));
    seg_add.apply(l, 1);
  }
  for &i in &ii {
    let (x, _) = a[i];
    let p = lower(x);
    seg_add.apply(p, seg_add.prod(p, seg_max.prod(p, p + 1)));
  }
  let mut ans = Vec::new();
  for (x, _) in a {
    let p = lower(x);
    ans.push(seg_add.prod(p, p + 1));
  }
  print_vec(&ans, &mut out);
}
fn main() {
  yorisou();
}

#[allow(warnings)]
type int = i32;
#[allow(warnings)]
type uint = u32;
#[allow(warnings)]
type ll = i64;
#[allow(warnings)]
type ull = u64;

struct Scanner {
  buf: Vec<String>,
  idx: usize,
}
#[allow(dead_code)]
impl Scanner {
  fn new() -> Self {
    // 一次性读入全部 stdin
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let buf = input
      .split_whitespace()
      .map(str::to_string)
      .collect::<Vec<_>>();
    Scanner { buf, idx: 0 }
  }

  fn next<T: FromStr>(&mut self) -> T {
    let s = &self.buf[self.idx];
    self.idx += 1;
    s.parse().ok().expect("parse error")
  }

  fn get_string(&mut self) -> String {
    self.next()
  }
  fn get_chars(&mut self) -> Vec<char> {
    self.next::<String>().chars().collect()
  }

  fn get_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
    (0..n).map(|_| self.next()).collect()
  }
}

#[allow(dead_code)]
fn print_vec<T: ToString, W: Write>(v: &[T], out: &mut W) {
  let s = v
    .iter()
    .map(|x| x.to_string())
    .collect::<Vec<_>>()
    .join(" ");
  writeln!(out, "{}", s).unwrap();
}
