//! Djikstra's algorithm for finding the shortest path between two nodes in a graph.
//!
//! Given a vector of edges (u, v, w) and a starting node s, Djikstra's algorithm finds the shortest
//! path from s to all other nodes in the graph.
//! u: source node, v: destination node, w: weight of the edge (u, v)

use std::collections::HashMap;

pub fn djikstra(edges: &Vec<(usize, usize, usize)>, s: usize) -> HashMap<usize, usize> {
    let mut distances = HashMap::new();
    let mut visited = HashMap::new();
    let mut queue = vec![s];

    if edges.is_empty() {
        return distances;
    }

    if !edges.iter().any(|(u, _, _)| *u == s) {
        return distances;
    }

    while !queue.is_empty() {
        let node = queue.remove(0);
        if !visited.contains_key(&node) {
            visited.insert(node, true);
            for (u, v, w) in edges {
                if *u == node {
                    let distance = distances.get(&node).unwrap_or(&0) + w;
                    let current_distance = distances.get(&v).unwrap_or(&usize::MAX);
                    if distance < *current_distance {
                        distances.insert(*v, distance);
                    }
                    queue.push(*v);
                }
            }
        }
    }
    distances
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn djikstra_small_graph() {
        let edges = vec![
            (0, 1, 4),
            (0, 2, 1),
            (1, 2, 2),
            (2, 0, 1),
            (2, 3, 5),
            (3, 3, 3),
        ];
        let result = djikstra(&edges, 2);
        let mut expected = HashMap::new();
        expected.insert(0, 1);
        expected.insert(1, 3);
        expected.insert(2, 0);
        expected.insert(3, 5);
        assert_eq!(result, expected);
    }

    #[test]
    fn djikstra_empty_graph() {
        let edges = vec![];
        let result = djikstra(&edges, 0);
        assert_eq!(result, HashMap::new());
    }

    #[test]
    fn djikstra_line() {
        let edges = vec![(0, 1, 1), (1, 2, 1), (2, 3, 1), (3, 4, 1)];
        let result = djikstra(&edges, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 1);
        expected.insert(2, 2);
        expected.insert(3, 3);
        expected.insert(4, 4);
        assert_eq!(result, expected);
    }

    #[test]
    fn djikstra_disconnected() {
        let edges = vec![(0, 1, 1), (1, 2, 1), (3, 4, 1)];
        let result = djikstra(&edges, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 1);
        expected.insert(2, 2);
        assert_eq!(result, expected);
    }
}
