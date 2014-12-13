{-
 - By Yue Wang 13.12.2014
 - proj02 Given a list, find the first and last occurrences of the largest element.
 - -}
firstAndLast :: (Ord a) => [a] -> (Int,Int)
firstAndLast [] = error "empty list"
firstAndLast xs = (firstMaximum xs, lastMaximum xs)
    where   fstMax xs = if head xs == maximum xs    then 0                  else 1 + fstMax (tail xs)
            lstMax xs = if last xs == maximum xs    then length xs - 1      else lstMax (init xs)
