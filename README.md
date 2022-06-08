-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Naudojimosi instrukcija**

1. Paleidus programą pasirenkame ar norime sugeneruoti 5 failus su studentų įrašais (jie bus reikalingi, tik tuo atveju jei norėsite įvykdyti programos spartos analizę).
2. Kitas 'taip/ne' pasirinkimas: 10 išvesties failų sugeneravimas (taip pat reikalingi tik tuo atveju, jei vykdysite spartos analizę).
3. Dabar, jei vykdysite spartos analizę, galite pasirinkti kurį konteinerį norėtumėte ištirti (1 - vector, 2 - list, 3 -deque). Įveskite 4, jei tyrimo vykdyti nenorite.
4. Toliau galima išbandyti programos veikima rankiniu būdu. Pasirinkite p (patys), jeigu studentų vardus, pavardes, namų darbų įvertinimus ir egzamino balą norite įvesti patys arba f (iš failo), jeigu norite apdoroti šiuos duomenis iš tekstinio failo.

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

**Testų ir tyrimų rezultatai:**

**v0.4**

Programos spartos analizė
Failų generavimas:
- 1000 įrašų - 0.047s;
- 10000 įrašų - 0.362s;
- 100000 įrašų - 1.58s
- 1000000 įrašų - 12.178s
- 10000000 įrašų - 118.688s

Failų apdorojimo laikai (vector konteineris):
- '1000.txt' - 0.015s
- '10000.txt' - 0.096s
- '100000.txt' - 0.934s
- '1000000.txt' - 9.694s
- '10000000.txt' - 91.992s

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

**v0.5**

Programos spartos analizė
Failų apdorojimo laikai (deque konteineris):
- '1000.txt' - 0.014s
- '10000.txt' - 0.109s
- '100000.txt' - 1.051s
- '1000000.txt' - 11.753s
- '10000000.txt' - 116.606s

Failų apdorojimo laikai (list konteineris):
- '1000.txt' - 0.013s
- '10000.txt' - 0.108s
- '100000.txt' - 0.930s
- '1000000.txt' - 9.251s
- '10000000.txt' - 78.877s

Išvados:
- nuskaitymo laikas tarp konteinerių skiriasi minimaliai;
- rūšiavimas pagal pavardę: greičiausias - list, lėčiausias - deque;
- išskyrimas į vieną iš dviejų konteinerių pagal vidurkį: greičiausias - deque, lėčiausias - list.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

**v1.0**

Programos spartos analizė (lėtesnis kompas)
Failų apdorojimo laikai (vector konteineris, nauja 2 strategija):
- '1000.txt' - 0.062s
- '10000.txt' - 0.297s
- '100000.txt' - 2.906s
- '1000000.txt' - 31.123s
- '10000000.txt' - 349.179s

Failų apdorojimo laikai (deque konteineris, nauja 2 strategija):
- '1000.txt' - 0.109s
- '10000.txt' - 0.36s
- '100000.txt' - 3.718s
- '1000000.txt' - 42.06s
- '10000000.txt' - 456.421s

Failų apdorojimo laikai (list konteineris, nauja 2 strategija):
- '1000.txt' - 0.078s
- '10000.txt' - 0.266s
- '100000.txt' - 2.765s
- '1000000.txt' - 27.608s
- '10000000.txt' - 292.057s

Išvada:
- 2 strategija efektyvesnė su vector ir list konteineriais, vos vos lėtesnė su deque.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

**v1.1**

v1.0 (struct) ir v1.1 (class) spartos palyginimas:

![lyginimas](https://user-images.githubusercontent.com/100161683/172133303-524eecdb-39fe-490f-8113-54f2bc4441a8.png)

**IŠVADA:**
- Mano atveju v1.1 greičiau veikia su mažesnies apimties failais, o v1.0 su didesnės.

Eksperimentinė v1.1 spartos analizė, priklausomai nuo kompiliatoriaus optimizavimo lygio (O1, O2, O3):

![flagai](https://user-images.githubusercontent.com/100161683/172133562-c8729cbb-ea19-492b-915d-98abbea859f5.png)

**IŠVADA:**
- Apskritai su optimizavimo flagais programa veikia greičiau, bet didelio laiko skirtumo tarp O1, O2 ir O3 nepastebėjau.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
