#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "libraries.h"

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis;

public:
    Studentas(std::string vardas, std::string pavarde) {
        this->vardas = vardas;
        this->pavarde = pavarde;
        pazymiai = std::vector<int>(5);
        egzaminas = 0;
        vidurkis = 0.0;
    };
    ~Studentas(){};
    
    void generuotiPazymius(){
        for (int i = 0; i < 5; i++){
            pazymiai[i] = rand() % 11;
        }
        egzaminas = rand() % 11;
    }
    
    void apskaiciuotiVidurki(){
        int suma = 0;
        for (int pazymys : pazymiai){
            suma += pazymys;
        }
        vidurkis = ((suma / 5) + egzaminas) / 2;
    }
    
    //START Gavimas//
    std::string gautiVarda() const {
        return vardas;
    }
    std::string gautiPavarde() const {
        return pavarde;
    }
    std::vector<int> gautiPazymius() const {
        return pazymiai;
    }
    int gautiEgzamina() const {
        return egzaminas;
    }
    float gautiVidurki() const {
        return vidurkis;
    }
    //END Gavimas//
};

#endif
