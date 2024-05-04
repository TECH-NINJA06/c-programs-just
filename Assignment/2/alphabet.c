#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    (ch >= 'a' && ch <= 'z') ? printf("%c is a lowercase alphabet.\n", ch) : printf("%c is not a lowercase alphabet.\n", ch);
    islower(ch)?printf("\nlowercase letter"):printf("\nNope");
    return 0;
}
