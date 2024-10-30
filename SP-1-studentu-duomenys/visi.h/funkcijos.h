#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "libraries.h"

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
    std::vector<std::string> likusiosEilutes;

    if (skaitomasis.is_open() && blogiIrasymas.is_open()) {
        std::getline(skaitomasis, eile);
        blogiIrasymas << eile << "\n";
        likusiosEilutes.push_back(eile);

        while (std::getline(skaitomasis, eile)) {
            likusiosEilutes.push_back(eile);
        }
        skaitomasis.close();

        auto partitionPoint = std::partition(likusiosEilutes.begin() + 1, likusiosEilutes.end(), [](const std::string& line) {
            std::stringstream ss(line);
            std::string vardas, pavarde;
            std::vector<int> pazymiai(5);
            int egzaminas;
            float vidurkis;

            ss >> vardas >> pavarde;
            for (int i = 0; i < 5; i++) ss >> pazymiai[i];
            ss >> egzaminas >> vidurkis;

            return vidurkis >= 5.0;
        });

        std::copy(partitionPoint, likusiosEilutes.end(), std::ostream_iterator<std::string>(blogiIrasymas, "\n"));
        blogiIrasymas.close();

        std::ofstream atnaujintasFailas(sablonuFailas, std::ios::trunc);
        std::copy(likusiosEilutes.begin(), partitionPoint, std::ostream_iterator<std::string>(atnaujintasFailas, "\n"));
        atnaujintasFailas.close();

        std::cout << "Surūšiuota ir pašalinta iš originalaus failo √" << std::endl;
    } else {
        std::cerr << "Klaida. Rūšiavimas nepavyko, failai nebuvo atidaryti!";
    }
    rodytiAtmintiesSanaudasMacOS();
} //END Rusiavimo Vienam Failui Funkcija//

#endif
