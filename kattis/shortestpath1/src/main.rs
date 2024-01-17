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

mod dijkstra;

use std::{collections::HashMap, io::BufRead};

use input::*;

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let mut result = Vec::new();
    loop {
        let n_m_q_s: Vec<usize> = get_line_of_integers(stdin, buffer);
        let (n, m, q, s) = (n_m_q_s[0], n_m_q_s[1], n_m_q_s[2], n_m_q_s[3]);
        if n == 0 && m == 0 && q == 0 && s == 0 {
            break;
        }

        let mut graph = HashMap::new();
        for i in 0..n {
            graph.insert(i, vec![]);
        }

        for _ in 0..m {
            let u_v_w: Vec<usize> = get_line_of_integers(stdin, buffer);
            let (u, v, w) = (u_v_w[0], u_v_w[1], u_v_w[2]);
            graph.entry(u).or_insert(vec![]).push((v, w));
        }

        let distances = dijkstra::dijkstra(&graph, s);
        for _ in 0..q {
            let query: usize = get_line_of_integer(stdin, buffer);
            let distance = distances.get(&query);
            match distance {
                Some(distance) => {
                    result.push(distance.to_string());
                    println!("{}", distance);
                }
                None => {
                    result.push("Impossible".to_string());
                    println!("Impossible");
                }
            }
        }
    }

    result.join("\n")
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut buffer = String::with_capacity(1024);

    let _ = solve(&mut stdin, &mut buffer);
}

#[cfg(test)]
mod tests {
    use super::*;

    fn within_epsilon(a: f64, b: f64) -> bool {
        (a - b).abs() < 1e-6
    }

    #[test]
    fn test_1() {
        let mut stdin =
            "4 3 4 0\n0 1 2\n1 2 2\n3 0 2\n0\n1\n2\n3\n2 1 1 0\n0 1 100\n1\n0 0 0 0\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "0\n2\n4\nImpossible\n100";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_2() {
        let mut stdin = "0 0 0 0\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_3() {
        let mut stdin = "1 0 0 0\n0 0 0 0".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_4() {
        let mut stdin = "1 1 1 0\n0 0 0\n0\n0 0 0 0".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "0";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_5() {
        let mut stdin = "1 1 1 0\n0 0 0\n1\n0 0 0 0".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "Impossible";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_6() {
        let mut stdin = "2 3 1 0\n0 1 10\n0 1 5\n0 1 2\n1\n0 0 0 0".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "2";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_7() {
        let mut stdin = "5 4 3 0\n0 1 10\n1 2 30\n0 1 5\n0 1 2\n1\n2\n4\n0 0 0 0".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "2\n32\nImpossible";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_8() {
        let input = vec![
            "5 5 5 0", "0 1 10", "0 2 1", "2 3 1", "3 4 1", "4 1 1", "0", "1", "2", "3", "4",
            "0 0 0 0",
        ];
        let stdin = input.join("\n");
        let mut stdin = stdin.as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "0\n4\n1\n2\n3";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_no_edges() {
        let mut stdin = "5 0 5 0\n0\n1\n2\n3\n4\n0 0 0 0".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "0\nImpossible\nImpossible\nImpossible\nImpossible";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }

    #[test]
    fn test_q_outside_n() {
        let mut stdin = "1 0 1 0\n5\n0 0 0 0".as_bytes();
        let mut buffer = String::with_capacity(1024);
        let expected = "Impossible";
        assert_eq!(solve(&mut stdin, &mut buffer), expected);
    }
}
