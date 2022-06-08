-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Buvę release'ai**:

v0.1:
- Įgyvendintas vartotojo duomenų įvedimas (v.01_mas - į masyvą, v.01_vek - į vektorių);
- Lentelės sudarymas išvedime pagal vartotojo įvestus studentų duomenis, galutinio balo suskaičiavimas pagal vidurkį ir medianą (0.4 * Vidurkis/Mediana+ 0.6 * Egzaminas).

v0.2:
- Įgyvendintas duomenų nuskaitymas iš failo;
- Output'as surūšiuojamas pagal studentų pavardes.

v0.3:
- v.02 kodo reorganizavimas iš main.cpp į atskirus header ir cpp failus;
- Minimalus exception handling pritaikymas.

v0.4:
- Sukurtas failų generatorius sugeneruojantis failus su 1000, 10000, 100000, 1000000, 10000000 įrašų;
- Įgyvendintas studentų rūšiavimas į 'gerus' (galutinis vidurkis >= 5) ir 'blogus' (galutinis vidurkis < 5);
- Aprašyta programos spartos analizė.

v0.5:
- Be vector konteinereio galima pasirinkti list arba deque;
- Įvykdyta nauja spartos analizė su kiekvienu konteineriu.

v1.0:
- Įgyvendinta 2 skirstymo strategija konteineriams;
- Atnaujinta spartos analizė.

v1.1:
- Struktūra pakeista į klasę (Studentas);
- Įvykdyta v1.0 (struct) ir v1.1 (class) spartos analizė;
- Įvykdyta ekperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio (O1, O2, O3).

v1.2:
- Klasei pritaikytas "Rule of Three";
- Sukurtas papildomas operatorius.

v1.5:
- Sukurtas dar viena klasė - bazinė (Zmogus). Iš jos derived tampa klasė "Studentas";
- Klasė "Zmogus" padaryta į abstrakčią.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Naudojimosi instrukcija**

1. Paleidus programą pasirenkame ar norime sugeneruoti 5 failus su studentų įrašais (jie bus reikalingi, tik tuo atveju jei norėsite įvykdyti programos spartos analizę).
2. Kitas 'taip/ne' pasirinkimas: 10 išvesties failų sugeneravimas (taip pat reikalingi tik tuo atveju, jei vykdysite spartos analizę).
3. Dabar, jei vykdysite spartos analizę, galite pasirinkti kurį konteinerį norėtumėte ištirti (1 - vector, 2 - list, 3 -deque). Įveskite 4, jei tyrimo vykdyti nenorite.
4. Toliau galima išbandyti programos veikima rankiniu būdu. Pasirinkite p (patys), jeigu studentų vardus, pavardes, namų darbų įvertinimus ir egzamino balą norite įvesti patys arba f (iš failo), jeigu norite apdoroti šiuos duomenis iš tekstinio failo.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
