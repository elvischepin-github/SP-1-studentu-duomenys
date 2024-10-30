#include "libraries.h"
#include "studentas.h"

//START Atminties Matavimo Funkcija// Windows Windows Windows
//void rodytiAtmintiesSanaudasWindows() {
//    PROCESS_MEMORY_COUNTERS pmc;
//    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
//        std::cout << "Atminties sąnaudos po rūšiavimo funkcijos: " << pmc.WorkingSetSize / 1024 << " KB" << std::endl;
//    } else {
//        std::cerr << "Negalima pasiekti atminties sąnaudų." << std::endl;
//    }
//} //END Atminties Matavimo Funkcija//

//START Atminties Matavimo Funkcija// macOS macOS macOS
void rodytiAtmintiesSanaudasMacOS() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        std::cout << "Atminties sąnaudos po rūšiavimo funkcijos: " << usage.ru_maxrss << " KB" << std::endl;
    } else {
        std::cerr << "Negalima pasiekti atminties sąnaudų." << std::endl;
    }
} //END Atminties Matavimo Funkcija//

//START Rusiavimo Dviems Failams Funkcija//
void rusiuotiStudentusDviejoseFailuose(const std::string& sablonuFailas, const std::string& geriFailas, const std::string& blogiFailas){
    
    std::ifstream skaitomasis(sablonuFailas);
    std::ofstream geriIrasymas(geriFailas);
    std::ofstream blogiIrasymas(blogiFailas);
    
    std::string eile;
    
    if(skaitomasis.is_open() && geriIrasymas.is_open() && blogiIrasymas.is_open()){
        std::getline(skaitomasis, eile);
        geriIrasymas << eile << "\n";
        blogiIrasymas << eile << "\n";
        
        while(std::getline(skaitomasis, eile)){
            std::stringstream ss(eile);
            std::string vardas, pavarde;
            std::vector<int> pazymiai(5);
            int egzaminas;
            float vidurkis;
            
            ss >> vardas >> pavarde;
            for (int i = 0; i < 5; i++){
                ss >> pazymiai[i];
            }
            ss >> egzaminas;
            ss >> vidurkis;
            
            if(vidurkis >= 5.0){
                geriIrasymas << eile << "\n";
            } else blogiIrasymas << eile << "\n";
        }
        std::cout << "Surūšiuota √" << std::endl;
    } else {
        std::cerr << "Klaida. Rūšiavimas nepavyko, failai nebuvo atidaryti!";
    }
    
    rodytiAtmintiesSanaudasMacOS();
} //END Rusiavimo Dviems Failams Funkcija//

//START Rusiavimo Vienam Failui Funkcija//
void rusiuotiStudentusVienameFaile(const std::string& sablonuFailas, const std::string& blogiFailas) {
    std::ifstream skaitomasis(sablonuFailas);
    std::ofstream blogiIrasymas(blogiFailas);
    
    std::string eile;
//    std::vector<std::string> likusiosEilutes; // VECTOR
//    std::list<std::string> likusiosEilutes; // LIST
    std::deque<std::string> likusiosEilutes; // DEQUE
    
    if (skaitomasis.is_open() && blogiIrasymas.is_open()) {
        std::getline(skaitomasis, eile);
        blogiIrasymas << eile << "\n";
        likusiosEilutes.push_back(eile);
        
        while (std::getline(skaitomasis, eile)) {
            std::stringstream ss(eile);
            std::string vardas, pavarde;
            std::vector<int> pazymiai(5);
            int egzaminas;
            float vidurkis;
            
            ss >> vardas >> pavarde;
            for (int i = 0; i < 5; i++) {
                ss >> pazymiai[i];
            }
            ss >> egzaminas;
            ss >> vidurkis;
            
            if (vidurkis < 5.0) {
                blogiIrasymas << eile << "\n";
            } else {
                likusiosEilutes.push_back(eile);
            }
        }

        skaitomasis.close();
        blogiIrasymas.close();
        
        std::ofstream atnaujintasFailas(sablonuFailas, std::ios::trunc);
        for (const auto& line : likusiosEilutes) {
            atnaujintasFailas << line << "\n";
        }
        
        std::cout << "Surūšiuota ir pašalinta iš originalaus failo √" << std::endl;
    } else {
        std::cerr << "Klaida. Rūšiavimas nepavyko, failai nebuvo atidaryti!";
    }

    rodytiAtmintiesSanaudasMacOS();
} //END Rusiavimo Vienam Failui Funkcija//

