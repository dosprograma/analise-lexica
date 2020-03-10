#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char critInt[] = "^[0-9]*$";
char critFloat[] = "^[0-9]+\\.[0-9]+$";
char critSymb[] = "^[\\+|-|/|*|(|)|\\]*$";

int main()
{
    char str[] ="3 + 6 - 9 x 5 / 2 ++ 3 - 0";
    char * pstr;

    pstr = strtok (str," ");

	regex_t exprInt;
    regex_t exprFloat;
    regex_t exprSymb;

    regcomp(&exprInt, critInt, REG_EXTENDED);
    regcomp(&exprFloat, critFloat, REG_EXTENDED);
    regcomp(&exprSymb, critSymb, REG_EXTENDED);

    printf ("%s\n",str);

    while (pstr != NULL){

        printf ("%s ->     \t",pstr);
        if(regexec(&exprInt, pstr, 0, NULL, 0) == 0)
		    printf("Numero Inteiro\n");
	    else
            if(regexec(&exprFloat, pstr, 0, NULL, 0) == 0)
		        printf("Numero Real\n");
        else
            if(regexec(&exprSymb, pstr, 0, NULL, 0) == 0)
		        printf("Operador\n");
        else
            printf("Nao se aplica a expressao\n");
        pstr = strtok (NULL, " ");
    }
    
    return 0;
}