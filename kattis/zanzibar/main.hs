
solve :: [Int] -> Int
solve (x:xs) = snd (foldl (\a x -> (x, snd a + max (x - fst a * 2 ) 0)) (x, 0) xs)
solve _ = 0

convertToInts :: [[String]] -> [[Int]]
convertToInts = map (map (read::String->Int))

readLines :: String -> [[String]]
readLines = map words . tail . lines

main :: IO ()
main = interact (unlines . map (show . solve) . convertToInts . readLines)