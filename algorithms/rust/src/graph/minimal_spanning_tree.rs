// pub fn kruskal(edges: &Vec<(usize, usize)>) -> Vec<(usize, usize)> {
//     let mut edges = edges.clone();
//     edges.sort_by(|a, b| a.0.cmp(&b.0));
//     let mut uf = UnionFind::new(edges.len());
//     let mut result = Vec::new();
//     for (i, &(w, u, v)) in edges.iter().enumerate() {
//         if uf.find(u) != uf.find(v) {
//             uf.unite(u, v);
//             result.push((w, u, v));
//         }
//     }
//     result
// }
