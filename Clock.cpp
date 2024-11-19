#include <iostream>

using namespace std;

class Clock
{
    private:
        long yearOfManufacture = 0; //Item 4
        int hour = 0;
        int minute = 0;
        int second = 0;

    public:
        
        //Item 4
        Clock(const long yearOfManufacture, const int hour, const int minute, const int second) :
         yearOfManufacture(yearOfManufacture), hour(hour), minute(minute), second(second) {}

        virtual ~Clock()
        {
          cout << "The clock object was deleted!" << endl;
        }

        long getYearOfManufacture()
        {
          return this -> yearOfManufacture;
        } 

        int getHour()
        {
          return this -> hour;
        } 

        int getMinute()
        {
          return this -> minute;
        } 

        int getSecond()
        {
          return this -> second;
        }   

        void setYearOfManufacture(const int yearOfManufacture)
        {
           this -> yearOfManufacture = yearOfManufacture;
        } 

        void setHour(const int hour)
        {
           this -> hour = hour;
        } 

        void setMinute(const int minute)
        {
            this -> minute = minute;
        }

        void setSecond(const int second)
        {
            this -> second = second;
        }

        void setTime(const int hour, const int minute, const int second) 
        {
           this -> hour = hour;
           this -> minute = minute;
           this -> second = second;
        }

        void toString()
        {
            cout << "Ceasul fabricat in anul " << this -> yearOfManufacture << " arata ora: " << 
            this -> hour << " cu minutul: " << this -> minute << " si cu secunda: " << this -> second << endl;
        }
};

class ClockShop : Clock
{
  
  private:
    int yearOfManufacture = 0; //Item 4
    int hour = 0;
    int minute = 0;
    int second = 0;
    int nrOfClocks = 0;

    ClockShop(const ClockShop& clockShop); //Item 6

  public:
     
     ClockShop(const int yearOfManufacture, const int hour, const int minute, const int second) : //Item 4
     Clock(yearOfManufacture, hour, minute, second)
     {
        nrOfClocks++;
     }

    ~ClockShop() 
     {
        cout << "The clockShop was deleted!" << endl;
     }

     int getNrOfClocks()
     {
        return this -> nrOfClocks;
     }
};

int main(void)
{
    Clock clk1(2020, 0, 0, 0);
    Clock clk2(clk1); 

    clk2.toString(); //Nu afisaza eroare

    ClockShop clkShop1(2002, 1, 2, 3);
    //Clock clk1; Deja este creat un constructor in clasa - afisaza eroare
    cout << "Number of clocks: " << clkShop1.getNrOfClocks() << endl; 
    //ClockShop clkShop2(clkShop1); - eroare item 6
    return 0;
}