#include <iostream>
#include <cstring>

using namespace std;
#define BUFFER_SIZE 1024

enum FruitType
{
   orange = 0,
   banana = 1,
   apple = 2,
   pear = 3,
   strawberry = 4,
   kiwi = 5,
   peach = 6,
   plum = 7,
};

class Fruit
{
    private:
       FruitType type;
       char *originCountry = nullptr;
       double price = 0.0;
       double weight = 0.0;
    
    public:
       Fruit(){} //Constructor implicit
      
       Fruit(const FruitType type, char *originCountry, const double price, const double weight) : 
        type(type), originCountry(originCountry), price(price), weight(weight) 
        {
            this -> originCountry = new char[BUFFER_SIZE];
            strcpy(this -> originCountry, originCountry);
            cout << "The fruit constructor called!" << endl;
        } 

        ~Fruit()
        {
            delete[] originCountry;
            cout << "The fruit destructor called!" << endl;
        }

        Fruit& operator=(const Fruit& fruit) 
        {
            if(this == &fruit) //Item 11
            {
                return *this;
            }

            else
            {
               this -> type = fruit.type;

               delete[] this -> originCountry;
               this -> originCountry = new char[BUFFER_SIZE];
               strcpy(this -> originCountry, fruit.originCountry);

               this -> price = fruit.price;
               
               this -> weight = fruit.weight;

               return *this; //Item 10
            }
        }

        Fruit& operator=(FruitType fruitType)
        {
            if(this -> type == fruitType)
            {
                return *this;
            }

            else
            {
                this -> type = fruitType;
                return *this;
            }
        }

        Fruit& operator=(double price)
        {
            if(this -> price == price)
            {
                return *this;
            }

            else
            {
               this -> price = price;
               return *this;
            }
        }        

        Fruit& operator=(char* originCountry)
        {
            this -> originCountry = new char[BUFFER_SIZE];
            if(this -> originCountry == originCountry)
            {
                return *this;
            }

            else
            {
                strcpy(this -> originCountry, originCountry);
                return *this;
            }
        }

        Fruit& operator+(double price)
        {
            this -> price += price;
            return *this;
        }

        Fruit& operator-(double price)
        {
            this -> price -= price;
            return *this;
        }

        FruitType getFruitType()
        {
            return this -> type;
        }

        char* getOriginCountry()
        {
            return this -> originCountry;
        }

        double getPrice()
        {
            return this -> price;
        }

        double getWeight()
        {
            return this -> weight;
        }

        void toString()
        {
            cout << "Fruit type: " << this -> type << " origin contry: " << this -> originCountry << " price: " << 
            this -> price << " weight: " << this -> weight << endl;
        }
};

class Juice : public Fruit
{
    private:
       int numberOfFruits = 0;

    public:
       Juice() 
       {
          cout << "The juice constructor called!" << endl;
       }

       ~Juice()
       {
         cout << "The juice destructor called!" << endl;
       }
       
       Juice(const Juice& juice) : Fruit(juice), numberOfFruits(juice.numberOfFruits) // Item 12
       {
          this -> numberOfFruits = juice.numberOfFruits;
          cout << "The juice copy constructor called!" << endl; 
       }

       void addFruit(const Fruit& fruit)
       {
         this -> numberOfFruits++;
       }

       int getNumberOfFruits()
       {
         return this -> numberOfFruits;
       }

       void toString()
       {
         cout << "The juice has made from " << this -> numberOfFruits << " fruits" << endl; 
       }
};

int main(void)
{
    Fruit f1; 
    char *country = new char[BUFFER_SIZE];
    strcpy(country, "Turkey");
    Fruit f2(banana, country, 0.3, 0.9);
    
    f1 = f2; //A avut loc operator=

    f1.toString();

    strcpy(country, "Greece");
    
    f2 = orange;
    f2 = country;
    f2 = f2 + 0.9; //Se mareste pretul fructului cu 0.9
    f2 = f2 - 0.6; //Se scade pretul fruictului cu 0.6
    f2.toString();

    Juice juice1;
    juice1.addFruit(f1);
    juice1.toString();

    Juice juice2(juice1); //S-a apelat copy constructor-ul
    juice2.toString();

    delete[] country;
    return 0;
} 