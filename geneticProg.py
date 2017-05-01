import random
import sys

def createSequence():
	seq = []
	for i in range (4):
		randNum=random.randrange(3)
		if randNum == 0 :
			seq.append('T')
		if randNum == 1 :
			seq.append('#')
		if randNum == 2 :
			seq.append('F')
	print seq
	#sys.stdout.flush()
createSequence()
