#include "libraries.h"

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int namuDarbai;
    int egzaminas;

public:
    Studentas(std::string vardas, std::string pavarde, int namuDarbai) {
        this->vardas = vardas;
        this->pavarde = pavarde;
        
        int pazymys;
        for (int i = 0; i < namuDarbai; ++i) {
                   std::cout << vardas << " " << pavarde <<  ": Įveskite " << (i + 1) << "-ojo namų darbo pažymį: ";
                   std::cin >> pazymys;
                   pazymiai.push_back(pazymys);
               }

               std::cout << "Įveskite egzamino pažymį: ";
               std::cin >> egzaminas;
    }
    Studentas(const Studentas& Kopija)
        : vardas(Kopija.vardas), pavarde(Kopija.pavarde), pazymiai(Kopija.pazymiai),
          namuDarbai(Kopija.namuDarbai), egzaminas(Kopija.egzaminas) {
    }

    Studentas& operator=(const Studentas& Kopija) {
        if (this != &Kopija) {
            vardas = Kopija.vardas;
            pavarde = Kopija.pavarde;
            pazymiai = Kopija.pazymiai;
            namuDarbai = Kopija.namuDarbai;
            egzaminas = Kopija.egzaminas;
        }
        return *this;
    }
    
    ~Studentas(){};

    double galutinisVidurkis() const {
        int suma = 0;
        for (int pazymys : pazymiai) {
            suma += pazymys;
        }
        double vidurkis = static_cast<double>(suma) / pazymiai.size();
        return 0.4 * vidurkis + 0.6 * egzaminas;
    }

    void gautiRez() const {
        std::cout << std::left << std::setw(15) << "Pavardė"
                  << std::setw(20) << "Vardas"
                  << std::setw(25) << "Galutinis (Vid.)"
                  << std::endl;
        
        std::cout << "----------------------------------------------" << std::endl;
        
        std::cout << std::left << std::setw(15) << pavarde
                  << std::setw(20) << vardas
                  << std::setw(25) << std::fixed << std::setprecision(2) << galutinisVidurkis()
                  << std::endl << std::endl;
    }
};

int main() {
//    ------------savarankiškas įvedimas--------------
    std::string vardas, pavarde;
    int namuDarbai;

    std::cout << "Vardas: ";
    std::cin >> vardas;
    std::cout << "Pavardė: ";
    std::cin >> pavarde;
    
    std::cout << "Namų darbų skaičius: ";
    std::cin >> namuDarbai;
    
    Studentas student1(vardas, pavarde, namuDarbai);
    student1.gautiRez();
////    ------------kopijavimas-------------------------
//    Studentas student2("Tomas", "Tomaitis", 3);
//    student2.gautiRez();
////    ------------priskyrimas-------------------------
//    Studentas student3("Romas", "Romanovas", 4);
//    Studentas student4 = student3;
//    student3.gautiRez();
    
    return 0;
}
