#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "libraries.h"

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int namuDarbai = 5;
    int egzaminas;

public:
    bool spausdinimas = false;

    Studentas(std::string vardas, std::string pavarde);
    Studentas(const Studentas& Kopija);
    Studentas& operator=(const Studentas& Kopija);
    ~Studentas();

    double galutinisVidurkis() const;
    double galutinisMediana() const;
    void gautiRez() const;
};

#endif
