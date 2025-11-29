#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr;

    char filename[] = "document.html";

    fptr = fopen(filename, "w");

    if(fptr == NULL){
        printf("\n Couldn't open the File!");
        return 1;
    }

    fprintf(fptr, "\n Hello World <br>");
    fprintf(fptr, "\n I'm Balaji <br>");
    fprintf(fptr, "\n This HTML page is created using C \n");

    fclose(fptr);

    printf("\n File %s Created Successfully .\n",filename);

    system("start document.html"); // So this will open the files in the default extension of the files.

    return 0;
}  