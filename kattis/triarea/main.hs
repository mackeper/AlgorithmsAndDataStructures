main = interact (\input -> show (foldl (\a x -> x * a) 0.5 (map read (words input))))