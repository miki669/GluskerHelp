#pragma once
#include <time.h>

namespace practica
{
   // П14-1-15 Напишите процедуру, которая по двум датам (номерам дней в месяце, месяцам и году) находит количество дней между ними.
   struct Date {
      int d, m, y;
   };
   const int monthDays[12] =
      { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31
      };
   int countLeapYears(Date d)
   {
      int years = d.y;
      if (d.m <= 2)
         years--;
      return years / 4
             - years / 100
             + years / 400;
   }
   int GetDifference(Date dt1, Date dt2)//процедура
   {   
      long int maxdate1 = dt1.y * 365 + dt1.d;      
      for (int i = 0; i < dt1.m - 1; i++)
         maxdate1 += monthDays[i];
      
      maxdate1 += countLeapYears(dt1);
      long int maxdate2 = dt2.y * 365 + dt2.d;
      for (int i = 0; i < dt2.m - 1; i++)
         maxdate2 += monthDays[i];
      
      maxdate2 += countLeapYears(dt2);
      return (maxdate2 - maxdate1);
   }
   void P14115()
   {
      int
      day_1,
      day_2,
      month_1,
      month_2,
      year_1,
      year_2;
      printf("Enter Date 1(lower) (DD MM YYYY): ");
      scanf_s("%d %d %d",&day_1,&month_1,&year_1);
      if(day_1   > 31 && day_1 < 0  ||
         month_1 > 12 && month_1 < 1||
         year_1  < 0)
            return;
      printf("Enter Date 2(big) (DD MM YYYY): ");
      scanf_s("%d %d %d",&day_2,&month_2,&year_2);
      if(day_1   > 31 && day_1 < 0  ||
         month_1 > 12 && month_1 < 1||
         year_1  < 0)
            return;
      Date dt1 = { day_1, month_1, year_1 };
      Date dt2 = { day_2, month_2, year_2 };      
      cout << GetDifference(dt1,dt2) << endl;
   }
}
