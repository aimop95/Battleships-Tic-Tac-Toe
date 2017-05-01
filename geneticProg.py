import random
import sys


fullList = []
studentList = [[1,1,0,1,1],[1,1,1,0,1],[0,0,1,0,1],[0,1,0,1,0],[1,0,1,1,1],[0,1,1,1,0]]
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
	return seq

def ruleTesting(studentSequence,test):
	count = 0
	score = 0
	for i in test:
		if i != '#':
			if studentSequence.index(count) == 0 and i == 'F':
				score +=1
			if studentSequence.index(count) == 1 and i == 'T':
				score +=1
			else:
				score -=1
		else:
			score+=1
		
		count+=1
	if studentSequence.index(4)==1 and score>2:
		return true
	else:
		return false


def testing():
	testingList = []
	for i in range (10):
		testingList.append(createSequence())


