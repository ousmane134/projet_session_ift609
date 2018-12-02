(clear-all)

(define-model count

(sgp :esc t :lf .05 :trace-detail high)


(chunk-type Mult         firstM  secondM resMU resMD)
(chunk-type Div          firstD  secondD resD)
(chunk-type Soustraction firstS  secondS  resSU resSD )
(chunk-type Add          firstA  secondA  resAU resAD )
(chunk-type Racine       nbre  resRU resRU)
 


(chunk-type Equat A B C X1 X2 delta state)
(chunk-type delta b-carreU b-carreD 4-acU 4-acD 4-acC retenuU retenuD)



(add-dm
 
(mult00 ISA Mult first 0 second 0 resU 0 resD 0)
(mult01 ISA Mult first 0 second 1 resU 0 resD 0)
(mult02 ISA Mult first 0 second 2 resU 0 resD 0)
(mult03 ISA Mult first 0 second 3 resU 0 resD 0)
(mult04 ISA Mult first 0 second 4 resU 0 resD 0)
(mult05 ISA Mult first 0 second 5 resU 0 resD 0)
(mult06 ISA Mult first 0 second 6 resU 0 resD 0)
(mult07 ISA Mult first 0 second 7 resU 0 resD 0)
(mult08 ISA Mult first 0 second 8 resU 0 resD 0)
(mult09 ISA Mult first 0 second 9 resU 0 resD 0)
(mult10 ISA Mult first 1 second 0 resU 0 resD 0)
(mult11 ISA Mult first 1 second 1 resU 1 resD 0)
(mult12 ISA Mult first 1 second 2 resU 2 resD 0)
(mult13 ISA Mult first 1 second 3 resU 3 resD 0)
(mult14 ISA Mult first 1 second 4 resU 4 resD 0)
(mult15 ISA Mult first 1 second 5 resU 5 resD 0)
(mult16 ISA Mult first 1 second 6 resU 6 resD 0)
(mult17 ISA Mult first 1 second 7 resU 7 resD 0)
(mult18 ISA Mult first 1 second 8 resU 8 resD 0)
(mult19 ISA Mult first 1 second 9 resU 9 resD 0)
(mult20 ISA Mult first 2 second 0 resU 0 resD 0)
(mult21 ISA Mult first 2 second 1 resU 2 resD 0)
(mult22 ISA Mult first 2 second 2 resU 4 resD 0)
(mult23 ISA Mult first 2 second 3 resU 6 resD 0)
(mult24 ISA Mult first 2 second 4 resU 8 resD 0)
(mult25 ISA Mult first 2 second 5 resU 0 resD 1)
(mult26 ISA Mult first 2 second 6 resU 2 resD 1)
(mult27 ISA Mult first 2 second 7 resU 4 resD 1)
(mult28 ISA Mult first 2 second 8 resU 6 resD 1)
(mult29 ISA Mult first 2 second 9 resU 8 resD 1)
(mult30 ISA Mult first 3 second 0 resU 0 resD 0)
(mult31 ISA Mult first 3 second 1 resU 3 resD 0)
(mult32 ISA Mult first 3 second 2 resU 6 resD 0)
(mult33 ISA Mult first 3 second 3 resU 9 resD 0)
(mult34 ISA Mult first 3 second 4 resU 2 resD 1)
(mult35 ISA Mult first 3 second 5 resU 5 resD 1)
(mult36 ISA Mult first 3 second 6 resU 8 resD 1)
(mult37 ISA Mult first 3 second 7 resU 1 resD 2)
(mult38 ISA Mult first 3 second 8 resU 4 resD 2)
(mult39 ISA Mult first 3 second 9 resU 7 resD 2)
(mult40 ISA Mult first 4 second 0 resU 0 resD 0)
(mult41 ISA Mult first 4 second 1 resU 4 resD 0)
(mult42 ISA Mult first 4 second 2 resU 8 resD 0)
(mult43 ISA Mult first 4 second 3 resU 2 resD 1)
(mult44 ISA Mult first 4 second 4 resU 6 resD 1)
(mult45 ISA Mult first 4 second 5 resU 0 resD 2)
(mult46 ISA Mult first 4 second 6 resU 4 resD 2)
(mult47 ISA Mult first 4 second 7 resU 8 resD 2)
(mult48 ISA Mult first 4 second 8 resU 2 resD 3)
(mult49 ISA Mult first 4 second 9 resU 6 resD 3)
(mult50 ISA Mult first 5 second 0 resU 0 resD 0)
(mult51 ISA Mult first 5 second 1 resU 5 resD 0)
(mult52 ISA Mult first 5 second 2 resU 0 resD 1)
(mult53 ISA Mult first 5 second 3 resU 5 resD 1)
(mult54 ISA Mult first 5 second 4 resU 0 resD 2)
(mult55 ISA Mult first 5 second 5 resU 5 resD 2)
(mult56 ISA Mult first 5 second 6 resU 0 resD 3)
(mult57 ISA Mult first 5 second 7 resU 5 resD 3)
(mult58 ISA Mult first 5 second 8 resU 0 resD 4)
(mult59 ISA Mult first 5 second 9 resU 5 resD 4)
(mult60 ISA Mult first 6 second 0 resU 0 resD 0)
(mult61 ISA Mult first 6 second 1 resU 6 resD 0)
(mult62 ISA Mult first 6 second 2 resU 2 resD 1)
(mult63 ISA Mult first 6 second 3 resU 8 resD 1)
(mult64 ISA Mult first 6 second 4 resU 4 resD 2)
(mult65 ISA Mult first 6 second 5 resU 0 resD 3)
(mult66 ISA Mult first 6 second 6 resU 6 resD 3)
(mult67 ISA Mult first 6 second 7 resU 2 resD 4)
(mult68 ISA Mult first 6 second 8 resU 8 resD 4)
(mult69 ISA Mult first 6 second 9 resU 4 resD 5)
(mult70 ISA Mult first 7 second 0 resU 7 resD 0)
(mult72 ISA Mult first 7 second 2 resU 4 resD 1)
(mult73 ISA Mult first 7 second 3 resU 1 resD 2)
(mult74 ISA Mult first 7 second 4 resU 8 resD 2)
(mult75 ISA Mult first 7 second 5 resU 5 resD 3)
(mult76 ISA Mult first 7 second 6 resU 2 resD 4)
(mult77 ISA Mult first 7 second 7 resU 9 resD 4)
(mult78 ISA Mult first 7 second 8 resU 6 resD 5)
(mult79 ISA Mult first 7 second 9 resU 3 resD 6)
(mult80 ISA Mult first 8 second 0 resU 0 resD 0)
(mult81 ISA Mult first 8 second 1 resU 8 resD 0)
(mult82 ISA Mult first 8 second 2 resU 6 resD 1)
(mult83 ISA Mult first 8 second 3 resU 4 resD 2)
(mult84 ISA Mult first 8 second 4 resU 2 resD 3)
(mult85 ISA Mult first 8 second 5 resU 0 resD 4)
(mult86 ISA Mult first 8 second 6 resU 8 resD 4)
(mult87 ISA Mult first 8 second 7 resU 6 resD 5)
(mult88 ISA Mult first 8 second 8 resU 4 resD 6)
(mult89 ISA Mult first 8 second 9 resU 2 resD 7)
(mult90 ISA Mult first 9 second 0 resU 0 resD 0)
(mult91 ISA Mult first 9 second 1 resU 9 resD 0)
(mult92 ISA Mult first 9 second 2 resU 8 resD 1)
(mult93 ISA Mult first 9 second 3 resU 7 resD 2)
(mult94 ISA Mult first 9 second 4 resU 6 resD 3)
(mult95 ISA Mult first 9 second 5 resU 5 resD 4)
(mult96 ISA Mult first 9 second 6 resU 4 resD 5)
(mult97 ISA Mult first 9 second 7 resU 3 resD 6)
(mult98 ISA Mult first 9 second 8 resU 2 resD 7)
(mult99 ISA Mult first 9 second 9 resU 1 resD 8)


(square00 ISA Racine nbreU 0 nbreD 0 nbreC 0 resSU 0 resSD 0)
(square01 ISA Racine nbreU 1 nbreD 0 nbreC 0 resSU 1 resSD 0)
(square02 ISA Racine nbreU 2 nbreD 0  nbreC 0 resSU 1 resSD 0)
(square03 ISA Racine nbreU 3 nbreD 0 nbreC 0 resSU 1 resSD 0)
(square04 ISA Racine nbreU 4 nbreD 0 nbreC 0 resSU 2 resSD 0)
(square05 ISA Racine nbreU 5 nbreD 0 nbreC 0 resSU 2 resSD 0)
(square06 ISA Racine nbreU 6 nbreD 0 nbreC 0 resSU 2 resSD 0)
(square07 ISA Racine nbreU 7 nbreD 0 nbreC 0 resSU 2 resSD 0)
(square08 ISA Racine nbreU 8 nbreD 0 nbreC 0 resSU 2 resSD 0)
(square09 ISA Racine nbreU 9 nbreD 0 nbreC 0 resSU 3 resSD 0)
(square10 ISA Racine nbreU 0 nbreD 1 nbreC 0 resSU 3 resSD 0)
(square11 ISA Racine nbreU 1 nbreD 1 nbreC 0 resSU 3 resSD 0)
(square12 ISA Racine nbreU 2 nbreD 1 nbreC 0 resSU 3 resSD 0)
(square13 ISA Racine nbreU 3 nbreD 1 nbreC 0 resSU 3 resSD 0)
(square14 ISA Racine nbreU 4 nbreD 1 nbreC 0 resSU 3 resSD 0)
(square15 ISA Racine nbreU 5 nbreD 1 nbreC 0 resSU 3 resSD 0)
(square16 ISA Racine nbreU 6 nbreD 1 nbreC 0 resSU 4 resSD 0)
(square17 ISA Racine nbreU 7 nbreD 1 nbreC 0 resSU 4 resSD 0)
(square18 ISA Racine nbreU 8 nbreD 1 nbreC 0 resSU 4 resSD 0)
(square19 ISA Racine nbreU 9 nbreD 1 nbreC 0 resSU 4 resSD 0)
(square20 ISA Racine nbreU 0 nbreD 2 nbreC 0 resSU 4 resSD 0)
(square21 ISA Racine nbreU 1 nbreD 2 nbreC 0 resSU 4 resSD 0)
(square22 ISA Racine nbreU 2 nbreD 2 nbreC 0 resSU 4 resSD 0)
(square23 ISA Racine nbreU 3 nbreD 2 nbreC 0 resSU 4 resSD 0)
(square24 ISA Racine nbreU 4 nbreD 2 nbreC 0 resSU 4 resSD 0)
(square25 ISA Racine nbreU 5 nbreD 2 nbreC 0 resSU 5 resSD 0)
(square26 ISA Racine nbreU 6 nbreD 2 nbreC 0 resSU 5 resSD 0)
(square27 ISA Racine nbreU 7 nbreD 2 nbreC 0 resSU 5 resSD 0)
(square28 ISA Racine nbreU 8 nbreD 2 nbreC 0 resSU 5 resSD 0)
(square29 ISA Racine nbreU 9 nbreD 2 nbreC 0 resSU 5 resSD 0)
(square30 ISA Racine nbreU 0 nbreD 3 nbreC 0 resSU 5 resSD 0)
(square31 ISA Racine nbreU 1 nbreD 3 nbreC 0 resSU 5 resSD 0)
(square32 ISA Racine nbreU 2 nbreD 3 nbreC 0 resSU 5 resSD 0)
(square33 ISA Racine nbreU 3 nbreD 3 nbreC 0 resSU 5 resSD 0)
(square34 ISA Racine nbreU 4 nbreD 3 nbreC 0 resSU 5 resSD 0)
(square35 ISA Racine nbreU 5 nbreD 3 nbreC 0 resSU 5 resSD 0)
(square36 ISA Racine nbreU 6 nbreD 3 nbreC 0 resSU 6 resSD 0)
(square37 ISA Racine nbreU 7 nbreD 3 nbreC 0 resSU 6 resSD 0)
 

(first-goal ISA Equat A 1  B 3 C 2 res state nil)) 



(goal-focus first-goal)


(p start_A_NN
   =goal>
      ISA         Equat
	  A           =a
	  B           =b
	  C           =c
	 -A           0 ;;CAS A est different de zero. On a soit deux solutions ou zero solution
	  state       nil
 ==>
   =goal>
		state     b-carre
   +retrieval>
      ISA         Mult
      firstM       b
	  secondM      b
)


)


