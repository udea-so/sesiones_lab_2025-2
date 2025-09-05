#include <stdio.h>

#define MAX 10

int main() {
  FILE *fp;
  char buff[MAX];

  fp = fopen("foo.txt", "r");
 
  while (fgets(buff, MAX, fp)) {
    printf("%s", buff);
  }
  fclose(fp);

  fp = fopen("bar.bin", "wb");
  int num = 0x12345678;
  fwrite(&num, sizeof(int), 1, fp);
  fclose(fp);

  fp = fopen("bar.bin", "rb");
  int readNum;
  fread(&readNum, sizeof(int), 1, fp);
  printf("readNum = 0x%x\n", readNum);
  fclose(fp);
  return 0;
}
