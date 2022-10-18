#include <stdio.h>

int main(){
    int weekday = 1; // day numbers : mon =0, tue = 1 ... sun = 6
    int year = 1901; // the first day of 1901 is a tuesday
    int month = 1;  // Jan = 1, Feb = 2 ..... Dec = 12
    int suncount=0; // Number of Sundays
    printf("There was a sunday on these dates: \n");
     
    while(year <2001){      //stops at Dec 31, 2000
        while (month <=12){     //loops through all 12 months in every year, from 1901 to 2000
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ){ //months with 31 days
                if(weekday==6){     //if sunday on 1st day of the month
                    suncount++;
                    printf("1/%d/%d\n", month, year); //prints the date if 1st day is sunday
                }
            weekday = (weekday+31) % 7;
            // formula for calculation of weekday of the next month
            // (1st day of month number of current month + numberOfDaysinCurrentMonth) % 7 =  1st day number of next month
            // the first day of Jan 1901 is tuesday, which is equal to 1.
            // so (1+31)%7 = 4
            // which means that the first day of feb 1901 will be a friday

            }
            else if ( month == 4 || month == 6 || month == 11 || month == 9){     //months with 30 days
                if(weekday==6){
                    suncount++; 
                    printf("1/%d/%d\n", month, year); 
                }
            weekday = (weekday+30) % 7; //same formula as above
            }
            else if ( month==2 && year%4 !=0){      //feb check without a leap year
                if(weekday==6){
                    suncount++; 
                    printf("1/%d/%d\n", month, year); 
                }
            weekday = (weekday+28) % 7; 
            }
            else if ( month==2 && year%4 == 0){ //feb check with a leap year
                if(weekday==6){
                    suncount++; 
                    printf("1/%d/%d\n", month, year); 
                }
            weekday = (weekday+29) % 7; 
            }
        month++;
        // month incremented after check for sunday on first day
        }
        if (month == 13)    //when month becomes 13, it resets back to 1.
        {
            month = 1;
        }
        
        year++; //since it is a nested loop, so the year is increased by 1 AFTER all months are calculated
        
    }
    printf("The total number of sundays on 1st of each month in the 20th century are: %d", suncount);     //prints the number of sundays
    return 0;
}
