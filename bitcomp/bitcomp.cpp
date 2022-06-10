#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int count = 0;
	char c1;
	char c2;
	FILE *file1;
  	FILE *file2;
  	file1 = fopen(argv[1], "r");
  	file2 = fopen(argv[2], "r");
  	do {
      c1 = getc (file1);
      c2 = getc (file2);
      if(c1 != EOF && c2 != EOF){
      	for (int i = 7; i >= 0; i--)
    	    if(((c1 >> i) & 1) ^ ((c2 >> i) & 1)==1){
    	    	count++;
    	    }
      }
      else{
      	count = count + 8;
      }
    } while (c1 != EOF || c2 != EOF);
    count = count-8;
    printf("%d bit(s) are different.\n",count);
    fclose(file1);
    fclose(file2);
    return 0;
}
