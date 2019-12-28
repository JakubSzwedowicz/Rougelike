# Rougelike

Program jest grą typu roguelike, czyli w skrócie gracz porusza się po planszy zbudowanej wyłącznie z symboli tablicy ASCII.
Dostępne są dwie mapy, labirynt.txt oraz mapa.txt. 
Po włączeniu programu należy zacząć od wyboru poziomu trudności. W przypadku testowania zaleca się wybrać ustawienia użytkownika
i tam ustawić np.:  
hp gracza = 100,  
hp wrogów = 1,  
dmg_gracza = 100,  
liczbę pocisków = 10000,  
szybkość gry = 1.  

Są to optmymalne ustawienia do testowania.

Następnie należy wczytać mapę (Po tym kroku nie można zmienić ustawień!) i w końcu zagrać.

## Zasaday

Celem gracza jest dotrzeć i wejść na literę K, nie tracąc przy tym całego życia.

## Klawiszologia

Strzałki - ruch w 4 kierunkach,  
s - strzał,  
q - natychmiastowe przerwanie gry i powrót do menu.  

Gracz strzela w kierunku, w którym jest zwrócony. Jest to połączone z ruchem.
Zwrot gracza jest zgodny ze zwrotem ostatniego wykonanego ruchu. Oznacza to, że aby zmienić kierunek, w którym się strzela
trzeba wykonać ruch (tj. nie można obrócić się w miejscu).

## Legenda

Różne znaki opisują poszczególne elementy gry.  
G - gracz,  
K - koniec etapu,   
	element do którego gracz ma dobiec i w niego wejść aby wygrać.  
P - przeciwnik,  
	zniszczalny, mobilny, generalnie wie gdzie jest gracz, jednak obecnie zablokowałem korzystanie z tego. Porusza się bezcelu po mapie i strzela
	jeśli tylko znajdzie się na linii strzału z graczem. można go zniszczyć.  
M - mina,  
	Zniszczalny, mobilny, porusza się w kompletnie losowych kierunkach. Zadaje spore obrażenia jeśli wpadnie na gracza.  
W - wieżyczka,  
	zniszczalny, niemobilny przeciwnik, który strzela w jednym kierunku, w losowych momentach. Można go zniszczyć, 
	acz jest to raczej trudne.  
\# - ściana,  
	Niezniszczalny, niemobilny element, który wyznacza granice mapy.  
O - obiekt,  
	nieszkodliwy, sam się nie porusza. Można go zniszczyć jednak ma sporo hp. 
	Jego główną cechą jest to, że może być przesuwany przez gracza. (odpowiednik "skrzynek" itp. w grach).  
\* - pocisk,  
	jest wystrzliwywany przez G, W, P. Może niszczyć inne pociski, zadaje obrażenia zależne od strzelca. 
	istotny bug: jest możliwe strzelanie na tyle szybko, że pociski wystrzelone później doganiają i niszczą te wystrzelone wcześniej.

## Przygotowania do włączenia programu

Aby uruchomić poprawnie program należy załączyć wszystkie pliki w jednym projekcie, 
zaś folder "przykładowe mapy" umieścić w folderze z plikami źródłowymi.

### Programy dodatkowe

Nie ma większych wymagań co do oprogramowania potrzebnego do uruchomienia programu. 
W trakcie tworzenia oprogramowania korzystano z Microsoft Visual Studio Community 2019 16.1.0.

## Autor

* **Jakub Szwedowicz** - *Rougelike* - [JakubSzwedowicz](https://github.com/JakubSzwedowicz)
