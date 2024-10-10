#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <chrono>
#include <thread>

using namespace std;

void skorGoster(string oyuncu1, string oyuncu2, int* oyuncu1Skor, int* oyuncu2Skor) {
	cout << " ----- SKOR -----\n";
	cout << oyuncu1 << ": " << *oyuncu1Skor << endl;
	cout << oyuncu2 << ": " << *oyuncu2Skor << endl;
}

int main() {
	int tahmin;
	int deneme = 0;
	string oyuncu1, oyuncu2;

	int oyuncu1Skor = 0;
	int oyuncu2Skor = 0;

	int* pOyuncu1Skor = &oyuncu1Skor;
	int* pOyuncu2Skor = &oyuncu2Skor;


	srand(std::time(0)); // rastgele sayi olusturdum
	int hedefSayi;
	hedefSayi = std::rand() % 100 + 1; // modunu alýp 0-100 araligina dusurdum

	cout << "*** 0-100 Arasindaki Sayiyi Tahmin Etme Oyununa Hos Geldiniz ***\n";

	// 1. Oyuncu Bilgileri
	cout << "Lutfen 1.Oyuncu'nun Adini Giriniz: "; cin >> oyuncu1;
	cout << endl;
	// 2. Oyuncu Bilgileri
	cout << "Lutfen 2.Oyuncu'nun Adini Giriniz: "; cin >> oyuncu2;
	cout << endl;

	while (true) {

		if (deneme % 2 == 0) {
			cout << oyuncu1 << " Tahminini Girebilirsin: "; cin >> tahmin;

			if (tahmin > hedefSayi) {
				cout << "Daha kucuk bir deger giriniz\n";
			}
			else if (tahmin < hedefSayi) {
				cout << "Daha buyuk bir deger giriniz\n";
			}
			else {
				cout << oyuncu1 << " Tebrikler Dogru Tahmin Ettin ve 1 Puan Kazandin! ";
				cout << "Dogru Tahmin: " << hedefSayi;
				cout << endl;
				(*pOyuncu1Skor)++; // Oyuncu 1 e bir puan ekler
				std::this_thread::sleep_for(std::chrono::seconds(3)); // 3 saniye beklet
				system("CLS");
				skorGoster(oyuncu1, oyuncu2, pOyuncu1Skor, pOyuncu2Skor);
				hedefSayi = std::rand() % 100 + 1; // Yeni Sayi olusturuyor
			}
		}
		else {
			cout << oyuncu2 << " Tahminini Girebilirsin: "; cin >> tahmin;

			if (tahmin > hedefSayi) {
				cout << "Daha kucuk bir deger giriniz\n";
			}
			else if (tahmin < hedefSayi) {
				cout << "Daha buyuk bir deger giriniz\n";
			}
			else {
				cout << oyuncu2 << " Tebrikler Dogru Tahmin Ettin ve 1 Puan Kazandin!\n";
				cout << "Dogru Tahmin: " << hedefSayi;
				cout << endl;
				(*pOyuncu2Skor)++;
				std::this_thread::sleep_for(std::chrono::seconds(3)); // 3 saniye beklet
				system("CLS");
				skorGoster(oyuncu1, oyuncu2, pOyuncu1Skor, pOyuncu2Skor);
				hedefSayi = std::rand() % 100 + 1; // Sayi tahmin edildigi icin yeni tahmin olusturuyor
			}

		}

		deneme++; // Sira diger oyuncuya geciyor

	}

	// Kazanani Duyurma
	if (*pOyuncu1Skor == 3) {
		cout << "\n Tebrikler " << oyuncu1 << ", Oyunu Kazandin!\n";
	}
	else if (*pOyuncu2Skor == 3) {
		cout << "\n Tebrikler " << oyuncu2 << ", Oyunu Kazandin!\n";

	}

	skorGoster(oyuncu1, oyuncu2, pOyuncu1Skor, pOyuncu2Skor);

	return 0;
}