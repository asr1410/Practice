#include <stdio.h>
#include <conio.h>
int main()
{

    char ch;
    printf("Enter a character ");
    ch = getch(); // taking an user input without showing the value.
    printf("value of ch is %c", ch);
    printf("Enter a character again ");
    ch = getche(); // taking an user input and then displaying it on the screen but the cursor remain on same row.
    printf("value of ch is %c", ch);
    ch = getchar(); //it take the value and then take cursor to new line
    return 0;
}