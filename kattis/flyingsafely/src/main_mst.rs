#![allow(dead_code)]
mod input {
    use std::{io::BufRead, str::FromStr};

    pub fn get_line_of_integers<T, R>(stdin: &mut R, buffer: &mut String) -> Vec<T>
    where
        T: FromStr,
        <T as FromStr>::Err: std::fmt::Debug,
        R: BufRead,
    {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer
            .split_whitespace()
            .map(|x| x.parse::<T>().expect("Failed to parse integer"))
            .collect()
    }

    pub fn get_line_of_integer<T, R>(stdin: &mut R, buffer: &mut String) -> T
    where
        T: FromStr,
        <T as FromStr>::Err: std::fmt::Debug,
        R: BufRead,
    {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer.trim().parse::<T>().expect("Failed to parse integer")
    }

    pub fn get_line<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer.trim().to_string()
    }
}

pub mod minimal_spanning_tree;
pub mod union_find;

use crate::minimal_spanning_tree::kruskal;
use std::io::BufRead;

use input::*;

fn solve_case(edges: Vec<(usize, usize, usize)>) -> usize {
    let mst = kruskal(&edges);
    mst.cost
}

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let mut result = Vec::new();
    let cases: usize = get_line_of_integer(stdin, buffer);
    for _ in 0..cases {
        let mut edges = Vec::new();
        let n_m: Vec<usize> = get_line_of_integers(stdin, buffer);
        let (_, m) = (n_m[0], n_m[1]);
        for _ in 0..m {
            let u_v: Vec<usize> = get_line_of_integers(stdin, buffer);
            let (u, v) = (u_v[0], u_v[1]);
            edges.push((u - 1, v - 1, 1));
            edges.push((v - 1, u - 1, 1));
        }
        result.push(solve_case(edges).to_string());
    }
    result.join("\n")
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut buffer = String::with_capacity(1024);

    println!("{}", solve(&mut stdin, &mut buffer));
}

#[cfg(test)]
mod tests {
    use super::*;

    fn within_epsilon(a: f64, b: f64) -> bool {
        (a - b).abs() < 1e-6
    }

    #[test]
    fn test_1() {
        let mut stdin = "2\n3 3\n1 2\n2 3\n1 3\n5 4\n2 1\n2 3\n4 3\n4 5\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "2\n4");
    }
}
