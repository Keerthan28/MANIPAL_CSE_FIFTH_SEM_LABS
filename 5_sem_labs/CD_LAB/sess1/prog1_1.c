#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *fptr1;
  char filename[100], c;

  printf("Enter the filename to open for reading: \n");
  scanf("%s", filename);

  fptr1 = fopen(filename, "r");
  if (fptr1 == NULL){
    printf("Cannot open file %s \n", filename);
    exit(0);
  }
  int chars=0, lines=0;
  do{
    c = fgetc(fptr1);
    printf("%c\n",c);
    chars++;
    if(c=='\n')
      lines++;
  }while (c != EOF);
  printf("Characters: %d\nLines: %d\n",chars, lines);
  fclose(fptr1);
  return 0;
}
