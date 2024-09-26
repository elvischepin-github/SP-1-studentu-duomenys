#include "utils.h"

void matytiSarasa() {
    std::ifstream inputFile("kursiokai.txt");
    
    if (inputFile.fail()) {
        std::cerr << "Nepavyko perskaityti failo..." << std::endl;
        return;
    }

    std::vector<StudentasObj> studentai;
    std::string line;
    
    std::getline(inputFile, line);
    std::getline(inputFile, line);
    
    std::cout << std::left << std::setw(18) << "Pavardė" << std::setw(18) << "Vardas";
    for(int i=1; i<=5; i++){
        std::cout << std::setw(5) << ("ND" + std::to_string(i));
    }
    std::cout << std::setw(10) << "Egzaminas";
    std::cout << std::endl << "---------------------------------------------------------------------" << std::endl;

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        StudentasObj studentas;

        ss >> studentas.pavard >> studentas.vard
           >> studentas.pazymys1 >> studentas.pazymys2 >> studentas.pazymys3
           >> studentas.pazymys4 >> studentas.pazymys5 >> studentas.egz;

        studentai.push_back(studentas);
    }

    inputFile.close();
    
    for (const StudentasObj& studentas : studentai) {
        std::cout << std::left << std::setw(18) << studentas.pavard
        << std::setw(18) << studentas.vard
        << std::setw(5) << studentas.pazymys1
        << std::setw(5) << studentas.pazymys2
        << std::setw(5) << studentas.pazymys3
        << std::setw(5) << studentas.pazymys4
        << std::setw(5) << studentas.pazymys5
        << std::setw(10) << studentas.egz << std::endl;
    }
}
