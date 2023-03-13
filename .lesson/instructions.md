# UWAGA

**Obowiązuje zakaz wczytywania czegokolwiek z klawiatury. Jedyną funkcją (na tym etapie) której wolno cokolwiek wyświetlić na ekranie jest funkcja `debug_display()`.**

# Etap 1

Proszę opracować klasę reprezentującą planszę do gry Saper (Minesweeper)

Klasa powinna posiadać informacje o:

* rozmiarze planszy (można przyjąć, że nie przekracza pewnego ustalonego maksimum, np. 100x100)
* stanie każdego z pól:
    * ukryte lub odkryte
    * bezpieczne lub z miną
    * ma "flagę" lub jej nie ma

Wskazówka: informacje o pojedynczym polu na planszy możemy przechowywać w strukturze

```c++
struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};
```

Wszystkie pola możecie przechowywać np. w:

* dwuwymiarowej tablicy pól (```Field data[nrows][ncols];```)
* dwuwymiarowym std::vector - ale tylko jeśli jesteście absolutnie pewni, że wiecie jak to zrobić !
* niestandardowym Array2D zdefiniowanym w tym [repozytorium](https://zts.ita.pwr.wroc.pl/gitlab/bartlomiej.golenko/tools) 

**UWAGA**: niezależnie od tego na które rozwiązanie się zdecydujecie - pamiętajcie potem o sprawdzaniu, czy nie wychodzicie poza legalne indeksy !
Array2D "ułatwi" Wam to, bo po użyciu nielegalnego indeksu automatycznie zatrzyma Wasz program.

```c++
class MinesweeperBoard
{
    // wybierz jedno z poniższych

    // sugerowane:
    // Array2D<Field> board;

    // tablica 2D
    // Field board[100][100];    
    
    // wektor wektorów
    // std::vector<std::vector<Field>> board;

    // niezbędne jeśli użyjecie tablicy 2D, ale w każdym
    // przypadku wygodne
    int width;                // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy

public:
    MinesweeperBoard();
    void debug_display() const;
};
```

Waszym pierwszym zadaniem jest napisanie konstruktora klasy `MinesweeperBoard` oraz funkcji `debug_display()`. 

Konstruktor  ma:   

* ustawić wysokość i szerokość planszy - proponuję coś "rozsądnego", np. 7 wierszy i 5 kolumn; jeśli używasz Array2D, to na początku konstruktora wywołaj funkcję ```board.resize(liczba_wierszy, liczba_kolumn)```
* ustawić stan początkowy wszystkich pól planszy na: "nie ma miny", "pole zakryte", "nie ma flagi"
* pole (wiersz=0, kolumna=0) - zawiera minę, nie ma flagi i nie zostało odkryte
* pole (wiersz=1, kolumna=1) - jest odkryte, nie ma miny i nie ma flagi
* pole (wiersz=0, kolumna=2) - zawiera minę i flagę, nie jest odkryte

**UWAGA** - to że te wszystkie zadania mają być wykonane przez konstruktor nie znaczy, że nie można ich "oddelegować" do osobnej prywatnej funkcji! Zastanówcie się nad tym ;)


Funkcja debug_display() ma wyświetlić planszę w celu weryfikacji poprawności przeprowadzanych operacji - każde pole ma być wyświetlone jako ciąg 3 znaków w nawiasach kwadratowych.         

1. Znak pierwszy informuje czy na polu jest mina - jeśli jest, to wyświetlamy literę 'M'   
2. Znak drugi - czy pole jest odkryte - 'o'
3. Znak trzeci - informuje czy na polu jest flaga - 'f'
4. Miło by było, gdyby dodatkowo wyświetlone zostały numery wierszy i kolumn; to jest widok diagnostyczny (dla "programisty") zatem numerujemy od zera

Sprawdzić, czy funkcja `debug_display()` poprawnie wyświetli tą planszę, czyli czy zobaczymy:

        0    1    2    3    4
    0 [M..][...][M.f][...][...]
    1 [...][.o.][...][...][...]
    2 [...][...][...][...][...]
    3 [...][...][...][...][...]
    4 [...][...][...][...][...]
    5 [...][...][...][...][...]
    6 [...][...][...][...][...]
              

# Etap 2 - GIT
Cała praca przy projektach musi być regularnie umieszczana w repozytorium GIT.

## Obsługa GIT-a

