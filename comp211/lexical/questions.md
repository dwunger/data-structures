
a) What is the purpose of the 'valid' boolean variable? How does it impact what kind of Token is returned from the function?
- The function initially makes the assumption that all tokens beginning with `l` are of the `LOL` type. The function iterates over the input stream, and if at any point while consuming characters of the token, it fails to meet the minimum criteria to constitute a `LOL`, it updates the valid flag to false to indicate it is not of the `LOL` type.

b) Explain the logic and sequence of checks that determine if an input matches the 'lol' token pattern. How does the function handle invalid matches?
- As summarized in the previous, we begin by assuming any token starting with `l` is a valid `LOL` token. The function peeks at the next character; if it still indicates the pattern may continue (next character = `o`), it consumes the character and increments its length; otherwise, it falls through the remaining logic and begins to construct an `ERROR` token. In the valid case, once the base case of `lol` is satisfied, the token may consume any arrangement of exclusively `o` and `l` until no more contiguous 'l's and 'o's remain. A compound type is then constructed with a pointer to the start of the `LOL` or `ERROR` token and its length. Said token is then emitted and printed in the while loop from `main`.

c) Why does the function continue consuming characters in a while loop after matching the 'lol' prefix? What part of the 'lol' regular expression definition does this correspond to?
The first part is difficult to answer in any way other than just reading the code itself or writing in plain English:

```
while ((peek(*itr) == 'o' || peek(*itr) == 'l')) {
    next(itr); // consume the character
    length += 1;
}
```

It peeks and increments the pointer if it matches `l` or `o` until the first case in which that fails.
This behavior corresponds to the `[ol]*` character class in the regular definition.

d) At the end of the function, a Slice location is populated. Explain in your own words what the 'start' and 'length' fields of the Slice represent and how they are determined.
start - is the address of the first `l` in the LOL token.
length - the size of the LOL token in bytes, not including a null terminator (as the LOL token may terminate before the line it which it resides does).

Examine the peek, has_next, and next functions.
a) Why is it useful for the tokenizer to have access to a 'peek' function that lets it look ahead at the next character without consuming it?
Prematurely advancing the pointer could cause the caller to lose the beginning of a valid subsequent token, when the callee should not consume the next character. The callee needs to know the next character's content before deciding if it belongs to the current token or a subsequent one.

b) How does the tokenizer leverage the has_next function?
It encapsulates the `fgets` implementation details and null termination behind a simple function name, preventing buffer overrun without cluttering the core program logic. This is effectively nothing more than a stylistic choice. The compiler may even inline this check removing the need to save registers' states and perform stack cleanup after the call.

Describe how you would need to modify the tokenizer to support multi-digit integers in addition to single digit tokens. What would need to change in the take_digit function and main's switch statement?
take_digit would need a `peek` and `consume` loop as implemented in the take_lol helper function. The fixed slice length of 1 would need to become dynamic and incremented upon consumption. I think the change to the switch statement is a trick question since advancing the pointer and storing the token in string format is all handled in the helper function implementation.

The take_error function currently just consumes a single character when an unexpected input is seen. How would you extend it to consume all invalid characters up until the next potentially valid token? Explain how you would implement this.
A peek and consume loop which consumes if the next character is neither a digit nor `l`. Since a LOL token cannot begin with `o`, if peek sees an `o` in an error token, it would consume the `o`.

