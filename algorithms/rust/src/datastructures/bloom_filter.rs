//! Bloom filter
//!
//! A Bloom filter is a space-efficient probabilistic data structure
//! that is used to test whether an element is a member of a set.
//! False positive matches are possible, but false negatives are not.
//! Elements can be added to the set, but not removed.
//! The more elements that are added to the set, the larger the
//! probability of false positives.

use std::{collections::hash_map::DefaultHasher, hash::Hasher};

// k: number of hash functions
// m: size of bitset
pub struct BloomFilter {
    bitset: Vec<bool>,
    k: usize,
    m: usize,
}

impl BloomFilter {
    // TODO: calculate optimal k and m
    pub fn new_default() -> Self {
        let size = 51170; // large prime
        BloomFilter {
            bitset: vec![false; size],
            k: 10,
            m: size, // large prime
        }
    }

    pub fn new(k: usize, m: usize) -> Self {
        BloomFilter {
            bitset: vec![false; m],
            k,
            m,
        }
    }

    pub fn add(&mut self, key: &str) {
        for i in 0..self.k {
            let index = self.hash(key, i);
            self.bitset[index] = true;
        }
    }

    pub fn contains(&self, key: &str) -> bool {
        for i in 0..self.k {
            let index = self.hash(key, i);
            if self.bitset[index] == false {
                return false;
            }
        }
        true
    }

    fn hash(&self, key: &str, i: usize) -> usize {
        let mut hasher = DefaultHasher::new();
        let salt = format!("{}{}", key, i);
        hasher.write(salt.as_bytes());
        hasher.finish() as usize % self.m
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_bloom_filter() {
        let mut bf = BloomFilter::new_default();
        bf.add("hello");
        bf.add("world");
        assert_eq!(bf.contains("hello"), true);
        assert_eq!(bf.contains("world"), true);
        assert_eq!(bf.contains("foo"), false);
    }
}
