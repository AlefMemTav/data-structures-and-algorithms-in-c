<h1 align="center">📄 README</h1>

# Data structures
This repository contains implementations of various data structures in the C programming language. The following data structures are currently available:

- Bubble Sort
- Merge Sort
- Quick Sort
- Quick Select
- Singly Linked List
- Hash Table
- Heap
- Binary Search tree
- Balanced Binary Search tree (AVL, Red Black)
- Undirected Graph (Adjacency List, Adjacency Matrix)
- Directed Graph (Adjacency List, Adjacency Matrix)

## Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The algorithm is named for the way smaller or larger elements "bubble" to the top of the list.

## Quick Sort

Quick Sort is a fast sorting algorithm that uses a divide-and-conquer strategy to sort an array. It picks an element as a pivot and partitions the array around the pivot, such that all elements less than the pivot come before it and all elements greater than the pivot come after it. The pivot element is then placed in its final position and the algorithm is recursively applied to the sub-arrays.

## Quick Select

Quick Select is an efficient algorithm to find the k-th smallest element in an unsorted array of n elements. It is similar to Quick Sort, but instead of recursing into both sides, it only recurses into one side.

## Singly Linked List

A singly linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. Each element of a linked list consists of two parts: the data and a reference to the next element.

#### Time Complexity (Average and Worst)
|Access|Search|Insertion|Deletion|
|---|---|---|---|
|O(n)|O(n)|O(1)|O(1)|

|Space Complexity (Worst)|
|---|
|O(n)|

#### Insertion at the beginning:

1 - The first time the singly linked list points to NULL:

<img src="./assets/singlylinkedlist-firsttime.png" height="100">

2 - When inserting the node with value 10, it becomes the new header of the list:
<img src="./assets/singlylinkedlist-insert10.png" height="100">

3 - The new node that succeeds node 10 will become the header of the list:
<img src="./assets/singlylinkedlist-insert20.png" height="100">

## Hash Table

A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

## Linear-probing and Separate-chaining
#### Time Complexity (Average)
|Access|Search|Insertion|Deletion|
|---|---|---|---|
|O(1)|O(1)|O(1)|O(1)|

#### Time Complexity (Worst)
|Access|Search|Insertion|Deletion|
|---|---|---|---|
|O(n)|O(n)|O(n)|O(n)|

|Space Complexity (Linear-probing)|
|---|
|O(n)|

|Space Complexity (Separate-chaining)|
|---|
|O(m+n)|

# Heap

# Binary Search tree

# Graph 

## Adjacency List
#### Time Complexity (Average and Worst)
|Insertion|Deletion|
|---|---|
|O(1)|O(1)|

|Space Complexity|
|---|
|E+V|

## Adjacency Matrix

#### Time Complexity (Average and Worst)
|Insertion|Deletion|
|---|---|
|O(1)|O(1)|

|Space Complexity|
|---|
|V*V|

# Running the Program
To run the program, you will need to have a C compiler installed on your machine, such as GCC or Clang.
