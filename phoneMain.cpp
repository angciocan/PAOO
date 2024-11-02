#include <iostream>
#include <cstring>

using namespace std;
#define BUFFER_SIZE 30

class Phone
{
    private:
        char* name;
        int *year;
        int price;
        int weight;

    public:
        Phone(const char* name, int year, int price, int weight)  //Constructor 
        {
          this -> name = new char[BUFFER_SIZE];
          this -> year = new int;
          strcpy(this -> name, name);
          *(this -> year) = year;
          this -> price = price;
          this -> weight = weight; 
          cout << "The phone object is created!" << endl;
        }
        
        ~Phone() //destructor
        {
           cout << "The phone object was deleted!" << endl;
        }

        Phone(const Phone &phone) //Copy constructor
        {
           this -> name = new char[BUFFER_SIZE];
           strcpy(this -> name, phone.name);
           this -> year = phone.year;
           this -> price = phone.price;
           this -> weight = phone.weight;
           cout << "Copy constructor" << endl;
        }

        Phone(Phone&& phoneMove) noexcept //Move constructor
        {
            this -> name = phoneMove.name;
            this -> year = phoneMove.year;
            this -> price = phoneMove.price;
            this -> weight = phoneMove.weight;

            phoneMove.name = nullptr;
            phoneMove.year = nullptr;
            phoneMove.price = 0;
            phoneMove.weight = 0;

            cout << "Move constructor was executed!" << endl;
        }
        
        char* getName()
        {
            return this -> name;
        }

        int* getYear()
        {
            return this -> year;
        }

        int getPrice()
        {
            return this -> price;
        }

        int getWeight()
        {
            return this -> weight;
        }

        void setName(char* name)
        {
            strcpy(this -> name, name);
        }

        void setYear(int year)
        {
            *(this -> year) = year;
        }

        void setPrice(int price)
        {
           this -> price = price;
        }

        void setWeight(int weight)
        {
           this -> weight = weight;
        }

        void toString()
        {
             cout << "The name: " << this -> name << endl << "Year of manufacture: " << 
             *(this -> year) << endl << "Price: "<< this -> price << endl << "Weight: " 
             << this -> weight << endl;
        }

};

int main(void)
{
    Phone phone1("Samsung", 2021, 30, 20); //Constructor - se initializeaza membrii clasei pentru a seta obiectul
    phone1.toString();

    char *name = new char[BUFFER_SIZE];
    strcpy(name, "iPhone");
    phone1.setName(name); //Primul obiect phone isi seteaza numele 
    
    cout << "The first phone has changed the name" << endl;
 
    phone1.toString();

    Phone phone2 = phone1; //Al doilea obiect copiaza datele primului obiect prin copy constructor(doar cu prezenta unui copy constructor in clasa)

    cout << "The second phone has copied the first phone's contains" << endl;

    phone2.toString();

    Phone phone3 = Phone(move(phone1)); //Prin move constructor datele primului obiect sunt mutate in al treilea obiect

    cout << "The third phone has the first phone's contains" << endl;

    phone3.toString();
    
    //phone1.toString();
    // Se apeleaza automat destructorul pentru fiecare obiect phone(in caz contrar se pierde memorie)

    delete[] name;
    return 0;
}