;;CAS A est égal de zero. On a soit deux solutions ou zero solution
(p start_A_N
   =goal>
      ISA         Equat
	  A           =a
	  B           =b
	  C           =c
	  A           0 
	  state       nil
 ==>
   =goal>
		state     une-solution
		
   +retrieval>
		ISA Div
		firstD =c
		secondD =b		  
)

(p Sol-A-NUL

	=goal>
		ISA Equat
		state une-solution
	=retrieval>
	    ISA Div
	    firstD  =c
		secondD =b
		resD    =res
==>
	=-goal>
   !output!       (- res)
)


(P b-carre 
	=goal>
		ISA   Equat
		state b-carre
		A           =a
	    B           =b
	    C           =c
	=retrieval>
	    ISA      Mult
		firstM    =b
		secondM   =b
	    resMU     =bbU
		resMD     =bbD
	?imaginal>
       state free
==>
	=goal>
		state   ac	
    +imaginal>
	    ISA delta
	    b-carreU =bbU
		b-carreD =bbD
	+retrieval>
      ISA         Mult
      firstM       a
	  secondM     c 
	    
)



(P ac
	=goal>
		ISA   Equat
		state ac
		A        =a
	    B        =b
	    C        =c
	=retrieval>
	    ISA      Mult
		firstM    =a
		secondM   =c
		resMU     =acU
		resMD     =acD 
	?imaginal>
       state free
==>
	=goal>
		state   4ac-U
    +imaginal>
	    ISA delta
	    4-acU   =acU
		4-acD   =acD
	+retrieval>
	    ISA      Mult
		firstM    =4
		secondM   =acU
	    
)



