/*
16. An electric power distribution company charges its domestic consumers as follows:
- Consumption Units    Rate of Charge
- 0-200               Rs. 0.50 per unit
- 201-400             Rs. 100 plus Rs. 0.65 per unit excess of 200
- 401-600             Rs. 230 plus Rs. 0.80 per unit excess of 400.
Write a C program that reads the customer number and power consumed and prints the amount to be paid by the customer.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Customer {
    char *name;
    int identifier;
    int cycle_energy_consumption;
} CUSTOMER;

CUSTOMER *new_customer(char *name, int uid, int cycle_energy_consumption)
{
    
    return ptr_struct_customer;
}


int main(void)
{

    char *name = "David";
    int uid = 0xFFFFFF;
    double consumption = 365; 
    
    CUSTOMER *consumer = new_customer(name, uid, consumption);

    return 0;
}
