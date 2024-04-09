Homework: Implementing and Testing the `copy` Function

Objective:
Implement the `copy` function to copy a block of memory from a source location to a destination location, and write unit tests to verify its correctness.

Instructions:
1. Open the `copy.c` file in the `src` directory and implement the `copy` function according to the following requirements:
   - The function should copy `num` bytes from the memory location pointed to by `source` to the memory location pointed to by `destination`.
   - The function should return the `destination` pointer.
   - The function should work correctly for any type of data, not just strings.

2. Open the `copy.cpp` file in the `test/unit` directory and implement additional unit tests for the `copy` function:
   - Test copying an array of integers.
   - Test copying a struct.
   - Test copying 0 bytes (should be a no-op).
   - Test copying when `source` and `destination` overlap (should work correctly).

3. Run the unit tests using `make unit-test` and ensure all tests pass.

4. Open the `main.c` file in the `src` directory and add code to demonstrate using the `copy` function:
   - Declare and initialize an array of integers.
   - Declare another array to be the destination.
   - Use `copy` to copy the integers from the source array to the destination array.
   - Print both arrays to verify the copy worked correctly.

5. Compile and run the program using `make run` and verify the output is as expected.

6. (Bonus) Write an integration test in `test/integration/copy.bats` that runs the program with different inputs and verifies the output is correct.

7. Ensure all code is properly formatted and commented.

8. Submit your code (`copy.c`, `copy.cpp`, `main.c`, and `copy.bats` if you did the bonus) via the course portal.

Rubric:
- Correctness of `copy` implementation: 40%
- Thoroughness and correctness of unit tests: 30%
- Demonstration of `copy` usage in `main.c`: 10%
- Code formatting and comments: 10%
- Bonus integration test: 10%