#include<stdio.h>
#include<stdlib.h>
size_t maxSeq(int * array, size_t n){
  size_t  lenth= 1;
  size_t maxlen=0;
  if (n == 0 ) return 0;
  
  for(size_t i=1 ; i<n ;i++ ){
    if (array[i] > array[i-1]){lenth += 1;}
    else {
      if (lenth > maxlen) maxlen = lenth;
      lenth=1;
	  } 
  }
  if (lenth > maxlen) maxlen = lenth;
  return maxlen; 
}
