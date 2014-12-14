{-
 - By Yue Wang 14.12.2014
 - proj07 greedy.
 --}
greedy::(Ord a, Num a) => [a] -> a -> [a]
greedy [] _ = []
greedy coins total = first (grd ([], coins, total))
            where 
                first (x,_,_)     =   x
                grd (rets, coins, total)  
                    | total==0        =   (rets, coins, total)
                    | otherwise       =   grd (curr:rets, newCoins, newTotal)
                    where 
                        curr        =   if isBig    then coins!!1             else head coins
                        newCoins    =   if isBig    then tail coins           else coins
                        newTotal    =   if isBig    then total - coins!!1     else total - coins!!0
                        isBig       =   head coins > total
          

main = print (greedy [100,50,10,5,2,1] 189)
{- @output:
 - [2,2,5,10,10,10,50,100]
 - -}
