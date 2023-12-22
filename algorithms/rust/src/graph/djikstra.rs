//! Djikstra's algorithm for finding the shortest path between two nodes in a graph.
//!
//! Given a vector of edges (u, v, w) and a starting node s, Djikstra's algorithm finds the shortest
//! path from s to all other nodes in the graph.
//! u: source node, v: destination node, w: weight of the edge (u, v)

use std::collections::{HashMap, HashSet};

pub fn djikstra(graph: &HashMap<usize, Vec<(usize, usize)>>, s: usize) -> HashMap<usize, usize> {
    let mut distances = HashMap::new();
    distances.insert(s, 0);
    let mut visited = HashSet::new();
    let mut queue = vec![s];

    while !queue.is_empty() {
        let node = queue.remove(0);
        if !visited.contains(&node) {
            visited.insert(node);
            for (v, w) in graph.get(&node).unwrap_or(&vec![]).iter() {
                let distance = distances.get(&node).unwrap_or(&0) + w;
                let current_distance = distances.get(v).unwrap_or(&usize::MAX);
                if distance < *current_distance {
                    distances.insert(*v, distance);
                }
                queue.push(*v);
            }
        }
    }

    distances
}

pub fn djikstra_edges(edges: &Vec<(usize, usize, usize)>, s: usize) -> HashMap<usize, usize> {
    let mut graph = HashMap::new();
    for (u, v, w) in edges {
        graph.entry(*u).or_insert(vec![]).push((*v, *w));
    }
    djikstra(&graph, s)
    
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn djikstra_small_graph() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![(1, 4), (2, 1)]);
        graph.insert(1, vec![(2, 2)]);
        graph.insert(2, vec![(0, 1), (3, 5)]);
        graph.insert(3, vec![(3, 3)]);
        let result = djikstra(&graph, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 4);
        expected.insert(2, 1);
        expected.insert(3, 6);
        assert_eq!(expected, result);
    }

    #[test]
    fn djikstra_empty_graph() {
        let graph = HashMap::new();
        let result = djikstra(&graph, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        assert_eq!(result, expected);
    }

    #[test]
    fn djikstra_line() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![(1, 1)]);
        graph.insert(1, vec![(2, 1)]);
        graph.insert(2, vec![(3, 1)]);
        graph.insert(3, vec![(4, 1)]);
        let result = djikstra(&graph, 0);
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
        let mut graph = HashMap::new();
        graph.insert(0, vec![(1, 1)]);
        graph.insert(1, vec![(2, 1)]);
        graph.insert(3, vec![(4, 1)]);
        let result = djikstra(&graph, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 1);
        expected.insert(2, 2);
        assert_eq!(result, expected);
    }

    #[test]
    fn djikstra_edges_small_graph() {
        let edges = vec![
            (0, 1, 4),
            (0, 2, 1),
            (1, 2, 2),
            (2, 0, 1),
            (2, 3, 5),
            (3, 3, 3),
        ];
        let result = djikstra_edges(&edges, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 4);
        expected.insert(2, 1);
        expected.insert(3, 6);
        assert_eq!(result, expected);
    }
}
