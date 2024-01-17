import Data.List (intercalate)

solve :: [Int] -> [Int]
solve (n:l:ants) = n:l:ants

buildCases :: [[Int]] -> [Int] -> [[Int]]
buildCases cases (n:l:rest) = buildCases ((n : l : take n rest) : cases) (drop n rest)
buildCases cases _ = cases

main :: IO ()
main = interact (unlines . map (show . solve) . buildCases [] . map (map (read::String->Int)) . map words . tail . lines)