int main() {
    srand((unsigned int)time(0));
    
//    std::vector<Studentas> studentai; // VECTOR
//    std::list<Studentas> studentai; // LIST
    std::deque<Studentas> studentai; // DEQUE
    
    std::cout << "Pasirinkite sąrašo dydį įvesdami atitinkamą skaičių:" << std::endl;
    std::cout << "1 - 1 000" << std::endl;
    std::cout << "2 - 10 000" << std::endl;
    std::cout << "3 - 100 000" << std::endl;
    std::cout << "4 - 1 000 000" << std::endl;
    std::cout << "5 - 10 000 000" << std::endl;
    int pasirinkimas, sarasoIlgis;
    std::cin >> pasirinkimas;
    
    switch (pasirinkimas) {
        case 1:
            sarasoIlgis = 1000;
            break;
        case 2:
            sarasoIlgis = 10000;
            break;
        case 3:
            sarasoIlgis = 100000;
            break;
        case 4:
            sarasoIlgis = 1000000;
            break;
        case 5:
            sarasoIlgis = 10000000;
            break;
        default:
            std::cout << "Pasirinkimas neteisingas! Galite pasirinkti tik vieną skaičių nuo 1 iki 5!\n";
            exit(1);
    }

    //CHRONO START!!!
    auto pradetiGeneravima = std::chrono::high_resolution_clock::now();
    
    std::ofstream irasymoFailas;
    irasymoFailas.open("sablonai.txt");
    if(irasymoFailas.is_open()){
        //START Antraštė//
        irasymoFailas   << std::left
                        << std::setw(18) << "VARDAS"
                        << std::setw(18) << "PAVARDE";
        for(int i = 1; i <= 5; i++){
            irasymoFailas << std::right << std::setw(6) << ("ND" + std::to_string(i));
        }
        irasymoFailas   << std::right << std::setw(6) << "EGZ"
                        << std::setw(8) << "VID\n";
        //END Antraštė//
        for(int i = 1; i <= sarasoIlgis; i++){
            std::string vardas = "vardas" + std::to_string(i);
            std::string pavarde = "pavarde" + std::to_string(i);
            Studentas studentas(vardas, pavarde);
            studentas.generuotiPazymius();
            studentas.apskaiciuotiVidurki();
            studentai.push_back(studentas);
            
            irasymoFailas   << std::left
                            << std::setw(18) << studentas.gautiVarda()
                            << std::setw(18) << studentas.gautiPavarde();
            
            std::vector<int> pazymiai = studentas.gautiPazymius();
            for(int pazymys : pazymiai){
                irasymoFailas << std::right << std::setw(6) << pazymys;
            }
            
            irasymoFailas   << std::right << std::setw(6) << studentas.gautiEgzamina()
                            << std::setw(8) << std::fixed << std::setprecision(2) << studentas.gautiVidurki() << "\n";
        }
        std::cout << "Atminties buvo sunaudota " << sizeof(studentai) + (sizeof(Studentas) * studentai.size()) << " baitai.\n";

    irasymoFailas.close();
    
    //CHRONO END!!!
    auto baigtiGeneravima = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> generavimoLaikas = baigtiGeneravima - pradetiGeneravima;
        
    std::cout << "Sugeneruota √" << std::endl;
    std::cout << "Generavimo laikas: " << generavimoLaikas.count() << " sekundės." << std::endl;
        
    } else {
    std::cerr << "Klaida... Nepavyko atidaryti failo!" << std::endl;
    }
    
    std::cout << "Ar rūšiuoti studentus į gerai bei blogai besimokančius?" << std::endl;
    std::cout << "Įveskite skaičių:" << std::endl;
    std::cout << "1 - TAIP" << std::endl;
    std::cout << "2 - NE" << std::endl;
    int arRuosuotiPasirinkimas;
    std::cin >> arRuosuotiPasirinkimas;
    
    //CHRONO START!!!
    auto pradetiRusiavima = std::chrono::high_resolution_clock::now();
    
    if(arRuosuotiPasirinkimas == 1){
//        rusiuotiStudentusDviejoseFailuose("sablonai.txt", "geri.txt", "blogi.txt");
        rusiuotiStudentusVienameFaile("sablonai.txt", "blogi.txt");
    } else std::cout << "Programa baigta." << std::endl;
    
    //CHRONO END!!!
    auto baigtiRusiavima = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> rusiavimoLaikas = baigtiRusiavima - pradetiRusiavima;
    std::cout << "Rūšiavimo laikas: " << rusiavimoLaikas.count() << " sekundės." << std::endl;
  
    return 0;
}
