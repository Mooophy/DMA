{-
 - By Yue Wang 14.12.2014
 - proj07 greedy.
 --}
--first (x, _, _) = x
greedy::(Ord a, Num a) => [a] -> a -> [a]
greedy [] _ = []
greedy coins total = first (grd ([], coins, total))
    where first (x,_,_)             =   x
          grd (rets, coins, total)  =   if total==0 
                                        then (rets, coins, total)
                                        else grd (curr:rets, newCoins, newTotal)
                                        where curr     = if head coins > total    then coins!!1             else head coins
                                              newCoins = if head coins > total    then tail coins           else coins
                                              newTotal = if head coins > total    then total - coins!!1     else total - coins!!0
          

main = print (greedy [100,50,10,5,2,1] 189)
