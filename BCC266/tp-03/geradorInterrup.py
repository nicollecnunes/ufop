from random import *

# -------------------------- Values --------------------------
def generator(fileName, tamanho, sizeFor, probability):
	size_memory = 1000 # RAM size

	instructions = tamanho # number of instructions generated
	size_block = sizeFor # size of each repetition block (size of 'for')
	probability = probability # probability of each block occur (probability of 'for' occur)

	num_words = 4 # number of words for each block
	n = 2 # number of available opcodes
	num_address = [3, 3] # number of addresses for each opcode evaluated from 0 to n-1

	# -------------------------- Code --------------------------
	separator = " "
	array = []
	repetition = []

	# repetition block
	for i in range(size_block):
		r_value = randint(0, n)
		s = ""
		for j in range(num_address[r_value - 1]):
			s = s + separator + str(randint(0, size_memory-1)) + separator + str(randint(0, num_words-1))
		repetition.append(str(r_value) + s)

	# print(repetition) # uncomment to view repetition block

	# iteration
	num_blocks = instructions / size_block;
	num_blocks_with_probability = (probability / 100.0 +0.0001) * (num_blocks) # "+0.0001" for round up
	i = 0
	k = 0
	while(i < instructions):
		if(k <= num_blocks_with_probability and i + size_block < instructions):
			i = i + size_block 	# increment number of instructions in each block to not exceed the total
			k = k + 1 			# increment 1 repetition block until the probability is satisfied
			array.extend(repetition)
		else:
			i = i + 1
			r_value = randint(1, n)
			s = ""
			for j in range(num_address[r_value - 1]):
				s = s + separator + str(randint(0, size_memory-1)) + separator + str(randint(0, num_words-1))
			array.append(str(r_value) + s)

	# print(array) # uncomment to view final array

	# -------------------------- File --------------------------
	file = open(fileName + ".txt", "w")

	# write the number of instructions at the begining of the file
	file.write(str(instructions))
	file.write("\n")

	# write the instructions
	for i in range(len(array)):
		file.write(array[i])
		file.write("\n")
		
	file.close()

def createInstructions(tamanhoFor, probability):
	fileName = "./instructions/INST_{0}_{1}".format(tamanhoFor, probability)
	generator(fileName, 10001, tamanhoFor, probability)

def createInterruptions():
	tamanhos = [101, 91, 81, 71, 61, 51, 41]
	for i in range(len(tamanhos)):
		fileName = './interruptions/INTR_0' + str(i)
		generator(fileName, tamanhos[i], 10, 70)

if __name__ == "__main__":
	createInstructions(10, 75)
	#createInterruptions()