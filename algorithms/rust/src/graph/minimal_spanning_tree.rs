//! Minimal spanning tree algorithms.
use crate::datastructures::union_find::UnionFind;

/// Kruskal's algorithm for finding the minimal spanning tree of a graph.
pub fn kruskal(edges: &Vec<(usize, usize, usize)>) -> (Vec<(usize, usize, usize)>, usize) {
    let mut edges = edges.clone();
    edges.sort_by(|a, b| a.0.cmp(&b.0));
    let mut union_find = UnionFind::new(edges.len());
    let mut result = Vec::new();

    let mut mst_edge_count = 0;
    let mut cost = 0;
    for &(u, v, w) in edges.iter() {
        if union_find.find(u) != union_find.find(v) {
            union_find.unite(u, v).unwrap();
            cost += w;
            result.push((u, v, w));
            mst_edge_count += 1;
            if mst_edge_count >= edges.len() - 1 {
                break;
            }
        }
    }
    (result, cost)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_kruskal_triangle() {
        let edges = vec![(0, 1, 1), (0, 2, 2), (1, 2, 3)];
        let (mst, cost) = kruskal(&edges);
        assert_eq!(cost, 3);
        assert_eq!(mst.len(), 2);
        assert!(mst.contains(&(0, 1, 1)));
        assert!(mst.contains(&(0, 2, 2)));
        assert!(!mst.contains(&(1, 2, 3)));
    }

    #[test]
    fn test_kruskal_square() {
        let edges = vec![(0, 1, 1), (1, 2, 3), (2, 3, 4), (3, 0, 5)];
        let (mst, cost) = kruskal(&edges);
        assert_eq!(cost, 8);
        assert_eq!(mst.len(), 3);
        assert!(mst.contains(&(0, 1, 1)));
        assert!(mst.contains(&(1, 2, 3)));
        assert!(mst.contains(&(2, 3, 4)));
        assert!(!mst.contains(&(3, 0, 5)));
    }
}