Jeśli jeszcze takiego konta nie masz - załóż je w naszym serwisie Gitlab: https://zts.ita.pwr.wroc.pl/gitlab/users/sign_up

Zaloguj się i następnie

## Stwórz Access Token
Wejdź na swój profil (ikonka w prawym górnym roku) i wybierz opcję **Edit profile**

Z lewej strony wybierz **Access Tokens**

Wypełnij pola:
- token name = replit
- expiration = 2023-08-01 (co najmniej koniec semestru albo usunąć całkowicie)
- zaznacz **"write_repository"**

Naciśnij **Create personal token**

**UWAGA** - SKOPIOWAĆ ZAWARTOŚĆ POLA **"Your new personal access token"**

Zawartość tego pola zniknie po przeładowaniu strony i jeśli go nie zapiszecie
to jedyną możliwością jest skasowanie tokenu i stworzenie go od nowa!

Przykładowy token: **glpat-GXda3VM2W9i1yxTMx7Qs**


## Stwórzcie pusty projekt
Wróćcie na główną stronę Gitlaba - [ikonka liska w lewym górnym rogu](https://zts.ita.pwr.wroc.pl/gitlab/)

Wybieramy **New project** i następnie **Create blank project**

Wypełniamy pola:
- project name = "SAPER_imie_nazwisko" (oczywiście Wasze imię i nazwisko - to ułatwi mi potem sprawdzanie)
- **WYŁĄCZ** checkbox **Initialize repository with a README**

Skopiuj sobie zawartość sekcji **Git global setup** oraz **Push an existing folder** - za chwilę się przydadzą.

## Konfiguracja Replit

Część konfiguracji git-a można wykonać "klikaniem", ale jest to przeznaczone przede wszystkim dla osób korzystających z GitHub-a. W przypadku Gitlaba większość operacji i tak trzeba wykonać z wiersza poleceń, zatem zacznijcie od uruchomienia **Shell**-a

### Inicjalizacja repozytorium
Pomijamy pierwszą instrukcję z **Push an existing folder** i wpisujemy na początek tylko **drugą**, pomijając opcję ```--initial-branch``` (polecenie git z replit jeszcze jej nie obsługuje):
```
$ git init 
```

Poleceniem ```git status``` weryfikujemy, czy repozytorium jest zainicjowane - powinniście zobaczyć coś takiego:
```
$ git status
```
```
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
    new file:   .clang-format
    new file:   .gitignore
    new file:   CMakeLists.txt
    new file:   src/Array2D.h
    new file:   src/main.cpp
```

### Konfiguracja "właściciela" repozytorium
Wpisz teraz polecenia z zapisanej wczesniej sekcji **Git global setup** - sugeruję tylko, żeby zamienić ```--global``` na ```--local``` (kiedyś replit resetował w nieprzewidywalny sposób konfigurację globalną i generowało to sporo problemów)
```
$ git config --local user.name "Bartłomiej Golenko"
$ git config --local user.email "bartlomiej.golenko@pwr.edu.pl"
```
Ustawienia można zweryfikować poleceniem
```
$ git config --list
```
```
core.excludesfile=/etc/.gitignore
user.name=Bartłomiej Golenko
user.email=bartlomiej.golenko@pwr.edu.pl
core.repositoryformatversion=0
core.filemode=true
core.bare=false
core.logallrefupdates=true
```

## Konfiguracja zdalnego repozytorium
Kolejnym krokiem jest ustawienie adresu zdalnego repozytorium, z którym ma się synchronizować replit.

### Konfiguracja remote
W **Shell**-u wpisujemy trzecie polecenie z **Push an existing folder**. Przykładowo - dla mojego repozytorium to byłoby
```
$ git remote add origin https://zts.ita.pwr.wroc.pl/gitlab/bartlomiej.golenko/saper2023.git
```
**UWAGA**: Jeśli na koncie w Gitlabie macie skonfigurowany klucz ssh, to prawdopodobnie tutaj zobaczycie adres o postaci ```ssh://git@zts.ita.pwr.wroc...```. Wersję "https" można odczytać rozwijając menu **Clone**.


### Hasło
Z lewej strony w **Tools** wybieramy opcję **Secrets**. Dodajemy nowy sekret o nazwie np. GIT_URL i jako jego wartość wpisujemy adres repozytorium, uzupełniony o login i **personal access token**:
```
https://USER:TOKEN@zts.ita.pwr.wroc.pl/gitlab/bartlomiej.golenko/saper2023.git
```
zapisany wcześniej **Personal Access Token** z Gitlaba.

Przykładowo - ja wpisałbym coś takiego (w jednej linii):
```
https://bartlomiej.golenko:glpat-GXda3VM2W9i1yxTMx7Qs@zts.ita.pwr.wroc.pl/gitlab/bartlomiej.golenko/saper2023.git
```



Sprawdzamy w **Shell** (jeśli jest otwarty - trzeba go zamknąć i otworzyć ponownie z **Tools**)
```
$ echo $GIT_URL
```
Powinien wyświetlić się wpisany wcześniej adres z loginem i hasłem.

### Dodajemy pliki do repozytorium i wypychamy je do Gitlaba
Najpierw poleceniem ```git status``` sprawdzamy, co jest do dodania. 

```
$ git status
```
```
Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
    new file:   .clang-format
    new file:   .gitignore
    new file:   CMakeLists.txt
    new file:   src/Array2D.h
    new file:   src/main.cpp
```
Jeśli nie ma tu nic niespodziewanego, dodajemy te pliki do tzw staging area (indeksu)
```
$ git add .
```
Możecie sprawdzić poleceniem ```git status``` co się zmieniło w stanie repozytorium.

Kolejna operacja - trzeba dodane pliki wysłać do lokalnego repozytorium
```
$ git commit -m "Initial commit"
```

Na koniec wysyłamy zmiany do Gitlaba
```
$ git push $GIT_URL
```
Jeśli pojawi się błąd lub pytanie o hasło - upewnijcie się, że 
wpisaliście w sekretach poprawny adres repozytorium, login i hasło.
    
# Etap 3

## Podziel projekt na osobne pliki:
- przenieś deklaracje typów do pliku MinesweeperBoard.h
- przenieś implementacje funkcji składowych klasy MinesweeperBoard do pliku MinesweeperBoard.cpp
- w main.cpp powinna zostać **TYLKO** funkcja ```main()```

## Rozbudowa projektu
Proszę rozbudować klasę MinesweeperBoard poprzez dodanie do niej drugiego konstruktora:

```c++

enum GameMode  { DEBUG, EASY, NORMAL, HARD };

class MinesweeperBoard
{
    // ...
    
public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    // ...
};
```

Konstruktor ma działać w następujący sposób
1. Ustawia odpowiednio rozmiar planszy, zgodnie z przekazanymi parametrami (UWAGA - nie pomylcie wierszy z kolumnami !)
2. W zależności od trybu rozmieszcza na planszy miny
   - EASY   - miny ma 10% pól (rozmieszczone losowo)
   - NORMAL - miny ma 20% pól (rozmieszczone losowo)
   - HARD   - miny ma 30% pól (rozmieszczone losowo)
       - jeśli konieczne jest zaokrąglenie liczby min, to należy je wykonywać zawsze w górę
       - w trybach z losowym rozmieszczeniem zwróćcie uwagę na to by nie wstawiać miny na to samo pole więcej niż raz.

   - DEBUG  - predefiniowany układ min
        - wszystkie pola na przekątnej mają minę
        - wszystkie pola w pierwszym wierszu mają minę
        - co drugie pole w pierwszej kolumnie ma minę

Przykładowo:
```
    0    1    2    3    4    5    6    7    8
0 [M..][M..][M..][M..][M..][M..][M..][M..][M..]
1 [...][M..][...][...][...][...][...][...][...]
2 [M..][...][M..][...][...][...][...][...][...]
3 [...][...][...][M..][...][...][...][...][...]
4 [M..][...][...][...][M..][...][...][...][...]
5 [...][...][...][...][...][M..][...][...][...]
6 [M..][...][...][...][...][...][M..][...][...]
```




**Zaktualizuj zawartość repozytorium na Gitlabie**

Sprawdzamy co się zmieniło
```
$ git status
```
Dodajemy pliki przeznaczone do zaktualizowania lub dodania do git-a
```
$ git add plik1
$ git add plik2
...
```
Ponownie sprawdzamy:
```
$ git status
```
Jeśli jest OK:
```
$ git commit -m "Komentarz opisujący co zmieniliśmy"
```
Wypychamy do Gitlaba
```
$ git push $GIT_URL
```




