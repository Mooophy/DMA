{-
 - By Yue Wang 13.12.2014
 - proj04 binary search search.
 - -}
binSearch :: (Ord a) => [a] -> a -> Int
binSearch []  val = error "empty list"
binSearch [x] val = if x == val then 0 else 1
binSearch xs  val = case compare (xs !! mid) val of
                        EQ -> mid
                        GT -> 0   + binSearch (take mid xs) val
                        LT -> mid + binSearch (drop mid xs) val  
                    where mid = div (length xs) 2
