#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *fptr1, *fptr2, *fptr3;
  char filename[100];

  printf("Enter src file 1: \n");
  scanf("%s", filename);
  fptr1 = fopen(filename, "r");
  if (fptr1 == NULL){
    printf("Cannot open file %s \n", filename);
    exit(0);
  }

  printf("Enter src file 2: \n");
  scanf("%s", filename);
  fptr2 = fopen(filename, "r");
  if (fptr2 == NULL){
    printf("Cannot open file %s \n", filename);
    exit(0);
  }

  printf("Enter dest file: \n");
  scanf("%s", filename);
  fptr3 = fopen(filename, "w");
  if (fptr3 == NULL){
    printf("Cannot open file %s \n", filename);
    exit(0);
  }

  char a,b;
  int flag=1;
  a = fgetc(fptr1);
  b = fgetc(fptr2);
  while (!feof(fptr1) && !feof(fptr2)){
    if(flag){
      fputc(a,fptr3);
      a = fgetc(fptr1);
      if(a=='\n')
        flag = 0;
    }
    else{
      fputc(b,fptr3);
      b = fgetc(fptr2);
      if(b=='\n')
        flag = 1;
    }
  }
  while (!feof(fptr1)){
    fputc(a,fptr3);
    a = fgetc(fptr1);
  }
  while (!feof(fptr2)){
    fputc(b,fptr3);
    b = fgetc(fptr2);
  }
  printf("Combined alternating files stored to %s\n",filename);

  fclose(fptr1);
  fclose(fptr2);
  fclose(fptr3);
  return 0;
}
