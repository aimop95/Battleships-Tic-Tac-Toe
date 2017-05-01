import random
import sys


fullList = []
studentList = [[1,1,0,1,1],[1,1,1,0,1],[0,0,1,0,1],[0,1,0,1,0],[1,0,1,1,1],[0,1,1,1,0]]
def createSequence(): #Generates random rules.
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

def ruleTesting(studentSequence,test): #Select one rule and one sequence, and check to see if they match
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
			score+=1 #Columns with hashes ('#') always considered the fields below them as true, regardless of what's actually put in them.
		
		count+=1
	if studentSequence.index(4)==1 and score>2: #Checks to see if the computer guessed the resolution of the rule correctly.
		return true								#For example, if the sequence matches the rule perfectly, the score should be 4,
	else:										#and it should guess the fifth position in the rule list as '1', or True
		return false


def testing(): #TODO: Incomplete testing function
	testingList = []
	for i in range (10):
		testingList.append(createSequence())


