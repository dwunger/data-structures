Homework: Applying Best Practices for Pointers and Structures in C

Objective:
Modify the code from the lecture to incorporate the best practices discussed, including using guard functions for memory allocation, employing a "self" parameter for methods that modify a structure, and ensuring proper memory ownership.

Instructions:
1. Starting with the `Point` structure and related functions from the lecture, modify `point.h` and `point.c` to include:
   - A `point_create` function that allocates a new `Point` on the heap and initializes it with given `x` and `y` values.
   - A `point_destroy` function that frees the memory allocated for a `Point`.

2. Update the `point_offset` function to use a "self" parameter for the `Point` being modified.

3. In `main.c`:
   - Replace the direct memory allocation for `a` with a call to `point_create`.
   - Use your `oom_guard` function for all heap memory allocations.
   - Ensure that all allocated memory is properly freed using `point_destroy`.

4. Compile and run your program, ensuring it runs without memory leaks (you can use a tool like `valgrind` for this).

5. Submit your updated C source and header files.

Rubric:
- Correct implementation of `point_create` and `point_destroy`: 3 pts
- Proper use of `oom_guard` for all heap allocations: 2 pts
- Updating `point_offset` to use a "self" parameter: 2 pts
- Demonstration of usage in `main.c`: 2 pts
- Proper memory management (no leaks): 3 pts
- Code is well-commented and readable: 1 pt
