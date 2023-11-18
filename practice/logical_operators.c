// Goal: Formalize consistent grammatical construction for logical operators
// Validate construction in code.
#include <stdio.h>

int AND(int input1, int input2);

int main(void) 
{
    // ===AND===
    puts("===AND===");
    // Expected: 
    // 0 1 0 1
    // 0 0 1 1
    // 0 0 0 1

    printf("%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n", 0, 1, 0, 1,
                                                      0, 0, 1, 1,
                                                      AND(0,0), AND(1,0),
                                                      AND(0,1), AND(1,1));
    return 0;
}



int AND(int input1, int input2)
{
    // [TRUE] <- IF input1 AND input2 ARE [TRUE] 
    // [RESULT] <- [condition qualifier] [argument(s)] 
    // Grammar:
    // [Adj.] <- [Conj.] [Adj(s).] [V.]
    
    // Construction:
    // IF input1 AND input2
    // AND creates a dependency
    // So input2 is nested in input1
    if (input1) {
        if (input2) {
            return 1;
        }
    } 
    return 0; 
    
    // C standard: 
    // return (input1 && input2);
}
    



