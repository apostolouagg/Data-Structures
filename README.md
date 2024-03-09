# Data Structures Project
### PDF: [Data Structures Project.pdf](https://github.com/apostolouagg/Data-Structures/files/14547223/Data.Structures.Project.pdf)


Initially, we create 2 structures, one for the initial linked lists and the other for the final linked list output, and declare an integer variable named plListwn which will represent the number of lists. We ask the user to input how many lists they want and pass this number to another variable, int plListwn2, because we will modify plListwn later, but we need to keep track of the total number of lists. We use srand(time(0)) to generate random numbers based on time, so the sizes of the lists and the data within them are almost randomly assigned. Then, for the first linked list, we have n to create new nodes, temp to assist in node linking, and HEADS[plListwn], which is an array storing the heads of the lists. 

We start a loop that runs as many times as the number of lists. Using int list_size, we get the random size of the list, then with the help of n, temp, and HEADS[plListwn], we create the first node (head), and then with a for loop, we create the remaining nodes, assigning random numbers to their data. When the for loop finishes, we add a NULL as the last element of the list and then display it.
