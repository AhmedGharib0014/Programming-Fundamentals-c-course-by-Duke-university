#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  int cond1,cond2;
  cond1=(c.value >=2 )&&(c.value <= VALUE_ACE);
  cond2=(c.suit ==  SPADES )||(c.suit == CLUBS )||(c.suit ==  HEARTS)||(c.suit == DIAMONDS);
  assert(cond1 && cond2);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r){
  case  STRAIGHT_FLUSH:  return "STRAIGHT_FLUSH";
  case  FOUR_OF_A_KIND: return"FOUR_OF_A_KIND";
  case FULL_HOUSE: return"FULL_HOUSE";
  case  FLUSH: return"FLUSH";
  case  STRAIGHT: return"STRAIGHT";
  case  THREE_OF_A_KIND: return"THREE_OF_A_KIND";
  case  TWO_PAIR: return"TWO_PAIR";
  case  PAIR: return"PAIR";
  default  : return"NOTHING";
  }
}

char value_letter(card_t c) {
  char x='?';
  if ((c.value >= 2 )&&( c.value <=9)) x = '0' + c.value ;
  else {
    switch(c.value){
    case VALUE_KING : {x='K';  break;}
    case 10 : {   x='0';  break;}
    case VALUE_ACE :{ x= 'A' ;  break;}
    case VALUE_QUEEN :{x='Q' ; break;}
    case VALUE_JACK :{x='J' ; break;}
    default :break;
    }
  }
  return x ;
}


char suit_letter(card_t c) {
  char x='?';
  switch(c.suit){
  case  SPADES : {x='s';  break;}
  case HEARTS : {   x='h';  break;}
  case DIAMONDS :{ x= 'd' ;  break;}
  case CLUBS :{x='c' ; break;}
  default :{ x='N'; break;}
  }
  return x;
  
}

void print_card(card_t c) {
  char suit1= suit_letter( c);
  char value1= value_letter( c);
  printf("%c%c ",value1,suit1);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case 'K' : {temp.value= 13;  break;}
  case '0' : { temp.value= 10;  break;}
  case 'A' :{ temp.value= 14;  break;}
  case 'Q' :{temp.value= 12; break;}
  case 'J' :{temp.value= 11; break;}
  default :{temp.value=value_let - '0';
      break;} }

  switch(suit_let){
  case  's'  : {temp.suit =SPADES;  break;}
  case 'h' : {  temp.suit =HEARTS;  break;}
  case 'd' :{temp.suit = DIAMONDS ;  break;}
  case  'c':{temp.suit =CLUBS ; break;}
  default: {temp.suit = NUM_SUITS;  break; }}
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  unsigned value = c%13 + 2;
  temp.value = value;
  
  unsigned suit = c/13;
  switch(suit){
  case  0 : {temp.suit =SPADES;  break;}
  case 1 : {  temp.suit =HEARTS;  break;}
  case 2 :{temp.suit = DIAMONDS ;  break;}
  case 3:{temp.suit =CLUBS ; break;}
  default: {temp.suit = NUM_SUITS;  break; }}
  
  return temp;
  
}

/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {


}

const char * ranking_to_string(hand_ranking_t r) {
  return "";
}

char value_letter(card_t c) {
  return 'x';
}


char suit_letter(card_t c) {
  return 'x';
  
}

void print_card(card_t c) {

}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  return temp;
}
*/
