                     Manual                   
 NAME
         fillit -- tetramino solver

 SYNOPSIS
          fillit [--options[num]] source_file 
          fillit [--help]

 DESCRIPTION
         The fillit utility finds a way to assemble a given set of tetrimino in
         the smallest possible area from the map of the source_file.

         The following options are available:

         --options1		print convert tetramino in bits

         --options2		print matrix with all subsets

         --options3		in future :)

         --help			Print a brief help message.

         Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).

         A Tetrimino is a classic piece of Tetris composed of 4 blocks.

         Each character must be either a block character(’#’ ) or an empty character (’.’).

         Each block of a Tetrimino must touch at least one other block on any of his 4 sides
         (up, down, left and right).

         A few examples of valid descriptions of Tetriminos:
		 
		 ....	 ....	 ####	 ....	 .##.	 ....	 .#..	 ....	 ....
		 ..##	 ....	 ....	 ....	 ..##	 .##.	 ###.	 ##..	 .##.
		 ..#. 	 ..##	 ....	 ##..	 ....	 ##..	 ....	 #...	 ..#.
		 ..#.	 ..##	 ....	 ##..	 ....	 ....	 ....	 #...	 ..#.
		 
        A few examples of invalid descriptions of Tetriminos
		
		####	...#	##...	#. 	....	..##	####	,,,,	.HH.
		...#	..#.	##...	## 	....	....	####	####	HH..
		....	.#..	....	#. 	....	....	####	,,,,	....
		....	#...	....		....	##..	####	,,,,	....
		
        Because each Tetrimino fills only 4 of the 16 available boxes, it is possible to describe
        the same Tetrimino in multiple ways. However, a rotated Tetrimino describes a different
        Tetrimino from the original, in the case of this project. This means no rotation is possible
        on a Tetrimino, when you will arrange it with the others.
        Those Tetriminos are then perfectly equivalents on every aspect :
		
        ##..	 .##.	 ..##	....	 ....	 ....
        #...	 .#..	 ..#. 	##..	 .##.	 ..##
        #...	 .#..	 ..#. 	#...	 .#..	 ..#.
        ....	 ....	 .... 	#...	 .#..	 ..#.

        Finally, here is an example of a valid file your program must resolve:
		
		$> cat -e valid_sample.fillit
		...#$
		...#$
		...#$
		...#$
		$
		....$
		....$
		....$
		####$
		$
		.###$
		...#$
		....$
		....$
		$
		....$
		..##$
		.##.$
		....$
		$>

        The program displays the smallest assembled square on the standard output. The capital
        letter for each tetrimino, starting with the letter "A" and increasing for each new
        tetrimino. If the file contains at least one error, the error will be displayed in the
        standard output.

 EXAMPLES
 		$> cat sample.fillit | cat -e					$> cat sample.fillit | cat -e
		....$										....$
		##..$										....$
		.#..$										####$
		.#..$										....$
		$										$
		....$										....$
		####$										...$
		....$										..##$
		....$										..##$
		$										$> ./fillit sample.fillit | cat -e
		#...$										error$
		###.$										$>
		....$
		....$
		$
		....$
		##..$
		.##.$
		....$
		$> ./fillit sample.fillit | cat -e
		DDAA$
		CDDA$
		CCCA$
		BBBB$
		$>

		Exzmmple options1

		$> cat sample.fillit | cat -e
		....$
		...#$
		..##$
		...#$
		$
		####$
		....$
		....$
		....$
		$
		##..$
		##..$
		....$
		....$
		$> ./fillit -options1 sample.fillit | cat -e
		0100 1100 0100 0000 $
		0000 0000 0000 0000 $
		~~~~~~~~~~~~~~~~~~~$
		1111 0000 0000 0000 $
		0000 0000 0000 0000 $
		~~~~~~~~~~~~~~~~~~~$
		1100 1100 0000 0000 $
		0000 0000 0000 0000 $
		~~~~~~~~~~~~~~~~~~~$

 EXIT STATUS
		The fillit utility exits 0 on success, and > 0 if an error occurs.

