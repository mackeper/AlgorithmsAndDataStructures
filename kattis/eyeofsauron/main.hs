solve n []
    | n == 0 = "correct"
    | otherwise = "fix"
solve n (x:xs)
    | x == '|' = solve (n+1) xs
    | x == '(' = solve (-n) xs
    | x == ')' = solve n xs
solve n x = solve n []


main :: IO ()
main = interact (solve 0)