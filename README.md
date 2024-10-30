### APRAŠYMAS _programa buvo sukurta naudojantis Xcode IDE_
---------------------------------------------------------------------------------------------------------------
### Pirma Sinchronizacija v0.1
Programa buvo sukurta naudojantis Xcode IDE.

### Instrukcija:

Programai pasileidus reikia suvesti studento duomenis paeiliui,
t.y. vardą, pavardę, pažymių skaičių, kiekvieno pažymio balą ir
galiausiai egzamino balą.

- Panaudota "Rule of Three". Ją galima patikrinti nuėmus šios dalies kodą:

```
//    ------------kopijavimas-------------------------
//    Studentas student2("Tomas", "Tomaitis", 3);
//    student2.gautiRez();
////    ------------priskyrimas-------------------------
//    Studentas student3("Romas", "Romanovas", 4);
//    Studentas student4 = student3;
//    student3.gautiRez();
```
---------------------------------------------------------------------------------------------------------------
### Antra Sinchronizacija v0.1

### Instrukcija:

Programai pasileidus, reikia suvesti studento duomenis paeiliui,
t.y. vardą, pavardę, pažymių skaičių.

Sekantis žingsnis, atsakykite ar norite, kad balai būtų sugeneruojami atsitiktiniu būdu ar įvesite juos patys.
**Atsakymą rašykite didžiosiomis raidėmis!**

- Atsitiktinis? Įrašyti _"TAIP"_.

- Įrašysite patys? Įrašyti _"NE"_.

Tada pasirenkame skaičiavimo būdą.
**Atsakymą rašykite skaičiumi!**

- Įrašykite _"1"_  vidurkio skaičiavimas.
- Įrašykite _"2"_ medianos skaičiavimas.
---------------------------------------------------------------------------------------------------------------
### Trecia Sinchronizacija v0.1

Programa buvo sukurta naudojantis Xcode IDE.

### Instrukcija:

Šioje programoje įvedus duomenis jie bus išsaugoti _kursiokai.txt_ faile.

Programai pasileidus reikia suvesti studento duomenis paeiliui,
t.y. vardą, pavardę, šį kart balų kiekis yra fiksuotas lygus 5.

Sekantis žingsnis, atsakykite ar norite, kad balai būtų sugeneruojami atsitiktiniu būdu ar įvesite juos patys.
**Atsakymą rašykite mažosiomis raidėmis!**

- Atsitiktinis? Įrašyti _"t"_.

- Įrašysite patys? Įrašyti _"n"_.

Tada pasirenkame ar norėsite pamatyti esamą sąrašą ar ne.
**Atsakymą rašykite mažosiomis raidėmis!**

- Norite pamatyti sąrašą, įrašyti _"t"_.

- Nenorite pamatyti sąrašo, įrašyti _"n"_.

Galiausiai, klausimas, o gal tai naujas failas?
**Atsakymą rašykite mažosiomis raidėmis!**

- Naujas, įrašyti _"t"_.

- Esamas, įrašyti _"n"_.

Kaip ir buvo minėta, duomenys bus kaupiami ir skaitomi iš _kursiokai.txt_.

---------------------------------------------------------------------------------------------------------------
### Sinchronizacija_v0.2

### INSTRUKCIJA IR INFORMACIJA

Programa leidžia sugeneruoti penkis studenų sąrašų ilgius iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų.

Sugeneravus sąrašą galima jį rūšiuoti.

_Chrono_ apskaičiuoja laiką, pagal nutylėjima programa dirba su VECTOR masyvu, kuris beto pagal rezultatus yra greičiausas.

Čia yra patalpinti rezultatai generuojant visų rūšių failus bei juos rušiuojant. **Numeracija nurodo užimtą greitumo vietą**.
1. VECTOR-Rez.txt
2. DEQUE-Rez.txt
3. LIST-Rez.txt

> Buvo bandoma padaryti pasirinkimą dėl norimo masyvo tipo, bet programos struktūra to padaryti neleido, taigi paaiškinimas žemiau, pasakantis kaip patikrinti savarankiškai.

Norint savarankiškai patikrinti ir išbandyti kitus masyvo tipus galima tai padaryti užkomentavus atitinakamą eiltuę _main.cpp 46-48_.

### REZULTATAI

`->>> std::vector <<<- // main.cpp 46
Pasirinkite sąrašo dydį įvesdami atitinkamą skaičių:
5 - 10 000 000
Sugeneruota √
Generavimo laikas: 25.1798 sekundės.
Ar rūšiuoti studentus į gerai bei blogai besimokančius?
1 - TAIP
Surūšiuota √
Rūšiavimo laikas: 37.4186 sekundės.
///`

