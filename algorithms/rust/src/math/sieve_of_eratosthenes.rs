//! # Sieve of Eratosthenes
//!
//! Complexity: O(n log log n)
//!
//! The sieve of Eratosthenes is an ancient algorithm
//! for finding all prime numbers up to any given limit.
//!
//! TODO: Still possible to optimize this algorithm.
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

    macro_rules! test_sieve_of_eratosthenes {
        ($($name:ident: $value:expr,)*) => {
            $(
                #[test]
                fn $name() {
                    let (last, expected) = $value;
                    let result = sieve_of_eratosthenes(last);
                    assert_eq!(result, expected);
                }
            )*
        }
    }

    macro_rules! test_sieve_of_eratosthenes_last {
        ($($name:ident: $value:expr,)*) => {
            $(
                #[test]
                fn $name() {
                    let (last, expected) = $value;
                    let result = *sieve_of_eratosthenes(last).last().unwrap();
                    assert_eq!(result, expected);
                }
            )*
        }
    }
    test_sieve_of_eratosthenes! {
        primes_under_1: (1, []),
        primes_under_2: (2, [2]),
        primes_under_10: (10, [2, 3, 5, 7]),
        primes_under_100: (100, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
                                 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
                                 79, 83, 89, 97]),
    }

    test_sieve_of_eratosthenes_last! {
        last_prime_under_1000000: (1000000, 999983 as u64),
        last_prime_under_10000000: (10000000, 9999991 as u64),
    }
}
