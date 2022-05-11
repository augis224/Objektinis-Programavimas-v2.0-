-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Buvę release'ai**:

v.01:
- Įgyvendintas vartotojo duomenų įvedimas (v.01_mas - į masyvą, v.01_vek - į vektorių);
- Lentelės sudarymas išvedime pagal vartotojo įvestus studentų duomenis, galutinio balo suskaičiavimas pagal vidurkį ir medianą (0.4 * Vidurkis/Mediana+ 0.6 * Egzaminas).

v.02:
- Įgyvendintas duomenų nuskaitymas iš failo;
- Output'as surūšiuojamas pagal studentų pavardes.

v.03:
- v.02 kodo reorganizavimas iš main.cpp į atskirus header ir cpp failus;
- Minimalus exception handling pritaikymas.

v.04:
- Sukurtas failų generatorius sugeneruojantis failus su 1000, 10000, 100000, 1000000, 10000000 įrašų;
- Įgyvendintas studentų rūšiavimas į 'gerus' (galutinis vidurkis >= 5) ir 'blogus' (galutinis vidurkis < 5);
- Aprašyta programos spartos analizė.

v.05:
- Be vector konteinereio galima pasirinkti list arba deque;
- Įvykdyta nauja spartos analizė su kiekvienu konteineriu.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Naudojimosi instrukcija**

1. Paleidus programą pasirenkame ar norime sugeneruoti 5 failus su studentų įrašais (jie bus reikalingi, tik tuo atveju jei norėsite įvykdyti programos spartos analizę).
2. Kitas 'taip/ne' pasirinkimas: 10 išvesties failų sugeneravimas (taip pat reikalingi tik tuo atveju, jei vykdysite spartos analizę).
3. Dabar, jei vykdysite spartos analizę, galite pasirinkti kurį konteinerį norėtumėte ištirti (1 - vector, 2 - list, 3 -deque). Įveskite 4, jei tyrimo vykdyti nenorite.
4. Toliau galima išbandyti programos veikima rankiniu būdu. Pasirinkite p (patys), jeigu studentų vardus, pavardes, namų darbų įvertinimus ir egzamino balą norite įvesti patys arba f (iš failo), jeigu norite apdoroti šiuos duomenis iš tekstinio failo.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Šį kartą tyrimai atliktas su vienu kompu:
- mano (Intel(R) Core(TM) i7-4702MQ CPU, 8GB RAM, SanDisk SSD U110 16GB SCSI Disk Device).

**Vector**:

**1 strategija**

![Mano_v 05_VECTOR](https://user-images.githubusercontent.com/100161683/167317479-59c7af46-59b1-4dc5-917f-6293e5ce4754.png)

**2 strategija**

![2_vector](https://user-images.githubusercontent.com/100161683/167783916-141ea06d-442d-4544-a467-b5ec258d410f.png)

**List**:

**1 strategija**

![Mano_v 05_LIST](https://user-images.githubusercontent.com/100161683/167317484-46170ea4-765e-4d83-aa2e-8cdafbe733d6.png)

**2 strategija**

![2_list](https://user-images.githubusercontent.com/100161683/167783986-2d2fcb1a-787e-435b-b14a-03d348ae8a1e.png)

**Deque**:

**1 strategija**

![Mano_v 05_DEQUE](https://user-images.githubusercontent.com/100161683/167317504-6d7efc11-7984-4d6c-ba0e-c40fc5f8b09f.png)

**2 strategija**

![2_deque](https://user-images.githubusercontent.com/100161683/167784002-e49715e4-8f71-40cd-b3ac-237b0e9e50fb.png)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Konteinerių palyginimas:

**1 strategijos laikai**

![1strategija](https://user-images.githubusercontent.com/100161683/167790259-595963ec-8227-4cfa-9501-7bfc051640d7.png)


**2 strategijos laikai**

![2strategija](https://user-images.githubusercontent.com/100161683/167790576-79550534-57c3-4703-9986-5fc71486b1c6.png)


*Čia kiekvieno konteinerio lentelės:
- pirmas stupelis - nuskaitymas iš failo į konteinerį;
- antras stulpelis - surūšiavimas pagal pavardę;
- trečia stulpelis - išskyrimas į vieną iš dviejų konteinerių pagal vidurkį.

**Išvada**: 2 strategija efektyvesnė su vector ir list konteineriais, vos vos lėtesnė su deque.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
