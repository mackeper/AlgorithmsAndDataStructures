solve :: Int -> [String] -> Int
solve volume [] = volume
solve volume ("Skru op!" : rest) = solve (min (volume + 1) 10) rest
solve volume ("Skru ned!" : rest) = solve (max (volume - 1) 0) rest
solve volume (x : rest) = solve volume rest

main = interact (show . solve 7 . lines)