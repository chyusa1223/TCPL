#include <stdio.h>
#define LEN (sizeof(temperature_readings)/sizeof(temperature_readings[0][0]))
#define MON 30
#define HOUR 24 

int main(int argc, char *argv[])
{
  int temperature_readings[30][24] = {12,13,14,15,16,17,18,10,9,19,0};
  int i,j,sum;
  double result = 0.0;

  for(i=0;i<MON;i++) {
    for(j=0;j<HOUR;j++) {
      sum += temperature_readings[i][j];
    }
  }
  printf("Average temperature of month is %lf", (double)sum/LEN);
  return 0;
}
