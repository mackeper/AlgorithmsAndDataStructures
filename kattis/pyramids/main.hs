solve :: Int -> Int -> Int -> Int -> Int
solve height n used left
    | left >= n * n = solve (height+1) (n+2) (used+n*n)(left-n*n)
    | otherwise = height

main :: IO ()
main = interact (show . solve 0 1 0 . read)