(P 4ac-U
	=goal>
		ISA   Equat
		state 4ac-U
		A        =a
	    B        =b
	    C        =c
	=retrieval>
	    ISA      Mult
		firstM    =4
		secondM   =acU
		resMU     =4acU
		;;resMD     =ret
	?imaginal>
	    state free

==>
	=goal>
	    ISA     Equat
		state   4ac-D
	+imaginal>
	    ISA    delta
		4ac-U  =4acU
		;;retenu =ret
    +retrieval>
	    ISA      Mult
		firstM    4
		secondM   4-acD
		;;verifier si on peut comparer avec un slot
				
)
    
 
(P 4ac-D
	=goal>
		ISA   Equat
		state 4ac-D
		A        =a
	    B        =b
	    C        =c
	=retrieval>
	    ISA      Mult
		first    =4
		second   =acD
		resU     =4acD
        resD     =4acC
    ?imaginal>
        state   free		
==>
	=goal>
	    ISA     Equat
		state   diff-bb-4ac
	+imaginal>
	    ISA    delta
		4-acD   =4acD
		4-acC   =4acC
		        		
)  



(p delta

	=goal>
	













	)



























(p diff-bb-4ac
	=goal>
		ISA Equat
		state diff-bb-4ac
	    A        =a
	    B        =b
	    C        =c
	=retrieval>
		ISA delta
		b-carre-U 	=a1		
		b-carre-D 	=a2
		4-acU 		=b1 
		4-acD 		=b2 
		4-acC 		=b3
		
==>
	=+retrieval>
		ISA soustraction
		nbreAU =a1
		nbreAD =a2
		nbreAC 0
		nbreBU =b1
		nbreBD =b2
		nbreBC =b3
		res_sousU =c1
		res_sousD =c2
		res_sousC =c3
				
	=goal>
		ISA Equat
		state racine-delta 
		
	=+imaginal>
		ISA soustraction
		res_sousU =c1
		res_sousD =c2
		res_sousC =c3
		
)


