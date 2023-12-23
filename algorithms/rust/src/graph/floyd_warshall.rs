//! Floyd Warshall algorithm for finding shortest paths between all pairs of vertices in a graph.

use std::collections::HashMap;

pub fn floyd_warshall(graph: &HashMap<usize, Vec<(usize, usize)>>) -> Vec<Vec<usize>> {
    let mut dist = vec![vec![std::usize::MAX; graph.len()]; graph.len()];

    for (u, edges) in graph.iter() {
        for (v, w) in edges.iter() {
            dist[*u][*v] = *w;
        }
    }

    for i in 0..graph.len() {
        dist[i][i] = 0;
    }

    let num_nodes = graph.len();
    for k in 0..num_nodes {
        for i in 0..num_nodes {
            for j in 0..num_nodes {
                if dist[i][k] == std::usize::MAX || dist[k][j] == std::usize::MAX {
                    continue;
                }

                dist[i][j] = std::cmp::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    dist
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_floyd_warshall_triangle() {
        let mut graph = HashMap::new();
        graph.insert(0, vec![(1, 1), (2, 2)]);
        graph.insert(1, vec![(2, 3)]);
        graph.insert(2, vec![]);
        let result = floyd_warshall(&graph);
        assert_eq!(result[0][0], 0);
        assert_eq!(result[0][1], 1);
        assert_eq!(result[0][2], 2);
        assert_eq!(result[1][0], std::usize::MAX);
        assert_eq!(result[1][1], 0);
        assert_eq!(result[1][2], 3);
        assert_eq!(result[2][0], std::usize::MAX);
        assert_eq!(result[2][1], std::usize::MAX);
        assert_eq!(result[2][2], 0);
    }

    #[test]
    fn test_floyd_warshall_no_edges() {
        let graph = HashMap::new();
        let result = floyd_warshall(&graph);
        assert_eq!(result.len(), 0);
    }
}
