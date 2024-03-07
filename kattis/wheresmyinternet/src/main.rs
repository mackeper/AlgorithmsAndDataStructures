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

    pub fn get_line<R: BufRead>(stdin: &mut R, buffer: &mut String) {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
    }
}

use std::io::{BufRead, Write};

use input::*;

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String, stdout: &mut impl Write) {
    let n_m: Vec<usize> = get_line_of_integers(stdin, buffer);
    let (n, m) = (n_m[0], n_m[1]);

    // Build the graph
    let mut graph = vec![Vec::<usize>::new(); n];
    for _ in 0..m {
        let edge: Vec<usize> = get_line_of_integers(stdin, buffer);
        let (a, b) = (edge[0] - 1, edge[1] - 1);
        graph[a].push(b);
        graph[b].push(a);
    }

    // DFS
    let mut visited = vec![false; n];
    let mut stack = vec![0];
    while let Some(node) = stack.pop() {
        if visited[node] {
            continue;
        }
        visited[node] = true;
        for &neighbour in &graph[node] {
            stack.push(neighbour);
        }
    }

    // Find the unvisited nodes
    let mut any_unvisited = false;
    for (i, &x) in visited.iter().enumerate() {
        if !x {
            writeln!(stdout, "{}", i + 1).unwrap();
            any_unvisited = true;
        }
    }

    // Return Connected if all nodes are visited
    if !any_unvisited {
        writeln!(stdout, "Connected").unwrap();
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut in_buffer = String::with_capacity(1024);

    let stdout = std::io::stdout();
    let lock = stdout.lock();
    let mut out_buffer = std::io::BufWriter::new(lock);

    solve(&mut stdin, &mut in_buffer, &mut out_buffer);
}

// #[cfg(test)]
// mod tests {
//     use super::*;
//
//     fn within_epsilon(a: f64, b: f64) -> bool {
//         (a - b).abs() < 1e-6
//     }
//
//     #[test]
//     fn test_1() {
//         let mut stdin = "6 4\n1 2\n2 3\n3 4\n5 6".as_bytes();
//         let mut buffer = String::with_capacity(1024);
//         assert_eq!(solve(&mut stdin, &mut buffer).trim(), "5\n6");
//     }
//
//     #[test]
//     fn test_2() {
//         let mut stdin = "2 1\n2 1".as_bytes();
//         let mut buffer = String::with_capacity(1024);
//         assert_eq!(solve(&mut stdin, &mut buffer).trim(), "Connected");
//     }
//
//     #[test]
//     fn test_3() {
//         let mut stdin = "4 3\n2 3\n4 2\n3 4".as_bytes();
//         let mut buffer = String::with_capacity(1024);
//         assert_eq!(solve(&mut stdin, &mut buffer).trim(), "2\n3\n4");
//     }
// }
