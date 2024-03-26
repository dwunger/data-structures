Homework: Implementing a Simple String Library in C

Objective:
Write a C library that provides basic string manipulation functions, following the best practices discussed in the lecture. This includes:
- Using pointers to structures in function parameters
- Employing a "self" parameter for methods that modify a string
- Ensuring proper memory management and ownership

Instructions:
1. Define a `String` structure in `string.h` that contains:
   - A `char` pointer `data` to hold the string data
   - An `int` `length` to store the length of the string

2. Implement the following functions in `string.c`:
   - `String* string_create(const char* str)`: Creates a new `String` from a C-style string, allocating memory for the `data` field.
   - `void string_destroy(String* self)`: Frees the memory allocated for the `data` field of a `String`.
   - `void string_append(String* self, const String* other)`: Appends the `data` of `other` to `self`, reallocating memory if necessary.
   - `int string_compare(const String* str1, const String* str2)`: Compares two `String`s lexicographically.
   - `void string_print(const String* self)`: Prints a `String` to the console.

3. In `main.c`, demonstrate the usage of your `String` library:
   - Create two `String`s from C-style strings
   - Print both `String`s
   - Append one `String` to the other
   - Print the resulting `String`
   - Compare the two original `String`s
   - Destroy all `String`s

4. Compile and run your program, ensuring it runs without memory leaks (you can use a tool like `valgrind` for this).

5. Submit your C source and header files.

Rubric:
- Correct implementation of `String` structure: 2 pts
- Correct implementation of `string_create` and `string_destroy`: 3 pts
- Correct implementation of `string_append`, `string_compare`, and `string_print`: 3 pts
- Demonstration of usage in `main.c`: 2 pts
- Proper memory management (no leaks): 3 pts
- Code is well-commented and readable: 2 pts

---

Pointers and Structures in C Quiz

1. What is the main benefit of using pointers to structures in function parameters?
   a) It allows the function to modify the original structure
   b) It makes the code run faster
   c) It reduces memory usage
   d) It makes the code more readable

2. What is the purpose of the "self" parameter in methods that modify a structure?
   a) To provide a reference to the structure being modified
   b) To create a new copy of the structure
   c) To compare the structure with another one
   d) To free the memory allocated for the structure

3. Who is responsible for freeing memory allocated by a function?
   a) The function that allocated the memory
   b) The caller of the function
   c) The operating system
   d) The compiler

4. What is an "owning pointer"?
   a) A pointer that points to itself
   b) A pointer that points to another pointer
   c) A pointer that is responsible for freeing the memory it points to
   d) A pointer that cannot be modified

5. What can happen if you free a pointer that was not allocated by your code?
   a) Nothing, it's a no-op
   b) It will always crash your program
   c) It can corrupt the heap, leading to undefined behavior
   d) It will make your program run faster

Answers:
1. a
2. a
3. b
4. c
5. c