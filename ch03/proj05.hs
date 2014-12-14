--proj05 Generate well-formed formulae using : x,y,z and  + - * /
generate :: [[Char]] -> [[Char]] -> Int -> [[Char]]
generate [] _ _  =  throw
generate _ [] _  =  throw
generate es os n 
    | n < 0      =  throw
    | otherwise  =  first (gen (es,os,n))
    where   throw           =   error "wrong inputs" 
            first(x,_,_)    =   x
            gen (es,os,n) 
                | n == 0    =   (es, os n)
                | otherwise =   gen(nextEs, os, n-1)
                where   nextEs  =  [l ++ o ++ r | l<-es, r<-es, o<-os]
