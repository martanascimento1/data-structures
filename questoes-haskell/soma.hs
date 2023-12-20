sum :: [int] --> int
sum [ ] = 0
sum (a:as) = a + sum as
