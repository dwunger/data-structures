Homework: Implementing Callbacks with Function Pointers in C

Objective:
Write a C program that demonstrates the use of function pointers to implement callbacks. You will write a function that performs a generic operation on an array of integers, using a callback function to define the specific operation.

Instructions:
1. Define two callback functions:
   - `int square(int n)`: Returns the square of `n`.
   - `int cube(int n)`: Returns the cube of `n`.

2. Write a function `void applyOperation(int *arr, int size, int (*operation)(int))` that takes:
   - An integer array `arr`
   - The size of the array `size`
   - A function pointer `operation` that points to a function which takes an integer and returns an integer

3. Inside `applyOperation`, iterate over the array and apply the `operation` function to each element, replacing the element with the result.

4. In the `main` function:
   - Declare and initialize an integer array
   - Print the array
   - Call `applyOperation` with the array, its size, and the `square` function as arguments
   - Print the modified array
   - Call `applyOperation` again with the same array, its size, and the `cube` function as arguments
   - Print the modified array again

5. Compile and run your program. Observe how the array is modified based on the callback function passed to `applyOperation`.

6. Submit your C source code file(s).

Rubric:
- Correct implementation of `square` and `cube` functions: 2 pts
- Correct implementation of `applyOperation`: 3 pts
- Correct usage of function pointers in `main`: 3 pts
- Program compiles and runs without errors: 1 pt
- Code is well-commented and readable: 1 pt
