{-
 - By Yue Wang 14.12.2014
 - proj06 insertion sort.
 --}
{-
insert :: (Ord a) => ([a], [a]) -> ([a], [a])
insert (low, high)  =   if newHigh==[]  then (newLow, newHigh)  else insert (newLow, newHigh) 
                        where   newLow  = [x|x<-low, x <= head high] ++ [head high] ++ [x|x<-low, x > head high]
                                newHigh = tail high
-}

insertionSort :: (Ord a) => [a] -> [a]
insertionSort [] = []
insertionSort xs = fst (insert ([],xs))
    where   insert(low, high)       =   if newHigh==[] then (newLow, newHigh) else insert (newLow, newHigh)
                where   newLow      =   [x|x<-low, x <= head high] ++ [head high] ++ [x|x<-low, x > head high]
                        newHigh     =   tail high
    
