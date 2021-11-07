/*****************************************************
 * Command-line Calculator                           *
 * Author: Aleksandar Stankovic                      *
 * Date: 05.11.2021                                  *
 * Usage: calc.exe OPERAND_1 OPERATOR OPERAND_2      *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

void calculation(double first_number, double second_number, char* operator);
void help(void);

int main(int argc, char *argv[])
{
    /* check if enough arguments were passed */
    if (argc != 4)
    {
        printf("ERROR! 3 arguments expected...\n");
        help();
        exit(EXIT_FAILURE);
    }

    /* pass arguments to a variable */
    char* first_operand = argv[1];
    char* operator = argv[2];
    char* second_operand = argv[3];
    char* endptr;
    char* endptr2;
    
    /* convert string from cmd-line to double value */
    double first_number = strtod(first_operand, &endptr);
    double second_number = strtod(second_operand, &endptr2);

    /* check if the number is not a character 
     * if the pointer is not anymore at NULL then invalid char was passed */
    if (*endptr != 0) 
	{
		printf("Input argument 1 is NAN!\n");
        help();
		exit(EXIT_FAILURE);  
	}
    if (*endptr2 != 0) 
	{
		printf("Input argument 2 is NAN!\n");
        help();
		exit(EXIT_FAILURE);
	}
    calculation(first_number, second_number, operator);
    return 0;
}
void calculation(double first_number, double second_number, char* operator)
{  
    /* Addition */
    if (strcmp(operator, "+") == 0) 
    {
        printf("Sum: %f\n", first_number + second_number);
    }
    /* Subtraction */ 
    else if (strcmp(operator, "-") == 0)
    {
        printf("Diff: %f\n", first_number - second_number);
    }
    /* Division */
    else if (strcmp(operator, "/") == 0)
    {
        printf("Div: %f\n", first_number / second_number);
        if (second_number == (double)0)
        {
            printf("\tERROR! Divison by zero!\n");
            exit(EXIT_FAILURE);
        }
    }
    /* Multiplication */
    else if (strcmp(operator, "x") == 0)
    {
        printf("Mul: %f\n", first_number * second_number);
    }
    /* To the power of */
    else if (strcmp(operator, "xx") == 0)
    {
        printf("The Power Of: %f\n", pow(second_number, first_number));
    }
    /* arithmetic mean */
    else if (strcmp(operator, "m") == 0)
    {
        printf("Arithmetic Mean: %f\n", (first_number + second_number) / 2); 
    }
    /* n-th root of */
    else if (strcmp(operator, "_/") == 0)
    {
        if (second_number < 0)
        {
            printf("ERROR! Negative number not allowed!\n");
            exit(EXIT_FAILURE);
        }
        double radicant = second_number;
        int power = (int) first_number;
        printf("Root: %f\n", pow(radicant, 1.0 / power)); 
    }
    /* Sine */
    else if (strcmp(operator, "sin") == 0)
    {
        printf("Sine: %f\n", first_number * sin(second_number)); 
    }
    /* Cosine */
    else if (strcmp(operator, "cos") == 0)
    {
        printf("Cosine: %f\n", first_number * cos(second_number)); 
    }
    /* Tangens */
    else if (strcmp(operator, "tan") == 0)
    {
        printf("Tangens: %f\n", first_number * tan(second_number));
        if (second_number == 0)
        {
            printf("ERROR! tan(0)");
            exit(EXIT_FAILURE);
        }   
    }
    /* Modulo */
    else if (strcmp(operator, "%") == 0)
    {
        printf("Modulo: %d\n", (int)first_number % (int)second_number); 
    }
    else
    {
        printf("ERROR! Not a valid operator!\n");
        help();
        exit(EXIT_FAILURE);
    }
}
void help(void)
{
    printf("\nUsage: calc.exe OPERAND_1 OPERATOR OPERAND_2\n"
           "OPERAND_1 and OPERAND_2 shall be decimal numbers\n"
           "OPERATOR shall be one of the following strings:\n"
           "+, -, /, x, %%, _/, xx, m, sin, cos, tan\n\n");
}
