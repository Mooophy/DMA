{-
 - By Yue Wang 14.12.2014
 - proj06 insertion sort.
 --}
insertionSort :: (Ord a) => [a] -> [a]
insertionSort [] = []
insertionSort xs = fst (insert ([],xs))
    where   insert(low, high) = if hs==[] then (ls, hs) else insert (ls, hs)
        where   ls = [x|x<-low, x <= head high] ++ [head high] ++ [x|x<-low, x > head high]
                hs = tail high
    
