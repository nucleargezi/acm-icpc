use std::io::{self, Read};
use std::str::FromStr;

fn yorisou() {
  let mut sc = Scanner::new();

  let n: usize = sc.next();
  let mut a: Vec<usize> = sc.get_vec(n);
  for x in &mut a {
    *x -= 1;
  }
  let mut b = Vec::new();
  for i in 0..n {
    if a[i] != i {
      b.push(i);
    }
  }
  if b.is_empty() {
    println!("{} {}", 0, 0);
    return;
  }
  let l = b[0];
  let r = b[b.len() - 1];
  a[l..=r].reverse();
  for i in 0..n {
    if a[i] != i {
      println!("{} {}", 0, 0);
      return;
    }
  }
  println!("{} {}", l + 1, r + 1);
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
  buffer: Vec<String>,
}
#[allow(dead_code)]
impl Scanner {
  fn new() -> Self {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let buffer = input
      .split_whitespace()
      .map(str::to_string)
      .collect::<Vec<_>>();
    Self { buffer }
  }

  fn next<T: FromStr>(&mut self) -> T {
    self
      .buffer
      .remove(0)
      .parse::<T>()
      .ok()
      .expect("Failed parse")
  }

  fn get_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
    (0..n).map(|_| self.next()).collect()
  }

  fn get_line(&mut self) -> String {
    self.buffer.remove(0).to_string()
  }

  fn get_char(&mut self) -> char {
    self.next::<String>().chars().next().unwrap()
  }

  fn get_pair<T: FromStr, U: FromStr>(&mut self) -> (T, U) {
    (self.next(), self.next())
  }
}
