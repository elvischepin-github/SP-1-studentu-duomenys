#include "Studentas.h"

Studentas::Studentas(std::string vardas, std::string pavarde) {
    this->vardas = vardas;
    this->pavarde = pavarde;
    
    std::string arAtsitiktinis;
    std::cout << "Generuoti atsitiktinius pažymius? Įrašykite inicialą, taip = 't' arba ne = 'n': ";
    std::cin >> arAtsitiktinis;
    
    if(arAtsitiktinis == "n"){
        int pazymys;
        for (int i = 0; i < namuDarbai; ++i) {
            std::cout << vardas << " " << pavarde <<  ": Įveskite " << (i + 1) << "-ojo namų darbo pažymį: ";
            std::cin >> pazymys;
            pazymiai.push_back(pazymys);
        }
        std::cout << "Įveskite egzamino pažymį: ";
        std::cin >> egzaminas;
    } else if(arAtsitiktinis == "t"){
        std::random_device random;
        std::default_random_engine engine(random());
        int min = 1, max = 10;
        std::uniform_int_distribution<int> distribution(min, max);
        
        for(int i = 0; i < namuDarbai; i++){
            pazymiai.push_back(distribution(engine));
        }
        egzaminas = distribution(engine);
    }
    
    std::string arMatytiSarasa;
    std::cout << "Norite pamatyti esamą sąrašą? Įrašykite inicialą, taip = 't' arba ne = 'n': ";
    std::cin >> arMatytiSarasa;
    if(arMatytiSarasa == "t"){
        spausdinimas = true;
    }
}

Studentas::Studentas(const Studentas& Kopija)
    : vardas(Kopija.vardas), pavarde(Kopija.pavarde), pazymiai(Kopija.pazymiai),
      namuDarbai(Kopija.namuDarbai), egzaminas(Kopija.egzaminas) {}

Studentas& Studentas::operator=(const Studentas& Kopija) {
    if (this != &Kopija) {
        vardas = Kopija.vardas;
        pavarde = Kopija.pavarde;
        pazymiai = Kopija.pazymiai;
        namuDarbai = Kopija.namuDarbai;
        egzaminas = Kopija.egzaminas;
    }
    return *this;
}

Studentas::~Studentas() {}

double Studentas::galutinisVidurkis() const {
    int suma = 0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    double vidurkis = static_cast<double>(suma) / pazymiai.size();
    return 0.4 * vidurkis + 0.6 * egzaminas;
}

double Studentas::galutinisMediana() const {
    std::vector<int> rusiuojamiPazymiai = pazymiai;
    std::sort(rusiuojamiPazymiai.begin(), rusiuojamiPazymiai.end());
    
    if (rusiuojamiPazymiai.size() % 2 == 0) {
        return (rusiuojamiPazymiai[rusiuojamiPazymiai.size() / 2 - 1] + rusiuojamiPazymiai[rusiuojamiPazymiai.size() / 2]) / 2.0;
    } else {
        return rusiuojamiPazymiai[rusiuojamiPazymiai.size() / 2];
    }
}

void Studentas::gautiRez() const {
    std::string pasirinkimas;
    
    std::cout << "Ar tai naujas failas? Įrašykite inicialą, taip = 't' arba ne = 'n': ";
    std::cin >> pasirinkimas;
    
    if(pasirinkimas == "t"){
        std::ofstream file("kursiokai.txt");
        if (!file.is_open()) {
            std::cerr << "Nepavyko atidaryti failo!" << std::endl;
        }
        file << std::left << std::setw(18) << "Pavardė" << std::setw(18) << "Vardas";
        for(int i=1; i<=5; i++){
            file << std::setw(5) << ("ND" + std::to_string(i));
        }
        file << std::setw(10) << "Egzaminas";
        file << std::endl << "---------------------------------------------------------------------" << std::endl;
        file.close();
    }
    
    std::fstream file("kursiokai.txt", std::ios::app);
    if(!file.is_open()){
        std::cerr << "Nepavyko atidaryti failo!" << std::endl;
    }
    file << std::left << std::setw(18) << pavarde << std::setw(18) << vardas;
    for (int i = 0; i < pazymiai.size(); ++i) {
        file << std::setw(5) << pazymiai[i];
    }
    file << std::setw(10) << egzaminas << std::endl;
    file.close();
}
