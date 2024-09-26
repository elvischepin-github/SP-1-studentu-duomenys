#include "libraries.h"
#include "studentas.h"
#include "utils.h"

int main() {
    std::string vardas, pavarde;

    std::cout << "Vardas: ";
    std::cin >> vardas;
    std::cout << "Pavardė: ";
    std::cin >> pavarde;
    
    Studentas student1(vardas, pavarde);
    student1.gautiRez();
    
    std::cout << std::endl;
    if(student1.spausdinimas == true){
        matytiSarasa();
    }
    
    return 0;
}
