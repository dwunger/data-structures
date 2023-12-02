/*

    Confused turing incomplete ramblings

    Create a device that can OR, NAND, NOR or AND two inputs.
    The third input will be the instruction. An instruction is just
    what we call the number that determines what to compute.

First impressions
TODO:
Create a byte decoder
Decode operation code*
Perform all operations (if there is no penalty for doing so)
Toggle the associated instruction's output switch

*Decoding an operation simply means that a unique input byte
will map to a unique operation on board. Assumption: 
if each operation is purely combinational (as opposed to sequential 
operations whose outputs rely on retention of state), output will 
always be yielded in time with the input, and as such, will not
need to manage any internal state. This is important as such responsibity 
could be offloaded to another portion of the circuit.

Instructions:
0 OR
1 NAND
2 NOR
3 AND
*/

#include <stdio.h>
/*Pointers were chosen to parallel physical connection between 
 *inputs and instruction circuitry*/
char logic_engine(char *opcode, char *input_0, char *input_1);

int main(void) {
    // Initialize an output for the logic engine
    // This is a language paradigm, not relevant to the circuit
    // Hardware output state is off by default
    char output = 0;

    // Two byte-sized inputs
    char i0 = 0b00000000;
    char i1 = 0b11111111;

    // Set the current instruction
    char op = 0;

    // Pass instruction to logic engine
    output = logic_engine(&op, &i0, &i1);

    printf("%d", (unsigned char)output);

    return 0;
}



char logic_engine(char *opcode, char *input_0, char *input_1)
{
    if (!(*opcode)) {
        return *input_0 | *input_1;
    }
    // and the others . . .

}

