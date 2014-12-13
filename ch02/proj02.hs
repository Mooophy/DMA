{-
 - By Yue Wang 13.12.2014
 - proj02 Given a list, find the first and last occurrences of the largest element.
 - -}
firstMaximum :: (Ord a) => [a] -> Int
firstMaximum []     =   error "empty list"
firstMaximum xs     
    | head xs == maximum xs     =   0
    | otherwise                 =   1 + firstMaximum (tail xs)


lastMaximum :: (Ord a) => [a] -> Int
lastMaximum []      =   error "empty list"
lastMaximum xs
    | last xs == maximum xs     =   length xs - 1
    | otherwise                 =   lastMaximum (init xs) 

