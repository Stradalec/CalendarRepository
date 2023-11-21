/**********************************
* Автор: Калинин Андрей           *
* Лабораторная №9                 *
* Дата: 19.11.2023                *
* Название: Календарь             *
* https://onlinegdb.com/pZXP0aez02*
**********************************/

#include <iostream>
#include <string>

using namespace std;


int main() {
  int userYear;
  int defaultYear = 2024;
  string namesOfMonthArray[12] = {"January", "February", "March", "April", "May",
  "June", "Jule", "August", "September", "October", "November", "December"};
  int monthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string weekArray[7] = {"Su", "Sa", "Fr", "Th", "We", "Tu", "Mo"};
  int reminder = 0;
  int copyReminder;
  int dayCounter = 0;
  int secondDayCounter = 1;
  bool check = false;
  int difference = 0;
  int emptyPlaces = 0;


  cout << "Enter the year: " ;
  cin >> userYear;
  difference = defaultYear - userYear;
  difference = difference % 7;
  reminder = 7 - ( difference % 7 );
  if (reminder == 7) {
      reminder = 0;  
    } else if (reminder > 7) {
      reminder = (reminder % 7) + 1;  
    }
  copyReminder = reminder;
    if (userYear == defaultYear || difference != 0) {
    if ( (userYear % 4 == 0 && userYear % 100 != 0) || (userYear % 400 == 0) ) {
      monthArray[1] = 29;    
    }
    for (int monthIndex = 0; monthIndex < 12; ++monthIndex ) {
      cout << namesOfMonthArray[monthIndex] << endl;
        cout << weekArray[6] << "  " << weekArray[5] << "  " << weekArray[4]
             << "  " << weekArray[3] << "  " << weekArray[2] << "  "
             << weekArray[1] << "  " << weekArray[0] << endl;
      for (int dayIndex = 1; dayIndex <= monthArray[monthIndex]; ++dayIndex) {
        while (reminder > 0) {
          cout << "    ";
          --reminder;
        }
        if (dayIndex < 10) {
          cout <<  dayIndex << "   ";
        } else {
          cout <<  dayIndex << "  ";
          if (dayIndex > (28 - copyReminder) ) {
            ++dayCounter;
            ++secondDayCounter;
          }
        }
        
        if (copyReminder != 0) {
          if (dayIndex == (7 - copyReminder)  ||
              dayIndex == (14 - copyReminder) ||
              dayIndex == (21 - copyReminder) ||
              dayIndex == (28 - copyReminder) ) {
            cout << endl;
          }
        } else {
          if (dayIndex % 7 == 0) {
            cout << endl;

          }   
        }
        
        if (dayIndex == monthArray[monthIndex]) {
          cout << endl;  
        }
        if (secondDayCounter == 8) {
          cout << endl;
          secondDayCounter -= 7;
          emptyPlaces = (secondDayCounter - 1);
          check = true;  
        }

      }
      
      if (dayCounter > 7) {
        reminder += monthArray[monthIndex] % 7;
        if (check) {
          reminder = (secondDayCounter - 1);
          }
      } else if (dayCounter == 7) {
        dayCounter -=  dayCounter;
        reminder = dayCounter;
      } else {
        reminder = dayCounter;
      }    
      copyReminder = reminder;
      dayCounter -=  dayCounter;
      secondDayCounter = 1;
      check = false;
    }  
  }

  return 0;
}


