#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"
#include "future.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t* deck=malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards=0;
  char arr[strlen(str)];
  int arr_len=0;
  for(int i=0;i<strlen(str);i++){
    if((str[i] == '\n')||(str[i] == ' ')||(str[i] == '\0'))continue;
    arr[arr_len]=str[i];
    arr_len ++;
  }
  
  if(arr_len%2 != 0) {
    fprintf(stderr, "wrong number of chars in hand\n" );
    return NULL;}
  arr[arr_len]='\0';
    
  int j=0;
  while (arr[j] != '\0') {
      if(arr[j] == '?'){
        add_future_card(fc,(size_t)(arr[j+1]-'0'),add_empty_card(deck)) ;
      }else{
        card_t x = card_from_letters(arr[j],arr[j+1]);
        assert_card_valid(x);
        add_card_to(deck,x);
      }
      j = j+2;
  }
  if (deck->n_cards < 5 ){
    fprintf(stderr,"asas");
    return NULL;
  }
  return deck;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  deck_t **arr=NULL;
  size_t n_hand=0;
  char *line=NULL;
  size_t sz=0;
  
  while(getline(&line,&sz,f)>=0){
    arr=realloc(arr,(n_hand+1)*sizeof(*arr));
    arr[n_hand]=hand_from_string(line,fc);
    n_hand ++;
  }
  *n_hands=n_hand;
  return arr;
}
