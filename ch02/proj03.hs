{-
 - By Yue Wang 13.12.2014
 - proj03 linear search.
 - @note this is a non monad version, return the size of the list when nothing found
 - -}
linearSearch :: (Eq a)=> [a] -> a -> Int
linearSearch [] val     =  error "empty list"
linearSearch [x]val     =  if x == val     then 0  else 1
linearSearch (x:xs) val =  if x == val     then 0  else 1 + linearSearch xs val 