`->>> std::list <<<- main.cpp 47
Pasirinkite sąrašo dydį įvesdami atitinkamą skaičių:
5 - 10 000 000
Sugeneruota √
Generavimo laikas: 27.5014 sekundės.
Ar rūšiuoti studentus į gerai bei blogai besimokančius?
1 - TAIP
Surūšiuota √
Rūšiavimo laikas: 47.7448 sekundės.
///`

`->>> std::deque <<<- main.cpp 48
Pasirinkite sąrašo dydį įvesdami atitinkamą skaičių:
5 - 10 000 000
Sugeneruota √
Generavimo laikas: 27.0858 sekundės.
Ar rūšiuoti studentus į gerai bei blogai besimokančius?
1 - TAIP
Surūšiuota √
Rūšiavimo laikas: 47.8869 sekundės.
///`

---------------------------------------------------------------------------------------------------------------
### Sinchronizacija_v1.0

Buvo išbandomos 1 ir 2 strategijos sėkmingai.

Šioje sinchronizacijoje  

> sablonai.txt

rūšiavimo metu antroje strategijoje tampa 

> geri.txt

taigi _sablonai.txt_ geri ir _blogi.txt_ yra blogi, rūšiuodami atsisakome vieno failo.

### Laiko matavimai užfiksuoti.
### Atminties sąnaudos užfiksuotos.

### Buvo naudojami std::partition ir std::copy algoritmai:
1. Veikia efectyviau, nes mažiau kartų turi praeiti per duomenis.
2. Išnaudoja geriau atmintį, alokuoja atmintį tinkamiau.
3. Supaprastinta logika, leidžianti lengviau rūpintis ir gerinti koda (bei skaityti).

### REZULTATAI

/\/\/\/\/\/\

->>> std::vector <<<- // main.cpp 70eil. && 119eil.
[215eil. funckijos kvietimas]
Įrašymo sąnaudos: 10 000 000 - Atminties buvo sunaudota 800000024 baitai.
1) STRATEGIJA: Atminties sąnaudos po rūšiavimo funkcijos: 10 000 000 - 2065743872 KB ~ 1.97 GB
[216eil. funckijos kvietimas]
2) STRATEGIJA: Atminties sąnaudos po rūšiavimo funkcijos: 10 000 000 - 2255060992 KB ~ 2.10 GB

/\/\/\/\/\/\

->>> std::list <<<- main.cpp 71eil. && 120eil.
[215eil. funckijos kvietimas]
Įrašymo sąnaudos: 10 000 000 - Atminties buvo sunaudota 800000024 baitai.
1) STRATEGIJA: Atminties sąnaudos po rūšiavimo funkcijos: 10 000 000 - 1306411008 KB ~ 1.22 GB
[216eil. funckijos kvietimas]
2) STRATEGIJA: Atminties sąnaudos po rūšiavimo funkcijos: 10 000 000 - 2044411904 KB ~ 1.90 GB

/\/\/\/\/\/\

->>> std::deque <<<- main.cpp 72eil. && 121eil.
[215eil. funckijos kvietimas]
Įrašymo sąnaudos: 10 000 000 - Atminties buvo sunaudota 800000048 baitai.
1) STRATEGIJA: Atminties sąnaudos po rūšiavimo funkcijos: 10 000 000 - 1148993536 KB ~ 1.07 GB
[216eil. funckijos kvietimas]
2) STRATEGIJA: Atminties sąnaudos po rūšiavimo funkcijos: 10 000 000 - 1765326848 KB ~ 1.64 GB

/\/\/\/\/\/\

---------------------------------------------------------------------------------------------------------------
### Finalinis v1.0

### REZULTATAI

/\/\/\/\/\/\

->>> std::vector <<<-
Atminties sąnaudos po rūšiavimo funkcijos: 10 000 000 - 2859728896 KB ~ 2.66 GB
Rūšiavimo laikas: 37.7243 sekundės.
Buvo naudojami std::partition ir std::copy algoritmai:
- Veikia efectyviau, nes mažiau kartų turi praeiti per duomenis.
- Išnaudoja geriau atmintį, alokuoja atmintį tinkamiau.
- Supaprastinta logika, leidžianti lengviau rūpintis ir gerinti koda (bei skaityti).

/\/\/\/\/\/\

### ĮKELTAS _**Makefile**_

INSTRUKCIJA: Paleisti _studentu_duomenys_ failą su administratoriaus teisėmis, reikia leidimų programai įrašant.
Galite naudoti komanda: `sudo ./studentu_duomenys`
