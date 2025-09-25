#include<stdio.h>

int findFourth(char val) {
    if ((val & 8) != 0) {
        return 1;
        
    } else {
        return 0;
    }
}

int displayBit(char val) {
    for (int i = 7; i >= 0; i--) {
        if (val & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}

int main() {
    char test1 = 8;
    char test2 = 4;
    
    
    printf("findFourth(%d) = %d\n", test1, findFourth(test1));
    printf("findFourth(%d) = %d\n", test2, findFourth(test2)); 


    printf("Bit pattern of %d: ", test1);
    displayBit(test1);
    printf("Bit pattern of %d: ", test2);
    displayBit(test2);


    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Result: %d\n", findFourth(num));
    
    printf("Bit pattern of %d: ", num);
    displayBit(num);

    return 0;
}