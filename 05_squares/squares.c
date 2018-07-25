#include <stdio.h>
#include <stdlib.h>

int max (int x ,int y){
  if (x>y)return x ;
  else return y;}



void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int w,h,x,y;
  int  con1,con2,con3,con4;
  x=y=0;
  w= max(size1,x_offset + size2);
  h=max(size1,y_offset + size2);
  con1=(((x >= x_offset )&&(x < x_offset + size2 ))&&((y == y_offset)||(y == y_offset+size2 -1)));
	con2=(((y >= y_offset )&&(y < y_offset + size2 ))&&((x == x_offset)||(x == x_offset+size2 -1)));
	con3=((x<size1)&&((y==0)||(y==(size1-1))));
	con4=((y<size1)&&((x==0)||(x==(size1-1))));
  //compute the max of size1 and (y_offset + size2).  Call this h

  //count from 0 to h. Call the number you count with y
  for (y=0;y< h;y++){
    //    printf("%d %d %d %d ",con1,con2,con3,con4);
    for (x=0;x<w;x++){
       con1=(((x >= x_offset )&&(x < x_offset + size2 ))&&((y == y_offset)||(y == y_offset+size2 -1)));
	con2=(((y >= y_offset )&&(y < y_offset + size2 ))&&((x == x_offset)||(x == x_offset+size2 -1)));
	con3=((x<size1)&&((y==0)||(y==(size1-1))));
	con4=((y<size1)&&((x==0)||(x==(size1-1))));
 
      if (con1 || con2) printf("*");
      else{ if (con3 || con4) printf("#");
	else printf(" ");} }
    printf("\n");
  }

    //count from 0 to w. Call the number you count with x

      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
  
 
 
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *
 
 
      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #

      //else print a space
    //when you finish counting x from 0 to w, 
    //print a newline

}
