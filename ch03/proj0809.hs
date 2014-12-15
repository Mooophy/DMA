--proj08 power
pow :: Integer -> Integer -> Integer
pow a n = if n == 0 then 1 else a * pow a (n-1)

--proj09 a^(2^n)
proj09 a n = pow a (pow 2 n)

main = do print (pow 10 2)
          print (proj09 2 3)  
--output :
--100
--256
