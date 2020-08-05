
#include <stdio.h>

int main(void) {

  struct time {
    char departure_time[20];
    char Arrival_time[20];
    int d;
  };
  int user_time, hour, minute;

  struct time d[8] = { {"8:00 a.m.","10:16 a.m.",480},
		       {"9:43 a.m.","11:52 a.m.",583},
		       {"11:19 a.m.","1:31 p.m.",679},
		       {"12:47 a.m.","3:00 p.m.",767},
		       {"2:00 p.m.","4:08 p.m.",840},
		       {"3:45 p.m.","5:55 a.m.",945},
		       {"7:00 p.m.","9:20 a.m.",1140},
		       {"9:45 p.m.","11:58 a.m.",1305}};


  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &hour, &minute);
  user_time = hour * 60 + minute;

  /*
    printf("User Time : %d\n",user_time);
    printf("limit : %d\n",d[0].d+(d[1].d - d[0].d)/2);
  */
  printf("Closest departure time is ");

  if (user_time <= d[0].d + (d[1].d - d[0].d) / 2)
      printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (user_time < d[1].d + (d[2].d - d[1].d) / 2)
      printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (user_time < d[2].d + (d[3].d - d[2].d) / 2)
      printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (user_time < d[3].d + (d[4].d - d[3].d) / 2)
      printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (user_time < d[4].d + (d[5].d - d[4].d) / 2)
      printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (user_time < d[5].d + (d[6].d - d[5].d) / 2)
      printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (user_time < d[6].d + (d[7].d - d[6].d) / 2)
      printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else
      printf("9:45 p.m., arriving at 11:58 p.m.\n");

  return 0;
}
