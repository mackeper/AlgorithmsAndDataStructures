//! Union-Find data structure, also known as a disjoint-set data structure or merge-find set.
//!
//! A Union-Find data structure is a data structure that keeps track of a set of elements partitioned
//! into a number of disjoint (non-overlapping) subsets. It provides near-constant-time operations
//! (bounded by the inverse Ackermann function) to add new sets, to merge existing sets, and to
//! determine whether elements are in the same set.

struct Subset {
    parent: usize,
    rank: usize,
}

pub struct UnionFind {
    subsets: Vec<Subset>,
}

impl UnionFind {
    // Create a new UnionFind data structure with size elements.
    pub fn new(size: usize) -> Self {
        UnionFind {
            subsets: (0..size).map(|i| Subset { parent: i, rank: 0 }).collect(),
        }
    }

    // Find the root of the set that i belongs to.
    pub fn find(&mut self, i: usize) -> Option<usize> {
        if self.subsets.get(i)?.parent != i {
            self.subsets.get_mut(i)?.parent = self.find(self.subsets.get(i)?.parent)?;
        }
        Some(self.subsets.get(i)?.parent)
    }

    // Unite the sets that x and y belong to.
    pub fn unite(&mut self, x: usize, y: usize) -> Result<(), ()> {
        let xroot = self.find(x).ok_or(())?;
        let yroot = self.find(y).ok_or(())?;

        let xrank = self.subsets.get(xroot).ok_or(())?.rank;
        let yrank = self.subsets.get(yroot).ok_or(())?.rank;

        if xrank < yrank {
            self.subsets.get_mut(xroot).ok_or(())?.parent = yroot;
        } else if xrank > yrank {
            self.subsets.get_mut(yroot).ok_or(())?.parent = xroot;
        } else {
            self.subsets.get_mut(yroot).ok_or(())?.parent = xroot;
            self.subsets.get_mut(xroot).ok_or(())?.rank += 1;
        }

        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_union_find() {
        let mut uf = UnionFind::new(5);
        assert_eq!(uf.find(0), Some(0));
        assert_eq!(uf.find(1), Some(1));
        assert_eq!(uf.find(2), Some(2));
        assert_eq!(uf.find(3), Some(3));
        assert_eq!(uf.find(4), Some(4));
        uf.unite(0, 1).unwrap();
        assert_eq!(uf.find(0), Some(0));
        assert_eq!(uf.find(1), Some(0));
        assert_eq!(uf.find(2), Some(2));
        assert_eq!(uf.find(3), Some(3));
        assert_eq!(uf.find(4), Some(4));
        uf.unite(1, 2).unwrap();
        assert_eq!(uf.find(0), Some(0));
        assert_eq!(uf.find(1), Some(0));
        assert_eq!(uf.find(2), Some(0));
        assert_eq!(uf.find(3), Some(3));
        assert_eq!(uf.find(4), Some(4));
        uf.unite(3, 4).unwrap();
        assert_eq!(uf.find(0), Some(0));
        assert_eq!(uf.find(1), Some(0));
        assert_eq!(uf.find(2), Some(0));
        assert_eq!(uf.find(3), Some(3));
        assert_eq!(uf.find(4), Some(3));
        uf.unite(0, 4).unwrap();
        assert_eq!(uf.find(0), Some(0));
        assert_eq!(uf.find(1), Some(0));
        assert_eq!(uf.find(2), Some(0));
        assert_eq!(uf.find(3), Some(0));
        assert_eq!(uf.find(4), Some(0));
    }

    #[test]
    fn test_union_find_access_out_of_bounds() {
        let mut uf = UnionFind::new(5);
        assert_eq!(uf.find(5), None);
    }
}
