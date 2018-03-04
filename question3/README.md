## Question 2

(K&R Exercise 5-14 & 5-15) Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order. Be sure that -r works with -n.

Also, add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A compare equal.

Compile Steps:

	gcc q3.c -o out3
	./out3 `< hi`

Output (no flags):

	INPUT:
	This is a test
	Hello all
	hi
	bla
	ho
	help
	Hi professor Hong!
	Hi
	My program works!
		lowercase
		spaces in front
			tab in front
	
	OUTPUT:
			tab in front
		lowercase
		spaces in front
	Hello all
	Hi
	Hi professor Hong!
	My program works!
	This is a test
	bla
	help
	hi
	ho

Output (-n flag):

	INPUT:
	This is a test
	Hello all
	hi
	bla
	ho
	help
	Hi professor Hong!
	Hi
	My program works!
		lowercase
	  spaces in front
			tab in front
	
	OUTPUT:
	bla
	help
	Hi professor Hong!
	Hi
	Hello all
	hi
	ho
		lowercase
	My program works!
	  spaces in front
	This is a test
			tab in front

Output (-r -n flags): 

	INPUT:
	This is a test
	Hello all
	hi
	bla
	ho
	help
	Hi professor Hong!
	Hi
	My program works!
		lowercase
	  spaces in front
			tab in front
	
	OUTPUT:
			tab in front
	This is a test
	  spaces in front
	My program works!
		lowercase
	ho
	hi
	Hello all
	Hi
	Hi professor Hong!
	help
	bla
	
Output (-f flag):

	INPUT:
	This is a test
	Hello all
	hi
	bla
	ho
	help
	Hi professor Hong!
	Hi
	My program works!
		lowercase
	  spaces in front
			tab in front
	
	OUTPUT:
			tab in front
		lowercase
	  spaces in front
	bla
	Hello all
	help
	Hi
	hi
	Hi professor Hong!
	ho
	My program works!
	This is a test
	
Output (-r -f flags):

	INPUT:
	This is a test
	Hello all
	hi
	bla
	ho
	help
	Hi professor Hong!
	Hi
	My program works!
		lowercase
	  spaces in front
			tab in front
	
	OUTPUT:
	This is a test
	My program works!
	ho
	Hi professor Hong!
	hi
	Hi
	help
	Hello all
	bla
	  spaces in front
		lowercase
			tab in front

Output (illegal flag):

	Unknown option m
	USAGE: ./out3 -n [numlines]

