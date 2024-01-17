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

use std::{
    collections::{HashMap, LinkedList},
    io::BufRead,
};

use input::*;

fn solve_case(graph: &HashMap<usize, Vec<usize>>) -> usize {
    let mut visited = vec![false; graph.len()];
    let mut queue = LinkedList::new();
    queue.push_back(0);
    let mut count = 0;

    while let Some(node) = queue.pop_front() {
        if visited[node] {
            continue;
        }
        visited[node] = true;
        count += 1;
        for &neighbor in graph.get(&node).unwrap() {
            queue.push_back(neighbor);
        }
    }

    count - 1
}

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) {
    let cases: usize = get_line_of_integer(stdin, buffer);
    for _ in 0..cases {
        let mut graph = HashMap::new();
        let n_m: Vec<usize> = get_line_of_integers(stdin, buffer);
        let (_, m) = (n_m[0], n_m[1]);
        for _ in 0..m {
            let u_v: Vec<usize> = get_line_of_integers(stdin, buffer);
            let (u, v) = (u_v[0], u_v[1]);
            graph.entry(u - 1).or_insert(Vec::new()).push(v - 1);
            graph.entry(v - 1).or_insert(Vec::new()).push(u - 1);
        }
        println!("{}", solve_case(&graph));
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut buffer = String::with_capacity(1024);

    solve(&mut stdin, &mut buffer);
}
