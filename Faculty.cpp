#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

#define BUFFER_SIZE 128

class Faculty 
{

    private:
        int facultyId = 0;
        string facultyName = "";
        int nrStudents = 0;
        int nrTeachers = 0;
    
    public:
        Faculty(){}

        Faculty(const int facultyId, string facultyName, const int nrStudents, const int nrTeachers) : 
        facultyId(facultyId), facultyName(facultyName), nrStudents(nrStudents), nrTeachers(nrTeachers)
        {
            cout << "The faculty constructor was called!" << endl;
        }

        ~Faculty()
        {
           cout << "The faculty destructor was called!" << endl; 
        }

        Faculty(const Faculty& faculty) // copy constructor
        {
            this -> facultyId = faculty.facultyId;
            this -> facultyName = faculty.facultyName;
            this -> nrStudents = faculty.nrStudents;
            this -> nrTeachers = faculty.nrTeachers;
            cout << "The copy constructor was called!" << endl;
        }
          
        Faculty& operator = (const Faculty& faculty)
        {
            if(this != &faculty)
            {
                this -> facultyId = faculty.facultyId;
                this -> facultyName = faculty.facultyName;
                this -> nrStudents = faculty.nrStudents;
                this -> nrTeachers = faculty.nrTeachers;
                cout << "The operator= was called!" << endl;
            }

            return *this;
        }

        void setFacultyId(const int facultyId)
        {
            if(this -> facultyId != facultyId)
            {
              this -> facultyId = facultyId;
            }
        }

        void setFacultyName(const string facultyName)
        {
            if(this -> facultyName != facultyName)
            {
                this -> facultyName = facultyName;
            }
        }

        void setNrStudents(const int nrStudents)
        {
            if(this -> nrStudents != nrStudents)
            {
               this -> nrStudents = nrStudents;
            }
        }

        void setNrTeachers(const int nrTeachers)
        {
            if(this -> nrTeachers != nrTeachers)
            {
                this -> nrTeachers = nrTeachers;
            }
        }

        void toString()
        {
            if(this -> facultyName != "" && this -> nrStudents != 0 && this -> nrTeachers != 0)
            {
                 cout << "The faculty of " << this -> facultyName << " has id " << this -> facultyId 
                 << " " <<  this -> nrStudents << " students and " << this -> nrTeachers << " teachers!" << endl;
            }

            else
            {
                cout << "The faculty hasn't id, name, students and teachers!" << endl;
            }
        }

};

int main(void)
{

    shared_ptr<Faculty> fac1(new Faculty(0, "AC", 2000, 900));  // Item 13
    fac1 -> toString();

    shared_ptr<Faculty> fac2(new Faculty(1, "ETc", 2000, 800));
    fac2 -> toString();
    
    fac2 = fac1; 
    fac2 -> toString();
    
    Faculty faculty1(2, "Mecanica", 3000, 1200);
    shared_ptr<Faculty> fac3(new Faculty(faculty1));

    fac2 = fac3; //Item 14

    fac2 -> toString(); // obiectul fac2 a copiat obiectul fac3, deci a copiat resursele obiectului fac3 
    
    return 0;
}