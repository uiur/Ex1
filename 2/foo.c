// mylecture.dataをつくる〜
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp1, *fp2;
  char str[100];
  char *period[5] = {"Mo1", "Mo4", "Tu5", "We2", "Fr2"};
  int i = 0;

  if((fp1 = fopen("mylecture.txt", "r")) == NULL) {
    printf("おうおう、開かれへんかったわ\n");
    exit(1);
  }

  if((fp2 = fopen("mylecture.data", "w")) == NULL) {
    printf("おうおう、開かれへんかったわ\n");
    exit(1);
  }

  do {
    fgets(str, 100, fp1);
    if(!feof(fp1))
      fprintf(fp2, "%s\t%s", period[i++], str);
  } while(!feof(fp1));
  
  return 0;
}
