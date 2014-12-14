--proj05 Generate well-formed formulae using : x,y,z and  + - * /
generate :: [[Char]] -> [[Char]] -> Int -> [[Char]]
generate [] _ _  =  error "wrong inputs"
generate _ [] _  =  error "wrong inputs"
generate es os n 
    | n < 0      =  error "wrong inputs"
    | otherwise  =  first (gen (es,os,n))
    where   first(x,_,_)    =   x
            gen (es,os,n) 
                | n == 0    =   (es, os, n)
                | otherwise =   gen(nextEs, os, n-1)
                where   nextEs  =  es ++ [l ++ o ++ r | l<-es, r<-es, o<-os]


--test:
es = ["x","y","z"]
os = ["+","-","*","/"]
main = do print (generate es os 1)
--output:
--["x","y","z","x+x","x-x","x*x","x/x","x+y","x-y","x*y","x/y","x+z","x-z","x*z","x/z","y+x","y-x","y*x","y/x","y+y","y-y","y*y","y/y","y+z","y-z","y*z","y/z","z+x","z-x","z*x","z/x","z+y","z-y","z*y","z/y","z+z","z-z","z*z","z/z"]
--
