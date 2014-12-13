{-
 - By Yue Wang 13.12.2014
 - proj02 Given a list, find the first and last occurrences of the largest element.
 - -}
firstAndLast :: (Ord a) => [a] -> (Int,Int)
firstAndLast []         =   error "empty list"
firstAndLast xs         =   (fstMax xs, lstMax xs)
    where   fstMax seq@(y:ys) = if y        == maximum seq      then 0                  else 1 + fstMax ys
            lstMax seq@(y:ys) = if last seq == maximum seq      then length seq - 1     else lstMax (init seq)
