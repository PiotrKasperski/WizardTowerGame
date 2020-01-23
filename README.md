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
 $ git fetch
 $ git checkout <nazwa_brancha>
 
 Jeŝli nie pracowaliŝcie wczeŝniej z gitem pewnie zastanawiacie się co to te commity branche i po co to w ogóle. Już tłumaczę.
 Git jes ŝwietnym narzedziem do wspólnego pracowania nad projektem.
 Gdy wszyscy pracujemy nad jednym kodem kazdy pracuje nad innym jego fragmentem. Bez gita po zrobieniu jakiejs funkcj czy klasy trzeba bylo by sie wymieniac kodem. Przy dwoch osobach jeszcze jakos do zrobienia aczkolwiek i tak wprowadziloby to sporo namieszania. Git automatycznie dba o to abysmu wszyscy mieli tą samą  wersje kodu. To tak w skrócie.
 
 To teraz czym są branche oraz jak I po co z nich korzystać.

Branch to jak sama nazwa wskazuje gałąź... prawda że bardzo dużo to mówi? No to teraz dokładnie. Każdy branch jest osobna gałęzią projektu takim jakby rozgalezieniem nie wiem jak to lepiej wytłumaczyć ale jak skończę myślę że zrozumiecie o co chodzi. Mając branch główny czyli master tworzymy nowy branch powiedzmy na to hello World. Od tego momentu pracując na branch hello World nie robimy żadnych zmian w branch głównym ani żadnym innym. Dzieki temu nasz glowny branch jest zawsze działająca aplikacja nadająca się do publikacji. W momencie kiedy w branchu helloWorld zaimplementujemy cała funkcjonalność, która miała być w nim zrobiona przetestujemy to I jesteśmy pewni że to finalna wersja mergujemy tę gałąź powrotem do mastera czyli łączymy tę dwie gałęzie powrotem.
Dzieki takiej metodologii pracy odpada również konieczność mergowania kodu przy każdym pull czy pusty. Wyobraźcie sobie że dwójka programistów pracuje na tym samym branch na tych samych plikach. Za każdym razem kiedy chcą zapisać zmiany na gicie muszą mergiwac je z tym co zrobił partner. Jest to na prawdę upierdliwe!

To teraz kilka słów o commitach. Commit jest to zapis stanu kodu projektu. Robiąc domina robicie tak na prawdę 'zapisz' Prościej się chyba nie da tego wytłumaczyć więc po prostu opiszę jak się nimi posługiwać i dlaczego przydatne jest częste commitowanie. Przykładowo skonczyliscie pisać jakaś funkcję która jako tako działa wiecie że jeszcze coś tam w niej będzie trzeba podmienić ale wstepna wersja jest gotowa robicie git commit -m 'funkcja xy działa' . Bierzecie się za poprawianie funkcji poprawianie poprawianie mieszkańców aż nagle funkcja przestaje działać tak jak powinna. Stwierdzacie że jednak za bardzo nmowszaliscie i przydało by się cofnąć do działającej wersji tej funkcji klimacie ctrl+z ctrl+z itd aż do momentu kiedy kończy się pamięć zmian w programie A wy dalej nie odzyskaliscie działającej funkcji. I co dalej? Gdyby nie zrobiony wcześniej commit trzeba by było od nowa napisać funkcję tak aby działała. Ale zaraz zaraz przecież mamy commit czyli zapis stanu kodu I możemy to przywrócić. Albo nawet przywrócić tylko tą funkcję do stanu pierwotnego. Widzicie że przydatna sprawa ;). Dlatego warto jak najczęściej robić commity i dobrze je opisywać (wiadomość po -m). Ja na przykład mam w zwyczaju robić commit po napisaniu każdej funkcji lub wprowadzeniu jakiejś zmiany w już istniejącej funkcji. Utworzone commity zapisują się najpierw lokalnie A potem poprzez komendę git push przesyłane są na githuba(wysyłane są wszystkie zapisane commity dlatego uważajcie również aby nie zdominować jakiś dupadebusgòw czy innych takich...)
 
