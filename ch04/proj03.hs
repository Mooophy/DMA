next :: [Bool] -> [Bool]
next [] = []
next xs 	
	| 	last xs==True		=	next(init xs) ++ [False]
	|	otherwise			=		 init xs  ++ [True] 		 
