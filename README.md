# WizardTowerGame
Projekt z PO
Aby odpalić musicie mieć zainstalowane:

-cmake

-gcc

-gdb

-libsfml

-libsfml-dev

-git

-clion

Instalacja tych pakietów jest prosta i sprowadza się do wpisania w Google <nazwa dystrybucji linuxa> <nazwa pakietu> installation I wykonaniu kroków z przewaznie pierwszego linku.

Gdy już macie wszystko zaczynamy zabawę.
Uruchamiacie cliona wybieracie open Project from git/vcs  czy coś takiego
Wyświetli się okienko dialogowe w które wpisujcie link do tego repozytorium
Potwierdzanie tyle razy ile będzie trzeba. Być może clion poprosi was o passy do githuba wpiszcie je i potwierdzenie.
mozna tez wykonac polecenie $ git clone <adres_tego_repozytorium>
Brawo otworzyliscie projekt.
Teraz kilka prostych słów jak pracować z gitem.
Jeśli chcecie pobrać aktualną wersję projektu musicie wykonać polecenie
$ git pull 
lub w clionie kliknąć po lewej stronie w projekt prawym przyciskiem myszy z rozwiniętego menu wybrać git>pull 

Aby utworzyc commit
$ git add all&&git commit -m '<komentarz do wykonanych zmian>'
lub oczywiscie znalesc odpowiednia opcje w tym samym menu co na górze.
 
 Aby zapisac zmiany na serwerze polecenie $ git push -u origin <nazwa_brancha> lub odpowiednia opcja w menu cliona.
 
 Utworzenie nowego brancha

$ git checkout master

$ git pull

$ git git checkout -b <nazwa_nowego_brancha> 


Aby zmieniĉ branch na którym pracujecie 

 $ git checkout <nazwa_brancha>
 
 Jeŝli nie pracowaliŝcie wczeŝniej z gitem pewnie zastanawiacie się co to te commity branche i po co to w ogóle. Już tłumaczę.
 Git jes ŝwietnym narzedziem do wspólnego pracowania nad projektem.
 Gdy wszyscy piszemy 
 
