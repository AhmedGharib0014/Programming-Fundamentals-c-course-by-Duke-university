
#include<stdio.h>
#include<stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double cal(double acc , retire_info st ){
  return acc*st.rate_of_return + st.contribution + acc;
}
void retirement (int startAge ,double initial , retire_info working,retire_info retired){
  double temp;
  temp= initial;
  for (int i=0;i<working.months ; i++,startAge++){
    printf("Age %3d month %2d you have $%.2lf\n",startAge/12 , startAge%12, temp);
    temp=cal(temp,working);
  }
  for (int i=0;i<retired.months;i++,startAge++){
    printf("Age %3d month %2d you have $%.2lf\n",startAge/12 , startAge%12, temp);
    temp=cal(temp,retired);
  }  
  //calculate retirement account balabce while working
  //print the formula
  //similar task to retirement
  //print out the same information
}


int main(void){
  retire_info working;
  working.months=489;
  working.rate_of_return=.045/12;
  working.contribution=1000;
  retire_info retired;
  retired.months=384;
  retired.rate_of_return = .01/12;
  retired.contribution=-4000;
  int startAge=327;
  double  initial =21345;
  retirement(startAge,initial,working,retired);
  return 0;
}
