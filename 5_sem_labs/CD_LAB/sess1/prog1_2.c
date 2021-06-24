#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strev(char *c){
  int n = strlen(c);
  char s[n];
  strcpy(s, c);
  for(int i=0; i<n; i++)
    c[i] = s[n-i-1];
}

int main(){
  FILE *fptr1, *fptr2;
  char filename[100];

  printf("Enter src file: \n");
  scanf("%s", filename);

  fptr1 = fopen(filename, "r");
  if (fptr1 == NULL){
    printf("Cannot open file %s \n", filename);
    exit(0);
  }

  printf("Enter dest file: \n");
  scanf("%s", filename);

  fptr2 = fopen(filename, "w");
  if (fptr2 == NULL){
    printf("Cannot open file %s \n", filename);
    exit(0);
  }

  char c[1500];
  int i=0;
  while(!feof(fptr1))
     c[i++] = fgetc(fptr1);
  strev(c);
  fprintf(fptr2,"%s",c);
  printf("Reversed string stored to %s\n",filename);

  fseek(fptr1, 0L, SEEK_END);
  printf("Size of file: %ld\n", ftell(fptr1));

  fclose(fptr1);
  fclose(fptr2);
  return 0;
}
