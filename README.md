# Linked Lists Assignment: Process Scheduling and Prime Number Calculation

## Table of Contents
1. [Overview](#overview)
2. [Approach](#approach)
   - [Problem 1: CPU Process Scheduling Algorithm](#problem-1-cpu-process-scheduling-algorithm)
   - [Problem 2: Very Large Prime Number Calculation](#problem-2-very-large-prime-number-calculation)
3. [Assumptions](#assumptions)
4. [Challenges](#challenges)
5. [File Structure](#file-structure)
6. [How to Run](#how-to-run)
7. [Sample Output](#sample-output)
   - [Problem 1 Output](#problem-1-output)
   - [Problem 2 Output](#problem-2-output)
8. [Contributors](#contributors)

## Overview
This project contains two distinct implementations using linked lists:
1. **CPU Process Scheduling Algorithm**: Implements a simple CPU scheduling mechanism using a circular linked list.
2. **Very Large Prime Number Calculation**: Stores a 1024-bit number across multiple nodes of a singly linked list and checks for its primality.

Both implementations demonstrate the use of linked lists for managing dynamic data structures in real-time applications.

## Approach

### Problem 1: CPU Process Scheduling Algorithm
* **Circular Linked List**: This implementation utilizes a circular linked list where each node represents a process. Each process contains attributes such as `process_id`, `execution_time`, and `remaining_time`. The scheduling algorithm assigns a fixed quantum of CPU time to each process, cycling through the list until all processes are completed.
* **Dynamic Process Insertion**: The algorithm supports the insertion of new processes during runtime without interrupting the schedule.
* **Scheduler Logic**: The CPU assigns time slices (quantum) to each process in a round-robin fashion. Once a process’s `remaining_time` reaches zero, it is removed from the list.

### Problem 2: Very Large Prime Number Calculation
* **Singly Linked List**: The large number (1024-bit or smaller) is stored across multiple nodes in the linked list, where each node holds a segment of the number. This segmentation ensures efficient memory usage while handling extremely large numbers.
* **Primality Test**: The algorithm uses a basic primality test that operates across the segments stored in the linked list. It combines these segments to evaluate whether the large number is prime.

## Assumptions
* For **Problem 1**: A fixed CPU time quantum of 3 units is used.
* For **Problem 2**: A 1024-bit number is divided into 64-bit segments and stored in a linked list.

## Challenges
* **Memory Management**: Handling very large numbers in **Problem 2** required careful memory management, as traditional data types cannot store such large values directly.
* **Dynamic Process Handling**: In **Problem 1**, allowing new processes to enter the schedule dynamically without interrupting the ongoing execution was complex to implement.
* **Optimizing Primality Testing**: For **Problem 2**, efficiently testing the primality of such large numbers while using linked lists was a challenge. Traditional primality tests were optimized to ensure the program remained performant.

## File Structure
Here’s a quick breakdown of the files included in the repository:
1. `t1.cpp`: The implementation of the CPU Process Scheduling Algorithm using a circular linked list.
2. `t2.cpp`: The implementation of the Very Large Prime Number Calculation using a singly linked list.

## How to Run
1. Clone the repository to your local machine.
2. Compile and run `t1.cpp` for the Process Scheduling Algorithm:
3. Compile and run `t2.cpp` for the Prime Number Calculation:


## Contributors
* Mohammad Umar - Implemented both linked list solutions.
