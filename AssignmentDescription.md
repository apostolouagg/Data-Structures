# Data Structures Assignment 1 2020-2021

As part of the assignment, you are asked to write a C++ program that solves the following problem:
You are given a set of k linear lists Li, i = 0, 1, 2, ..., k-1. In the context of this assignment, you should use the linked representation for the linear lists. For details, refer to Chapter 3.4 of the book "Data Structures, Algorithms, and Applications in C++."
The data in each node for all lists Li consists of an integer number. It is not necessary for all lists to contain the same number of nodes, and it is allowed for the same number to appear more times in each list. However, the use of ready-made data structures provided by C++ (C++ Containers) is not allowed.
The purpose of the program you will create is to create a new output list in which the elements of Li that appear in at least half of the lists will be placed. Each such element should appear only once in the output list, and all elements of the output list should be sorted in ascending order.
At the end of the program, the initial lists Li do not necessarily have to be in the same state as they were at the beginning of the program. You are allowed to remove any elements you want from each list Li or rearrange elements within each list Li during the execution of the algorithm. However, you are not allowed to process the lists Li in advance, e.g., you are not allowed to sort the lists at the beginning of the program.
The fact that you are allowed to modify the lists Li and that the output list must be sorted gives you the opportunity to optimize your algorithm by minimizing the number of comparisons required until the final construction of the output list. Try to think of and implement such optimizations in your algorithm.
The following diagram is provided for clarification of details. For example, although the number 11 appears several times overall, it appears only in two lists (less than half) and therefore should not be included in the output list. In contrast, the number 33 appears only three times, but it appears in three different lists (more than half) and therefore should be included in the output list. Finally, note that the elements in the output list are sorted.
Implementation Issues:
- The number k of lists should be read by your program during runtime. Therefore, the structure that will store the set of lists Li should be dynamically constructed during runtime.
- Subsequently, your program should construct the lists. For each list Li, its size (the number of nodes it will consist of) should be defined, and for each node, the number it will contain as data should be defined. For this purpose, a random number generator can be used. C++ provides a set of classes and methods for this purpose (see https://www.cplusplus.com/reference/random). To use these capabilities, you should:
o Include the header files <random> and <functional> in your program:
#include <random>
#include <functional>
o Define a random number generator:
std::default_random_engine generator;
o Define the allowable limits and the distribution for the generated random numbers. With the following declarations, we request that for the size of each list, a uniform distribution be used, and the generated numbers be integers in the range [100, 200] (i.e., the size of each list to be between 100 and 200 elements), while for the number that each node will contain, we again request a uniform distribution, and the generated numbers to be integers in the range [0, 50]. You are free to change these limits:
std::uniform_int_distribution<int> list_size_distribution(100, 200);
std::uniform_int_distribution<int> data_element_distribution(0, 50);
o For ease of use, you can 'bind' the random number generator with the desired distribution:
auto random_list_size = std::bind(list_size_distribution, generator);
auto random_element = std::bind(data_element_distribution, generator);
o Each time you call random_list_size() and random_element(), a random number will be generated based on the distribution and limits you have defined. For example, with the following calls, a random number for the size of a list in the range [100, 200] and a random number in the range [0, 50] that can be used as data for a node in a list are generated:
int list_size = random_list_size();
int data_element = random_element();
- As mentioned earlier, from the moment the lists Li are created using random numbers, you are not allowed to manipulate them until your algorithm for constructing the output list starts.
Deliverables:
The source code should be delivered along with the executable. Special emphasis should be placed on the proper documentation of your programs. Therefore, your code should be accompanied by a separate text providing a detailed description of your techniques. Also, within the source code, 'dense' comments of substance should be included. The submission of assignments will be done through gunet.
The assignment can be carried out by a team of up to two people strictly.
