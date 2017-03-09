(defun tic-tac-toe ()
	(format t "Who goes first?: ")
	(let ((first-turn (read)))
		;(format t "first-turn is ~A" first-turn)
		(cond
			((equal first-turn 'H) 
				(format t "Human goes first.~%")
				(print-board (create-board) 'H)
			)
			((equal first-turn 'C) 
				(print-board (create-board) 'C)
			)
			(t
				(format t "Please input C for computer or H for human.~%")
				(tic-tac-toe)
			)
		)
	)
)

(defun create-board ()
	(setf board (list '(- - -) '(- - -) '(- - -)))
	;(format t "~A" board);(first (first board)))
)

(defun print-board (board turn)
	(format t "~A" (first (first board))) ;From here
	(format t "~A" (first (second board)))
	(format t "~A~%" (first (third board)))
	(format t "~A" (second (first board)))
	(format t "~A" (second (second board)))
	(format t "~A~%" (second (third board)))
	(format t "~A" (third (first board)))
	(format t "~A" (third (second board)))
	(format t "~A~%" (third (third board))) ;to here simply prints the board. Sorry that it's incredibly unelegant
	(if (equal turn 'H) ;This checks to see whose turn it is
		(human-turn board)
		(computer-turn board) )
)

(defun human-turn (board)
	(format t "Human, select where you want to go.~%") ;Ask the player where they want to go
	(format t "Row: ")
		(setf row (read))
		(if (not (and (integerp row) (< row 3))) ;This
			(progn
				(format t "Please enter a number between 0-2~%")
				(human-turn board) ))
	(format t "Column: ")
		(setf col (read))
		(if (not (and (integerp col) (< col 3))) ;and this if statement check to see that the input is valid
			(progn
				(format t "Please enter a number between 0-2~%")
				(human-turn board) ))
	(format t "Valid input!") )

(defun computer-turn (board)
	(human-turn board) ) ;Currently a placeholder that redirects to human-turn function
