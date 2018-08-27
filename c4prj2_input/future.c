#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"
#include "future.h"
void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  if(index < fc->n_decks){
    fc->decks[index].cards=realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(*(fc->decks[index].cards)));
    fc->decks[index].cards[fc->decks[index].n_cards]=ptr;
    fc->decks[index].n_cards ++;
  }
  else{
    while(fc->n_decks <= index){
      fc->decks=realloc(fc->decks,(fc->n_decks+1)*sizeof(*fc->decks));
      fc->decks[fc->n_decks].cards=NULL;
      fc->decks[fc->n_decks].n_cards=0;
      fc->n_decks ++;
    }
    fc->decks[index].cards=realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(*(fc->decks[index].cards)));
    fc->decks[index].cards[fc->decks[index].n_cards]=ptr;
    fc->decks[index].n_cards ++;
  }
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  //error cheching
  int unknown=0;
  for(int i=0;i< fc->n_decks ; i++){
    if(fc->decks[i].cards != NULL) unknown ++;
  }
  if (deck->n_cards< unknown){
    fprintf(stderr,"future_cards_from_deck");
    return;
  }
  //initalization
  card_t card;
  card.value=0;
  card.suit=0;
  int j=0;
  for(int i=0 ;i<unknown;i++){
    card.value=(*(deck->cards[i])).value;
    card.suit=(*(deck->cards[i])).suit;
    while(fc->decks[j].n_cards == 0) j++;
    for(int x=0 ;x<fc->decks[j].n_cards ;x++){
      (*(fc->decks[j].cards[x])).value=card.value;
      (*(fc->decks[j].cards[x])).suit=card.suit;
    }
    j++;
  }
}

