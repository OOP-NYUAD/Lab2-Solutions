/*Write a class called Time that can be used to represent time in hour, minute and 
second values. The class Time contains the following members:
    - Three private data members: hour (0-23), minute (0-59) and second (0-59), 
      with default values of 0.
    - A public constructor Time(), which initializes the data members hour, minute 
      and second with the values provided by the caller (as arguments).
    - public getters and setters for private data members: getHour(),getMinute(),
      getSecond(),setHour(),setMinute(),and setSecond().
    - A public member function setTime() to set the values of hour, minute and 
      second given by the caller.
    - A public member function print() to print this Time instance in the format 
      "hh:mm:ss", zero-filled, e.g., 01:30:04.
    - A public member function nextSecond(), which increase this instance by one 
      second. nextSecond() of 23:59:59 shall be 00:00:00.
      
Write a simple tester program to test the Time class.
*/