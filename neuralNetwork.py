def neuralNetwork():
	persons = [1,1,0,1,1],[1,1,1,0,1],[0,0,1,0,1],[0,1,0,1,0],[1,0,1,1,1],[0,1,1,1,0] #The six people we're comparing
	indexWeight = [0.5,0.5,0.5,0.5] #Preset weight for each column
	score = 0			  #Score of each individual being evaluated (reset before each person evaluation)
	threshold = 0.5		  #Point limit that must be met to give the individual a pass, or 'yes'
	numCorrect = 0		  #Number of people evaluated correctly
	genCount = 0		  #Number of generations (Automatically increments at least once)
	while(numCorrect < 6 and genCount < 40): #Here's where the actual neural network begins. As long as we haven't successfully evaluated all 6 people AND the 40 generation limit hasn't been hit,
		genCount += 1						 #we keep running through the network
		numCorrect = 0
		for person in persons:
			score = 0
			for attribute in range(0,(len(person) - 1)):
				score += person[attribute] * indexWeight[attribute]
			if (score >= threshold and person[4] == 1) or (score < threshold and person[4] == 0): #If our weighted guess was right, increment numCorrect
				numCorrect += 1
			else:	#If our guess was wrong, we need to increment weights accordingly so that we score better the next time
				numCorrect = 0
				if score >= threshold: #If score was wrongfully 'yes', we need to decrement the weights to not be as intense next time.
					for attribute in range(0,(len(person) - 1)):
						if person[attribute] == 1:
							indexWeight[attribute] -= 0.05
				elif score < threshold: #If score was wrongfully 'no', the inverse is true; weights need to increase to be more notable next time.
					for attribute in range(0,(len(person) - 1)):
						if person[attribute] == 1:
							indexWeight[attribute] += 0.05
				else:
					print("Error in weight incrementation.")
					return
	displayResults(threshold, numCorrect, genCount, indexWeight) #When we fulfill either of the while loop's conditions, we cut out of the loop and display what we have

def displayResults(threshold, numCorrect, genCount, indexWeight):
	print 'Threshold: ',threshold
	print 'Number of correct evaluations: ',numCorrect
	print 'Number of generations: ',genCount
	for weight in range(0,len(indexWeight)):
		print 'Weight for condition #',weight+1,': ',indexWeight[weight]

neuralNetwork()		#Lastly, this is simply where we call the neural network function