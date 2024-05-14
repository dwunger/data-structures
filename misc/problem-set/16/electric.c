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
#include <string.h>
typedef struct Customer {
    char *name;
    int identifier;
    int cycle_energy_consumption;
} CUSTOMER;

CUSTOMER *new_customer(char *input_name, int input_uid, int input_monthly_consumption)
{
    // Allocate memory for Customer struct
    CUSTOMER *abstract_customer = malloc(sizeof(CUSTOMER));

    if (abstract_customer == NULL) {
        fprintf(stderr, "Failed to allocate memory");
        return 0;
    }

    strcpy(abstract_customer -> name, input_name);
    abstract_customer -> identifier = input_uid;
    abstract_customer -> cycle_energy_consumption = input_monthly_consumption;

    return abstract_customer;
}

int main(void)
{

    char *name = "David";
    int uid = 0xFFFFFF;
    double consumption = 365; 
    
    CUSTOMER *customer = new_customer(name, uid, consumption);
    
    // Construct a customer
    printf("Customer Name: %s\n", (*(customer)).name);
    printf("Customer ID: %d\n", (*(customer)).identifier);
    printf("Energy Cons: %d\n", (*(customer)).cycle_energy_consumption);
    return 0;
}
