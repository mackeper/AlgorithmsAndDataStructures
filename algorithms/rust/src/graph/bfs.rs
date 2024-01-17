//! BFS (Breadth First Search) is a graph traversal algorithm that traverses the graph level by level.
//! Given a vector of edges (u, v) and a starting node s, BFS visits all nodes reachable from s.

use std::collections::{HashMap, HashSet};

pub fn bfs_edges(edges: &Vec<(usize, usize)>, s: usize) -> Vec<usize> {
    let mut edges_map = HashMap::new();
    for (u, v) in edges {
        edges_map.entry(*u).or_insert(vec![]).push(*v);
    }
    bfs(&edges_map, s)
}

pub fn bfs(graph: &HashMap<usize, Vec<usize>>, s: usize) -> Vec<usize> {
    let mut visited = HashSet::new();
    let mut queue = vec![s];
    let mut result = vec![];

    if graph.is_empty() {
        return result;
    }

    if !graph.iter().any(|(u, _)| *u == s) {
        return result;
    }

    while !queue.is_empty() {
        let node = queue.remove(0);
        if !visited.contains(&node) {
            visited.insert(node);
            result.push(node);
            for v in graph.get(&node).unwrap_or(&vec![]).iter() {
                queue.push(*v);
            }
        }
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bfs_small_graph() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![1, 2]);
        graph.insert(1, vec![2]);
        graph.insert(2, vec![0, 3]);
        graph.insert(3, vec![3]);
        let result = bfs(&graph, 2);
        assert_eq!(result, vec![2, 0, 3, 1]);
    }

    #[test]
    fn bfs_empty_graph() {
        let graph = HashMap::new();
        let result = bfs(&graph, 0);
        assert_eq!(result, vec![]);
    }

    #[test]
    fn bfs_disconnected() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![1, 2]);
        graph.insert(1, vec![2]);
        graph.insert(3, vec![4]);
        let result = bfs(&graph, 0);
        assert_eq!(result, vec![0, 1, 2]);
    }

    #[test]
    fn bfs_line() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![1]);
        graph.insert(1, vec![2]);
        graph.insert(2, vec![3]);
        graph.insert(3, vec![4]);
        let result = bfs(&graph, 0);
        assert_eq!(result, vec![0, 1, 2, 3, 4]);
    }

    #[test]
    fn bfs_edges_small_graph() {
        let edges = vec![(0, 1), (0, 2), (1, 2), (2, 0), (2, 3), (3, 3)];
        let result = bfs_edges(&edges, 2);
        assert_eq!(result, vec![2, 0, 3, 1]);
    }

    #[test]
    fn bfs_egdes_empty_graph() {
        let edges = vec![];
        let result = bfs_edges(&edges, 0);
        assert_eq!(result, vec![]);
    }

    #[test]
    fn bfs_edges_line() {
        let edges = vec![(0, 1), (1, 2), (2, 3), (3, 4)];
        let result = bfs_edges(&edges, 0);
        assert_eq!(result, vec![0, 1, 2, 3, 4]);
    }

    #[test]
    fn bfs_edges_disconnected() {
        let edges = vec![(0, 1), (1, 2), (3, 4)];
        let result = bfs_edges(&edges, 0);
        assert_eq!(result, vec![0, 1, 2]);
    }
}
