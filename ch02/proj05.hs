{-
 - By Yue Wang 13.12.2014
 - proj05 bubble sort.
 --}
bubbleSort :: (Ord a) => [a] -> [a]
bubbleSort [] = []
bubbleSort xs = bubbleSort [x|x<-xs, x < maximum xs] ++ [x|x<-xs, x == maximum xs]
