nesimo :: Int -> [Int] -> Int
nesimo 1 (a:as) = as
nesimo n (a:as) = nesimo (n-1) as