mod input {
    use std::io::BufRead;

    pub fn get_line_of_integers<R: BufRead>(stdin: &mut R, buffer: &mut String) -> Vec<i32> {
        buffer.clear();
        stdin.read_line(buffer).unwrap();
        buffer
            .split_whitespace()
            .map(|x| x.parse::<i32>().unwrap())
            .collect()
    }

    pub fn get_line<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer.trim().to_string()
    }
}

use std::collections::{HashMap, HashSet, LinkedList};

use input::*;

pub fn bfs(edges: &HashMap<i32, Vec<i32>>, start: i32, stop: i32) -> (i32, bool) {
    let mut visited = HashSet::with_capacity(edges.len() * 2);
    let mut queue = LinkedList::new();
    queue.push_back((start, 0));

    if edges.is_empty() {
        return (0, false);
    }

    if !edges.iter().any(|(u, _)| *u == start) {
        return (0, false);
    }

    while !queue.is_empty() {
        let (node, depth) = queue.pop_front().unwrap();
        if !visited.contains(&node) {
            visited.insert(node);
            if node == stop {
                return (depth, true);
            }
            edges.get(&node).unwrap().iter().for_each(|v| {
                queue.push_back((*v, depth + 1));
            });
        }
    }
    (0, false)
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut buffer = String::with_capacity(1024);

    let line = get_line_of_integers(&mut stdin, &mut buffer);
    let n = line[0] as i32;
    let m = line[1] as i32;

    let mut edges = HashMap::with_capacity(n as usize * m as usize);
    for row in 0..n {
        let line = get_line(&mut stdin, &mut buffer);
        for col in 0..m {
            let i = col as usize;
            let value = line.chars().nth(i).unwrap().to_digit(10).unwrap() as i32;
            let current = row * m + col;
            if edges.get(&current).is_none() {
                edges.insert(current, Vec::new());
            }

            if row - value >= 0 {
                // Above
                edges.get_mut(&current).unwrap().push(current - (m * value));
            }
            if row + value < n {
                // Below
                edges.get_mut(&current).unwrap().push(current + (m * value));
            }
            if col - value >= 0 {
                // Left
                edges.get_mut(&current).unwrap().push(current - value);
            }
            if col + value < m {
                // Right
                edges.get_mut(&current).unwrap().push(current + value);
            }
        }
    }

    let result = bfs(&edges, 0, n * m - 1);

    if !result.1 {
        println!("-1");
    } else {
        println!("{}", result.0);
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn test_bfs() {
        let mut edges = std::collections::HashMap::new();
        edges.insert(0, vec![1]);
        edges.insert(1, vec![2]);
        edges.insert(2, vec![3]);
        edges.insert(3, vec![4]);
        assert_eq!(super::bfs(&edges, 0, 4), (4, true));
        assert_eq!(super::bfs(&edges, 0, 3), (3, true));
        assert_eq!(super::bfs(&edges, 0, 2), (2, true));
        assert_eq!(super::bfs(&edges, 0, 1), (1, true));
        assert_eq!(super::bfs(&edges, 0, 0), (0, true));
        assert_eq!(super::bfs(&edges, 0, 5), (0, false));
        assert_eq!(super::bfs(&edges, 0, 6), (0, false));
        assert_eq!(super::bfs(&edges, 0, 7), (0, false));
        assert_eq!(super::bfs(&edges, 0, 8), (0, false));
        assert_eq!(super::bfs(&edges, 0, 9), (0, false));
    }
}
