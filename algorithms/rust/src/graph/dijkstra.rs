//! dijkstra's algorithm for finding the shortest path between two nodes in a graph.
//!
//! Given a vector of edges (u, v, w) and a starting node s, dijkstra's algorithm finds the shortest
//! path from s to all other nodes in the graph.
//! u: source node, v: destination node, w: weight of the edge (u, v)

use std::{
    cmp::Reverse,
    collections::{BinaryHeap, HashMap},
};

pub fn dijkstra(graph: &HashMap<usize, Vec<(usize, usize)>>, s: usize) -> HashMap<usize, usize> {
    if graph.is_empty() {
        return HashMap::new();
    }

    let mut distances = HashMap::new();
    distances.insert(s, 0);
    let mut visited = vec![false; graph.len()];
    let mut queue = BinaryHeap::new();
    queue.push(Reverse((0, s)));

    while !queue.is_empty() {
        let node = queue.pop().unwrap().0 .1;

        if visited[node] {
            continue;
        }

        visited[node] = true;

        for (v, w) in graph.get(&node).unwrap_or(&vec![]).iter() {
            let new_distance = distances.get(&node).unwrap_or(&usize::MAX) + w;
            let current_distance = distances.get(v).unwrap_or(&usize::MAX);

            if new_distance < *current_distance {
                distances.insert(*v, new_distance);
                queue.push(Reverse((new_distance, *v)));
            }
        }
    }

    distances
}

pub fn dijkstra_edges(edges: &Vec<(usize, usize, usize)>, s: usize) -> HashMap<usize, usize> {
    let mut graph = HashMap::new();
    for (u, v, w) in edges {
        graph.entry(*u).or_insert(vec![]).push((*v, *w));
    }
    dijkstra(&graph, s)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn dijkstra_small_graph() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![(1, 4), (2, 1)]);
        graph.insert(1, vec![(2, 2)]);
        graph.insert(2, vec![(0, 1), (3, 5)]);
        graph.insert(3, vec![(3, 3)]);
        let result = dijkstra(&graph, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 4);
        expected.insert(2, 1);
        expected.insert(3, 6);
        assert_eq!(expected, result);
    }

    #[test]
    fn dijkstra_longer_path_is_shorter() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![(1, 10), (2, 1)]);
        graph.insert(1, vec![]);
        graph.insert(2, vec![(3, 1)]);
        graph.insert(3, vec![(4, 1)]);
        graph.insert(4, vec![(1, 1)]);
        let result = dijkstra(&graph, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 4);
        expected.insert(2, 1);
        expected.insert(3, 2);
        expected.insert(4, 3);
        assert_eq!(result, expected);
    }

    #[test]
    fn dijkstra_test() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![(4, 401), (3, 14), (1, 896)]);
        graph.insert(1, vec![(2, 854)]);
        graph.insert(2, vec![(4, 66)]);
        graph.insert(3, vec![(0, 451), (2, 27)]);
        graph.insert(4, vec![(1, 145), (3, 813)]);
        let result = dijkstra(&graph, 3);
        let mut expected = HashMap::new();
        expected.insert(0, 451);
        expected.insert(1, 238);
        expected.insert(2, 27);
        expected.insert(3, 0);
        expected.insert(4, 93);
        assert_eq!(result, expected);
    }

    #[test]
    fn dijkstra_empty_graph() {
        let graph = HashMap::new();
        let result = dijkstra(&graph, 0);
        let expected = HashMap::new();
        assert_eq!(result, expected);
    }

    #[test]
    fn dijkstra_line() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![(1, 1)]);
        graph.insert(1, vec![(2, 1)]);
        graph.insert(2, vec![(3, 1)]);
        graph.insert(3, vec![(4, 1)]);
        graph.insert(4, vec![]);
        let result = dijkstra(&graph, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 1);
        expected.insert(2, 2);
        expected.insert(3, 3);
        expected.insert(4, 4);
        assert_eq!(result, expected);
    }

    #[test]
    fn dijkstra_disconnected() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![(1, 1)]);
        graph.insert(1, vec![(2, 1)]);
        graph.insert(3, vec![(4, 1)]);
        let result = dijkstra(&graph, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 1);
        expected.insert(2, 2);
        assert_eq!(result, expected);
    }

    #[test]
    fn dijkstra_edges_small_graph() {
        let edges = vec![
            (0, 1, 4),
            (0, 2, 1),
            (1, 2, 2),
            (2, 0, 1),
            (2, 3, 5),
            (3, 3, 3),
        ];
        let result = dijkstra_edges(&edges, 0);
        let mut expected = HashMap::new();
        expected.insert(0, 0);
        expected.insert(1, 4);
        expected.insert(2, 1);
        expected.insert(3, 6);
        assert_eq!(result, expected);
    }
}
