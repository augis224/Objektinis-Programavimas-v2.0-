-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

• **Programos esmė**:
1) (Pasirinkimas 1) Programa paima tekstą įvesta faile 'Tekstas.txt' ir jį apdorojusi (ištrynus visus skaičius ir pašalinius simbolius) suskaičiuoja žodžių, kurie tekste pasikartoja daugiau nei vieną kartą, skaičių ir išveda tuos žodžius bei jų pasikartojimų skaičių į failą 'Zodziai.txt'. Lygiagrečiai i failą 'Lentele.txt' išvedama cross reference tipo lentelė, kurioje galime matyti koks žodis, kurioje eilutėje, kiek kartų pasikartojo.
2) (Pasirinkimas 2) Programa paima tekstą įvesta faile 'Url.txt' ir surandus  'https://...' arba 'www. ...' tipo URL, juos gražiai išveda ekrane.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

• Projektą sudaro 7 failai (1 cpp, 4 txt, 1 exe):
- main.cpp - čia rasime programos kodą: main() funkciją, bei dar dvi funkcijas: count_words() ir lentele();
- Tekstas.txt - iš čia programa ims tekstą apdorojimui (Pasirinkimas 1);
- Zodziai.txt - čia bus išvedami žodžiai, kurie 'Tekstas.txt.' pasikartojo daugiau nei kartą;
- Lentele.txt - čia bus išvedama cross reference tipo lentelė sudaryta iš informacijos iš apdoroto 'Tekstas.txt'.
- Url.txt - iš čia programa ims teksta apdorojimui (Pasirinkimas 2);
- papildomaUzd.exe - įdiegimo failas programai.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

•**v1.1 reikalavimai**:
- Suskaičiuokite, kiek kartų kiekvienas skirtingas žodis pasikartoja Jūsų tekste. Tekstą galite paimti iš bet kur, pvz.: [Vikipediją straipsnį apie Vilnių] (Geriau kad būtu kitoks tekstas, ne mažiau 1000 žodžių). Tuomet realizacijos output'e (išoriniame faile) išveskite skirtingus žodžius (kableliai, taškai ir kiti skyrybos ženklai nėra žodžiu dalis!), kurie pasikartojo dažniau negu 1 kartą, o taip pat ir count'erį, nurodantį kiek kartų konkretus žodis pasikartojo. ✔️;
- Sukurkite cross-reference tipo lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas ✔️;
- URL adresų suradimas Jūsų tekste. Kaip ir pirmos užduoties atveju, tekstą galite paimti iš bet kur, račiau būtina, kad tame tekste būtų bent keli URL'ai, pateikti "pilnu" https://www.vu.lt/ ar "sutrumpintu" pavidalu: [www.vu.lt](http://www.vu.lt/). Jūsų tikslas, iš to teksto išrinkti visus šiuos URL'us ir grąžiai atspausdinti ekrane (ar išvesti į failą)!✔️;
- Repozicija turi būti parengta pagal visus ankstesnių darbų galutinėms versijoms galiojančius reikalavimus.✔️.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Naudojimosi instrukcija:

- Sukompiliavus programą, turėsite pasirinkti įvesti vieną iš dviejų skaičių: 1 arba 2:
  - pasirinkimas 1 - žodžių, kurie tekste pasikartoja daugiau nei vieną kartą ir cross reference lentelės išvedimas.
  - pasirinkimas 2 - URL radimas tekste.
- Sekite nurodymus ant ekrano.
- Programai taip pat galite pateikti ir savo tekstus. Tereikia atsidaryti 'Tekstas.txt' arba 'Url.txt' ir įklijuoti savo tekstą. 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Įdiegimo instrukcija:

- Atsisiųskite 'papildomaUzd.exe' ir paleiskite šį failą.
- Pasirinkite 'Destination Folder'. Įprastu atveju tai bus Jūsų Desktop'as.
- Spauskite Install.
- Atidarykite 'papildomaUzd.cbp' per savo naudojamą IDE.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
