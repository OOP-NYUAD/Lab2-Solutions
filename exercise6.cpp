/*Create a class called Date to store day, month and year as numbers. Define operator 
overloading for ++, = and == operators for Date class. Test your class with several 
test cases of Date instances.*/
#include <iostream>
#include <iomanip>

using namespace std;

class Date{
    int day, month, year;

public:
    Date(int d = 1, int m = 1, int y = 1){
        day = d;
        month = m;
        year = y;
    }


    // Keep in mind this overloads the PRE-increment
    Date operator ++(){
        day++;
        if(day == 31){
            day = 1;
            month++;
        }
        if(month == 13){
            month = 1;
            year++;
        }

        return (*this);
    }

    // to overload the post increment, you specify a dummy (int) argument like so:
    Date operator ++(int){
        Date old(*this);    // copy current value of date
        ++(*this);          // do the increment
        return old;         // return the old value
    }

    bool operator ==(const Date &obj){
        return (this->day == obj.day && this->month == obj.month && this->year == obj.year);
    }

    void print(){
        cout << setfill('0') << setw(2) << day << '/' << setfill('0') << setw(2) << month << '/' << year << '\n';  
    }

};

int main(){
    Date d1(10, 2, 2023);
    d1++.print();   // this is a post increment so I should still get 10/02/2023

                    // now date is 11/02/2023
    (++d1).print(); // this should print 12/02/2023
    

    cout << '\n';
    /*Let's also be sure the date rolls over correctly*/
    Date d2(30, 12, 2023);  // Last day of the year
    (++d2).print();         // should give me 01/01/2024

    /*Finally, let's test the == operator*/

    d1 == d2 ? cout << "Same day\n" : cout << "Different day\n\n";

    /*Just to be sure let's have a day that is the same*/

    Date d3(1,1,2024);

    d2 == d3 ? cout << "Same day\n" : cout << "Different day\n";
    return 0;
}