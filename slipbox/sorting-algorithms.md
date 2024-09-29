# Sorting Algorithm

Because in the first challenge of 2022 of Advent of Code, I considered that I need to sort an array and that I wanted to do in C, I add to learn about sorting algorithms. So based on the associated wikipedia [ page ](https://en.wikipedia.org/wiki/Sorting_algorithm), there's quite some of them. Therefore I choose to reimplement the classic QuickSort algo. Although this is not the top performance sorting algorithm -- like [block sort](https://en.wikipedia.org/wiki/Block_sort) seems to be -- it seems like a reasonnable performant algorithm with 3 simple building blocks. Hence its simplicity to implement.

## QuickSort algo

This sorting method requires 4 concepts: (i) the swapping of 2 elements in an array and (ii) the selection of a pivot and (iii) a partition method and (iv) recursion. An implementation of it is visible [ here ](../libs/algorithms.c). How to choose a pivot can vary from one implementation to another, but here I choose to use what seems the most efficient in general, which is the Median of Three selection method.
For the partition method, I choose the Hoare Partition.
