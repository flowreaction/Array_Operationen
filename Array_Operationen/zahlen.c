/*	Aufgabe 4.1			array_operationen
	Autor				Florian Bopp
	Datum				16.11.17
	
	Kurzbeschreibung:	

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Aufgabe (d)
void tausche(int *a, int *b) //funktino welche die Werte welche bei den adressen zweier pointer gespeichert sind tauscht.
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void drucke(int a[]) //Funtion zum drucken eines arrays
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

///////////////////Main funktion//////////////////////
int main(void) 
{
	int kette[10];
	int i, j;
	int tempa, tempb;

	/////////////////////////Aufgabe (a)//////////////////////////
	for (i = 0; i < 10; i++) //schlleife welche den Nutzer nach 10 Zahlen fragt und diese in einem Array speichert.
	{
		printf("Geben Sie die %d.te Zahl ein: ", i+1);
		scanf("%d", &kette[i]);
	}
	drucke(kette);

	////////////////////////Aufgabe (b)//////////////////////////
	tempa = kette[0];							 //Variable welche den letzten wert des arrays speichert
	printf("Nach vorne verschieben:\n");
	for ( i = 0; i < 10; i++)					 //schleife welche die werte nach rechts schiebt
	{
		if (i <9)								//if-else kondition zum weiterschieben der Werte
		{
			kette[i] = kette[i + 1];
		}
		else
		{
			kette[i] = tempa;
		}
	}
	drucke(kette);								//aktueller Array wird gedruckt
	
	tempb = kette[9];							//Variable welche das letzte glied des Arrays speichert
	printf("Nach hinten verschieben:\n");
	for ( i = 9; i >= 0; i--)					//schleife welche am ende des Arrays anfäng und nach vorne arbeitet
	{
		if (i > 0)								//if-else Kondition zum schieben der werte
		{
			kette[i] = kette[i - 1];
		}
		else
		{
			kette[i] = tempb;
		}
	}
	drucke(kette);								//aktueller Array wird gedruckt

	///////////////////////Aufgabe (d)//////////////////////////
	int *a, *b;									//zwei Pointer variablen
	a = &kette[1];								//den pointern werden Adressen zugeordnet
	b = &kette[8];
	tausche(a, b);								//funktion zum tauschen der werte wird abgerufen
	printf("Tausche zweite und neunte Zahl:\n");
	drucke(kette);								//aktueller Array wird gedruckt

	///////////////////////Aufgabe (e)//////////////////////////
	printf("Tausche unsortierte Zahlennachbarn:\n");
	for (i = 0; i < 9; i++)						//schleife welche in der länge des Arrays läuft
	{
		if (kette[i] > kette[i+1])				//if kondition zum vergleichen von zwei benachbarten Werten
		{
			tausche(&kette[i], &kette[i + 1]);	//wenn kondition erfüllt ist werden Werte getauscht
		}
	}
	drucke(kette);								//aktueller Array wird gedruckt

	/////////////////////Aufgabe (f)////////////////////////////
	printf("Tausche 9mal unsortierte Zahlennachbarn:\n");
	for ( j = 0; j < 9; j++)					//for loop in der länge des arrays
	{
		for (i = 0; i < 9; i++)					//eingebetteter for loop welcher in der länge des arrays läuft sodass die gesamte anzahl der Durchläufe n^2 ist.
		{
			if (kette[i] > kette[i + 1])		//if kondition zum vergleichen von zwei benachbarten Werten
			{
				tausche(&kette[i], &kette[i + 1]); //Funktion zum tauschen wird abgerufen
			}
		}
	}
	drucke(kette);								//aktueller Array wird gedruckt
	return 0;
}