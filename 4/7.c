#include <stdio.h>
const char * napis = "Witajcie moi mili ...";
int main(){
  unsigned int index =0;
  for (index; ; (index > 21) ? index = 0 : ++index){
    printf("%c",napis[index]);
  }
  return 0;
}