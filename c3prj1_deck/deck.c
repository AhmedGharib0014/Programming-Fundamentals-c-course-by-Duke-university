#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

int com (card_t c1,card_t c2){
  if ((c1.value == c2.value) &&(c1.suit == c2.suit)) return 1;
  return 0;

}

void print_hand(deck_t * hand){
  card_t ** card =hand -> cards ;
  for (size_t i=0 ;i<hand -> n_cards ;i++){
    print_card(**(card+i));
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t ** card =d -> cards ;
  for (size_t i=0 ;i< d -> n_cards ;i++){
    if (com(**(card+i),c)) return 1;
  }

  return 0;
}

void shuffle(deck_t * d){
  card_t ** card =d -> cards ;
  card_t * temp;
  size_t n=d ->n_cards;
  int randarry;
  for (size_t i=0 ;i< n ;i++){
    randarry=rand()%(n-i) + i;
    temp=*(card+i);
    *(card+i)=*(card+randarry);
    *(card+randarry)=temp;
  }  
}

void assert_full_deck(deck_t * d) {
  card_t ** card =d -> cards ;
  card_t c;
  int count;
  
  for (size_t i=0 ;i< d -> n_cards ;i++){
    c=**(card+i);
    count=0;
    for (size_t j=0 ;j< d -> n_cards ;j++){
      if(com(**(card+j), c)) count ++;
    }
    assert(count ==1);
  }
}
