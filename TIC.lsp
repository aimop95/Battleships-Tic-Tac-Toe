(defun tic-tac-toe()
	(setf board (list '(- - -) '(- - -) '(- - -)))
	(run)
)
(defun run ()
	(format t "Who goes first?: ")
	(setf turn (read))
		(cond
			((equal turn 'H)
				(format t "human goes first ~%")
				(play turn)
			)
			((equal turn 'C)
				(format t "computer goes first~%")
				(play turn)
			)
			(t
				(format t "HAS TO BE EITHER C FOR COMPUTER OR H FOR HUMAN ~%" )
				(run)
			)
		)
)

(defun printBoard ()
	(format t "  0 1 2~%")
	(format t "0~A~%" (nth 0 board))
	(format t "1~A~%" (nth 1 board))
	(format t "2~A~%" (nth 2 board))
)

(defun play (turn)
	(printBoard)
	(cond
		; ((gameOver)

		; )
		((checkWin turn)
			
		)
		(t
			(cond
				((equal turn 'H)
					(format t "Human where would you like to play? ROW COL ~%")
					(setf row (read))
					(setf col (read))
					(if (equal (nth col (nth row board)) '- )
						(progn
							(setf (nth col (nth row board)) turn)
							(printBoard)
							(play 'C))
					)			
				)
				((equal turn 'C)
					(format t "Computer where would you like to play? ROW COL ~%")
					(setf row (read))
					(setf col (read))
					(if (equal (nth col (nth row board)) '- )
						(progn
							(setf (nth col (nth row board)) turn)
							(printBoard)
							(play 'H))
					)			
				)
			)
		)
	)

	; (format t "Where would you like to play? ROW COL ~%")
	; (setf row (read))
	; (setf col (read))
	; (if (equal (nth col (nth row board)) '- )
	; 	(progn
	; 	(setf (nth col (nth row board)) player)
	; 	(printBoard))
	; )
)

(defun checkWin(player)
	; check vertical left
	(if (and (equal (nth 0 (nth 0 board)) player)(equal (nth 0 (nth 1 board)) player)(equal (nth 0 (nth 2 board)) player))
		t
	)
	; check vertical middle
	(if (and (equal (nth 1 (nth 0 board)) player)(equal (nth 1 (nth 1 board)) player)(equal (nth 1 (nth 2 board)) player))
		t	
	)
	; check vertical right
	(if (and (equal (nth 2 (nth 0 board)) player)(equal (nth 2 (nth 1 board)) player)(equal (nth 2 (nth 2 board)) player))
		t
	)
	; check horizontal top
	(if (and (equal (nth 0 (nth 0 board)) player)(equal (nth 1 (nth 0 board)) player)(equal (nth 2 (nth 0 board)) player))
		t
	)
	; check horizontal middle
	(if (and (equal (nth 0 (nth 1 board)) player)(equal (nth 1 (nth 1 board)) player)(equal (nth 2 (nth 1 board)) player))
		t
	)
	; check horizontal bottom
	(if (and (equal (nth 0 (nth 2 board)) player)(equal (nth 1 (nth 2 board)) player)(equal (nth 2 (nth 2 board)) player))
		t
	)
	; check diagonal left-right
	(if (and (equal (nth 0 (nth 0 board)) player)(equal (nth 1 (nth 1 board)) player)(equal (nth 2 (nth 2 board)) player))
		t
	)
	; check diagonal right-left
	(if (and (equal (nth 2 (nth 0 board)) player)(equal (nth 1 (nth 1 board)) player)(equal (nth 0 (nth 2 board)) player))
		t
	)
)
(defun gameOver()
	(loop for x in board
		do(loop for y in x
			;do (print y)
		)
	)
)