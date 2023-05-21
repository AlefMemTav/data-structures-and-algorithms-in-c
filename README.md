<h1 align="center">📄 README</h1>

# Data structures 2
This repository contains implementations of various data structures in the C programming language. The following data structures are currently available:
- Bubble Sort
- Hash Table
- Linked List
- Quick Select
- Quick Sort

## Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The algorithm is named for the way smaller or larger elements "bubble" to the top of the list.

## Hash Table
A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

## Linked List
A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. Each element of a linked list consists of two parts: the data and a reference to the next element.

## Quick Select
Quick Select is an efficient algorithm to find the k-th smallest element in an unsorted array of n elements. It is similar to Quick Sort, but instead of recursing into both sides, it only recurses into one side.

## Quick Sort
Quick Sort is a fast sorting algorithm that uses a divide-and-conquer strategy to sort an array. It picks an element as a pivot and partitions the array around the pivot, such that all elements less than the pivot come before it and all elements greater than the pivot come after it. The pivot element is then placed in its final position and the algorithm is recursively applied to the sub-arrays.

# Running the Program
To run the program, you will need to have a C compiler installed on your machine, such as GCC or Clang.

#### Steps

1. Clone the repository to your local machine using Git:

```
git clone https://github.com/AlefMemTav/estruturas-de-dados-2.git
```

#### If you want compile an specific code

  2. Navigate to the directory of the data structure you want to use:

  ```
  cd estruturas-de-dados-2/LinkedList
  ```

3. Compile the code using the C compiler:

```
gcc linkedlist.c -o linkedlist
```

4. Run the executable:

```
./linkedlist
```

This will run the program and output the results to the terminal. You can modify the source code to change the input or output as desired.

#### Else if you want compile all codes

2. Navigate to the project directory:

```
cd estruturas-de-dados-2/
```

3. Compile the code:

```
gcc bubble_sort.c -o bubble_sort
gcc hash_table.c -o hash_table
gcc linked_list.c -o linked_list
gcc quick_select.c -o quick_select
gcc quick_sort.c -o quick_sort
```

4. Run a program:

```
./bubble_sort
```

# License
This repository is licensed under the MIT license. See the LICENSE file for more details.
