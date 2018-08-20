#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int checkinput(FILE * f){
  int c=0;
  int col =0;
  c=fgetc(f);
  while (!(c == EOF)){
    for(int i=0 ;i<10;i++){
      if(c == '\n'){
	fprintf(stderr,"char error");
	return 0;
      }
      c=fgetc(f);
    }
    if (c != '\n'){
      fprintf(stderr,"row err");
      return 0;
    }
    c=fgetc(f);
    col ++;
  }
  if(col == 10) return 1;
  else {
    fprintf(stderr,"column err");
    return 0;}
  
}

void rotate(char matrix[10][10]){
   for (int i = 0; i < 10 ; i++)   {
     for (int j = i; j < 10; j++) {
       char temp =matrix[i][j];
       matrix[i][j]=matrix[j][i];
       matrix[j][i]=temp;
     }
   }
   for (int i = 0; i < 10 ; i++)   {
     for (int j = 0; j < 5; j++) {
       char  temp =matrix[i][j];
       matrix[i][j]=matrix[i][9-j];
       matrix[i][9-j]=temp;
     }
   }
   return ;
 }

int main(int argc,char** argv){
   if (argc != 2){
     fprintf(stderr,"not correct number of argument \n");
     return EXIT_FAILURE;
   }
   FILE * f =fopen(argv[1],"r");
   if (f == NULL) {
     perror("Could not open file");
     return EXIT_FAILURE;
   }
   if (!(checkinput(f))) return EXIT_FAILURE;
       
  if (fclose(f) != 0) {
      perror("Failed to close the input file!");
      return EXIT_FAILURE;  }
   f =fopen(argv[1],"r");
   if (f == NULL) {
     perror("Could not open file");
     return EXIT_FAILURE;
   }
  
   char matrix[10][10];
   int c =0;
   for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
      c=fgetc(f);
      if (c == '\n') c=fgetc(f);
      matrix[i][j]=c;
    }}

   rotate(matrix);

   for (int x=0;x<10;x++){
      for (int y=0;y<10;y++){
	printf("%c",matrix[x][y]);
      }
      printf("\n");	
	}
    
  if (fclose(f) != 0) {
      perror("Failed to close the input file!");
      return EXIT_FAILURE;  }
    
  return EXIT_SUCCESS;
  
}
