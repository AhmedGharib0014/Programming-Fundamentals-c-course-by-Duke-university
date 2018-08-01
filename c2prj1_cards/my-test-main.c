#include "cards.h"
#include <stdio.h>

int main(void) {
  card_t c ;
  c.value=4;
  c.suit =2;
  assert_card_valid( c);  // printf("%s",ranking_to_string(5));
  const char *x = ranking_to_string(3);
  printf("%s",x);
  c=card_from_letters('5','h');
  for (int i=0;i<52;i++){
    c=card_from_num(i);
    print_card(c);
    printf("\n");
  }
}
