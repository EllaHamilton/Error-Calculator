#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int copytoclipboard(const char *str) {

    const char proto_cmd[] = "echo '%s' | pbcopy";

    char cmd[strlen(str) + strlen(proto_cmd) - 1]; // -2 to remove the length of %s in proto cmd and + 1 for null terminator = -1
    sprintf(cmd ,proto_cmd, str);

    return system(cmd);
}

int main()
{
    char str[50];
    float value1, value2;
    float uncertainty1, uncertainty2, uncertaintyTotal;
    float valueUnkown;
    float answer = 0;

    printf("What operation?\n");
    printf("1: Addition/Subraction\n");
    printf("2: Multiplication/Division\n");
    scanf("%f", &answer);
    printf("Enter the first value: ");
    scanf("%f", &value1);
    printf("enter the uncertainty: ");
    scanf("%f", &uncertainty1);
    printf("Enter the second value: ");
    scanf("%f", &value2);
    printf("enter the uncertainty: ");
    scanf("%f", &uncertainty2);
    printf("Enter the unknown value: ");
    scanf("%f", &valueUnkown);
    if (answer == 1) {
        uncertaintyTotal = uncertainty1 + uncertainty2;
        printf("The total uncertainty is %f\n", uncertaintyTotal);
    }
    else if (answer == 2) {
        uncertaintyTotal = ((uncertainty1/value1)+(uncertainty2/value2))*valueUnkown;
        printf("The total uncertainty is %f\n", uncertaintyTotal);
    }
    sprintf(str, "%f", uncertaintyTotal);
    copytoclipboard(str);
    //Made a new version? use this!
    //clang main.c -o ErrorCalculator

    exit(0);
}