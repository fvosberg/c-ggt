#include <stdio.h>

int ggT(int a, int b);
void test(int a, int b);

int main(int argc, char* argv[])
{
	int a = 0,
		b = 0;

	// setze den testmodus auf 1, wenn du es nicht einlesen möchtest
	int testmodus = 0;

	if(testmodus) {
		printf("### TEST ###\n");
		test(1, 3);
		test(5, 10);
		test(6, 9);
		test(1337, 1338);
	} else {
		printf("Berechnung des ggT von zwei Zahlen\n\n");
		printf("Gib Zahl 1 ein:\n");
		scanf(" %d", &a);
		printf("Gib Zahl 2 ein:\n");
		scanf(" %d", &b);

		printf("Der größte gemeinsame Teiler von %d und %d ist: %d\n", a, b, ggT(a, b));
	}
}

int ggT(int a, int b) {
	// 1 ist im Zweifel immer der ggT
	int ggT = 1;

	// wir müssen nur über alle Zahlen zwischen 1 und der kleineren Zahl iterieren
	// Optimierungsmöglichkeit: wir müssen sogar nur zwischen der kleineren Zahl und ihrer Hälfte iterieren
	int lower = a > b ? b : a;
	for(int i = lower; i > 0; i--) {
		if(a % i == 0 && b % i == 0) {
			ggT = i;
			break;
		}
	}
	return ggT;
}

// nur zum testen
void test(int a, int b) {
	printf("Der größte gemeinsame Teiler von %d und %d ist: %d\n", a, b, ggT(a, b));
}
