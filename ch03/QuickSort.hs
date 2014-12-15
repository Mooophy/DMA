--quick sort in haskell by Yue Wang 
quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort[y | y<-xs, y<=x] ++ [x] ++ quickSort[y | y<-xs, y>x]




li = [5,4,1,3,2]
main = do print li
          print (quickSort li)
          print (quickSort [])
--output:
--[5,4,1,3,2]
--[1,2,3,4,5]
--[1]
