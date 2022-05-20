solve :: String -> String
solve input
    | take 3 input == "555" = show 1
    | otherwise = show 0

main = interact solve