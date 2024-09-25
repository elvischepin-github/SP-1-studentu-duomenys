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
        
        std::string arAtsitiktinis;
        std::cout << "Generuoti atsitiktinius pažymius? Įrašykite 'TAIP' arba 'NE': ";
        std::cin >> arAtsitiktinis;
        
        if(arAtsitiktinis == "NE"){
            int pazymys;
                for (int i = 0; i < namuDarbai; ++i) {
                           std::cout << vardas << " " << pavarde <<  ": Įveskite " << (i + 1) << "-ojo namų darbo pažymį: ";
                           std::cin >> pazymys;
                           pazymiai.push_back(pazymys);
                       }

                        std::cout << "Įveskite egzamino pažymį: ";
                        std::cin >> egzaminas;
        } else if(arAtsitiktinis == "TAIP"){
            std::random_device random;
            std::default_random_engine engine(random());
            int min = 1, max = 10;
            std::uniform_int_distribution<int> distribution(min, max);
            
            for(int i = 0; i < namuDarbai; i++){
                pazymiai.push_back(distribution(engine));
            }
            egzaminas = distribution(engine);
        }

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
    
    ~Studentas(){}

    double galutinisVidurkis() const {
        int suma = 0;
        for (int pazymys : pazymiai) {
            suma += pazymys;
        }
        double vidurkis = static_cast<double>(suma) / pazymiai.size();
        return 0.4 * vidurkis + 0.6 * egzaminas;
    }

    double galutinisMediana() const {
        std::vector<int> rusiuojamiPazymiai = pazymiai;
        std::sort(rusiuojamiPazymiai.begin(), rusiuojamiPazymiai.end());
        
        if (rusiuojamiPazymiai.size() % 2 == 0) {
            return (rusiuojamiPazymiai[rusiuojamiPazymiai.size() / 2 - 1] + rusiuojamiPazymiai[rusiuojamiPazymiai.size() / 2]) / 2.0;
        } else {
            return rusiuojamiPazymiai[rusiuojamiPazymiai.size() / 2];
        }
    }

    void gautiRez() const {
        int pasirinkimas;

        std::cout << "Pasirinkite skaičiavimo būdą:" << std::endl;
        std::cout << "1 - Vidurkis" << std::endl;
        std::cout << "2 - Mediana" << std::endl;
        std::cout << "Įveskite atitinkamą skaičių: ";
        std::cin >> pasirinkimas;
        
        std::cout << std::left
                        << std::setw(18) << "Pavardė"
                        << std::setw(18) << "Vardas";
                    if(pasirinkimas == 1){
                        std::cout  << std::setw(16) << "Galutinis (Vid.)";
                    } else if (pasirinkimas == 2){
                        std::cout  << std::setw(16) << "Galutinis (Med.)";
                    }
                        std::cout << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << std::left
                        << std::setw(18) << pavarde
                        << std::setw(18) << vardas;
                    if(pasirinkimas == 2){
                        std::cout << std::setw(16) << std::fixed << std::setprecision(2) << galutinisVidurkis();

                    } else if (pasirinkimas == 1){
                        std::cout << std::setw(16) << std::fixed << std::setprecision(2) << galutinisMediana();
                    }
                        std::cout << std::endl << std::endl;
    }
};

int main() {
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
    
    return 0;
}
