(defun tester ()
	(format t "Who goes first?: ")
	(setf player1 (read))
		(cond
			((equal player1 'H)
				(format t "human goes first")
			)
			((equal player1 'C)
				(format t "computer goes first")
			)
			(t
				(format t "HAS TO BE EITHER C FOR COMPUTER OR H FOR HUMAN ~%" )
				(tester)
			)
		)
)

(defun createBoard()
	(setf board (list '(- - -) '(- T -) '(- - -)))
	;(format t "~A" board);(first (first board)))
	(printBoard board )
)

(defun printBoard(board n)
	(format t "~A" (nth 0 board))

)