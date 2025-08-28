// Taking input

#include <stdio.h>

int main(void){
    int num;
    float dec;
    char letter;
    
    printf("Please enter a number: ");
    scanf("%d",&num);
    
    printf("Please enter a decimal number: ");
    scanf("%f",&dec);
    
    printf("Please enter a letter: ");
    scanf(" %c",&letter);
    
    
    printf("Number: ");
    printf("%d\n",num);
    
    printf("Decimal number: ");
    printf("%f\n",dec);
    
    
    printf("Letter: ");
    printf("%c\n",letter);

    return 0;
}
