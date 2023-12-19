//! # Sieve of Eratosthenes
//!
//! Complexity: O(n log log n)
//!
//! The sieve of Eratosthenes is an ancient algorithm
//! for finding all prime numbers up to any given limit.
pub fn sieve_of_eratosthenes(last: u64) -> Vec<u64> {
    let is_even = |x: usize| -> bool { x & 1 == 0 };

    let last = last as usize;
    let mut primes = Vec::new();
    let mut sieve = vec![true; last + 1];
    for i in 2..=last {
        if i == 2 {
            primes.push(i as u64);
            continue;
        }
        if is_even(i) {
            continue;
        }
        if sieve[i] {
            primes.push(i as u64);
            for j in ((i * i)..=last).step_by(i) {
                sieve[j] = false;
            }
        }
    }
    primes
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn primes_under_10() {
        let result = sieve_of_eratosthenes(10);
        assert_eq!(result, [2, 3, 5, 7]);
    }

    #[test]
    fn primes_under_100() {
        let result = sieve_of_eratosthenes(100);
        assert_eq!(
            result,
            [
                2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                83, 89, 97
            ]
        );
    }

    #[test]
    fn last_prime_under_1000000() {
        let result = sieve_of_eratosthenes(1000000);
        assert_eq!(result.last(), Some(&999983));
    }

    #[test]
    fn last_prime_under_10000000() {
        let result = sieve_of_eratosthenes(10000000);
        assert_eq!(result.last(), Some(&9999991));
    }

    #[test]
    fn primes_under_1() {
        let result = sieve_of_eratosthenes(1);
        assert_eq!(result, []);
    }

    #[test]
    fn primes_under_2() {
        let result = sieve_of_eratosthenes(2);
        assert_eq!(result, [2]);
    }
}