;;(chunk-type Racine nbreU nbreD nbreC resSU resSD)
(p racine-delta
	=goal>
		ISA Equat
		state racine-delta
		A =a
		B =b 
		C =c
		
	=imaginal>
		ISA soustraction
		res_sousU =c1
		res_sousD =c2
		res_sousC =c3 

==>
	=goal>
		ISA Equat
		state diff-b-delta-square
	+retrieval>
		ISA Racine
		nbreU =c1
		nbreD =c2 
		nbreC =c3
		resSU =d1
		resSD =d2
		
	+imaginal>
		ISA Racine
		resSU =d1
		resSD =d2
		
)
;;(chunk-type soustraction nbreAU nbreAD nbreAC nbreBU nbreBD nbreBC res_sousU res_sousD res_sousC)
(p diff-b-delta-square
	=goal>
		ISA Euqat
		state diff-b-delta-square
		A =a
		B =b 
		C =c
	=imaginal>
		ISA Racine
		resSU =d1
		resSD =d2
==>
	=goal>
		ISA Equat
		state 2-a
	=+retrieval>
		ISA soustraction
		nbreAU =b
		nbreAD 0
		nbreAC 0
		nbreBU =d1
		nbreBD =d2
		nbreBC 0
		res_sousU =r1
		res_sousD =r2
		res_sousC =r3
	=+imaginal>
		ISA soustraction
		res_sousU =r1
		res_sousD =r2
		res_sousC =r3
)


;;(chunk-type Mult first second resU resD)
(p 2-a
	=goal>
		ISA Equat
		A =a
		B =b 
		C =c
==>
	=+retrieval>
		ISA mult
		first 2
		second =a
		resU =r1
		resD =r2
	=goal>
		ISA Equat
		state quotient ;; pour aller à la production qi va calculer (-b-racine(delta)/2*a
 
			    
)

















)
