#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include<locale.h>

using namespace std;
struct kelime {
	string kelime;
	int kackere = 1;
};
struct dugum {
	kelime veri;
	dugum* sonraki;
	dugum* onceki;
};
class list {
public:
	dugum* bas, * son;
	list()
	{
		bas = NULL;
		son = NULL;
	}
};

list liste = list();
void listele() {
	struct dugum* ptr;
	ptr = liste.bas;
	if (liste.bas == NULL)
	{
		cout << "Liste boş."<<endl;
	}
	else{
		cout << "Elemanlar: " << endl;
		while (ptr != NULL)
		{
			cout << ptr->veri.kelime << " " << ptr->veri.kackere << endl;
			ptr = ptr->sonraki;
		}
		cout << endl;
	}
	
}

int elemansayisi_bulma()
{
	struct dugum* ptr;
	ptr = liste.bas;
	int sayac = 0;
	while (ptr != NULL)
	{
		ptr = ptr->sonraki;
		sayac++;
	}
	return sayac;
}



bool bos_mu(dugum* bas)
{
	if (bas == NULL)
		return true;
	else
		return false;
}
int ara(string aranan) {
	int uzunluk = aranan.length();

	if (bos_mu(liste.bas) == true)
	{
		return -1;
	}
	else
	{
		dugum* bu = liste.bas;
		int sayac = 1;
		while (bu != NULL)
		{
			if (memcmp(bu->veri.kelime.data(), aranan.data(), uzunluk) == 0)
			{
				return sayac;
			}
			bu = bu->sonraki;
			sayac = sayac + 1;
		}
		return -1;
	}
}
bool kackere(string kelime)
{
	int var;
	dugum* gecici = new dugum;
	gecici = liste.bas;
	var = ara(kelime);
	if (var != -1) {
		for (int i = 1; i < var; i++)
		{
			gecici = gecici->sonraki;
		}
		gecici->veri.kackere++;
	}
	else {
		return -1;
	}
}
void son_guncelle() {
	dugum* ptr;
	ptr = liste.bas;
	while (ptr != NULL) {
		liste.son = ptr->sonraki;
	}
}

void basa_ekle(string kelime)
{
	dugum* gecici = new dugum;
	gecici->veri.kelime = kelime;
	if (liste.bas == NULL) {
		gecici->sonraki = gecici->onceki = NULL;
		liste.bas = gecici;
		liste.son = gecici;
	}
	else {

		gecici->sonraki = liste.bas;
		gecici->onceki = NULL;
		liste.bas->onceki = gecici;
		liste.bas = gecici;
	}

}
void sona_ekle(string str) {
	if (kackere(str) == -1) {
		dugum* gecici = new dugum;
		gecici->veri.kelime = str;
		gecici->sonraki = NULL;
		gecici->onceki = liste.son;
		liste.son->sonraki = gecici;
		liste.son = gecici;
	}
	
}
void bas_sil()
{
	if (bos_mu(liste.bas) == true)
	{
		cout << "liste bos" << endl;
	}
	else {
		dugum* gecici = new dugum;
		gecici = liste.bas;
		liste.bas = liste.bas->sonraki;
		liste.bas->onceki = NULL;
		delete gecici;
	}
}
int sil(int pos)
{
	dugum* gecici = new dugum;
	gecici = liste.bas;

	if (bos_mu(liste.bas) == true) {
		cout << "liste bos" << endl;
		return -1;
	}
	else {
		dugum* ptr;
		ptr = liste.bas;
		int a = elemansayisi_bulma();
		if (pos == a)
		{
			dugum* ptr;
			ptr = liste.son;
			liste.son = ptr->onceki;
			liste.son->sonraki = NULL;
			delete ptr;

		}
		else {
				dugum* gecici = new dugum;
				gecici = liste.bas;
				for (int i = 1; i < pos; i++)
				{
					gecici = gecici->sonraki;
				}
				gecici->onceki->sonraki = gecici->sonraki;
				gecici->sonraki->onceki = gecici->onceki;
				delete gecici;
		}
	}
}



void kelime_degistirme(int pos, string q) {
	dugum* gecici=new dugum;
	gecici = liste.bas;
	for (int i = 1; i < pos; i++)
	{
		gecici = gecici->sonraki;
	}

	gecici->veri.kelime = q;

}




		void kackez_sırala() {
			struct dugum* ptr;
			int temp;
			ptr = liste.bas;
			int a;
				a = elemansayisi_bulma();
				while (ptr->sonraki!=NULL)
				{
					for (int i = 0; i < a; i++) {
						for (int j = 0; j < a; j++)
						{
							

							if (ptr->sonraki != NULL)
							{
								if (int(ptr->veri.kackere) < (ptr->sonraki->veri.kackere)) {
									temp = ptr->veri.kackere;
									ptr->veri.kackere = ptr->sonraki->veri.kackere;
									ptr->sonraki->veri.kackere = temp;
									string(temp) = ptr->veri.kelime;
									ptr->veri.kelime = ptr->sonraki->veri.kelime;
									ptr->sonraki->veri.kelime = string(temp);
								}

								else {
									ptr = ptr->sonraki;
								}
							}

						}
					}
				}
		}
	    void alfabetik_sırala() {
			struct dugum* ptr;
			struct dugum* ptr2;
			int temp;
			ptr = liste.bas;
			ptr2 = liste.bas;
			int a;
			a = elemansayisi_bulma();
			while (ptr->sonraki != NULL)
			{
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < a; j++)
					{


						if (ptr->sonraki != NULL)
						{
							if ((ptr->veri.kelime) > (ptr->sonraki->veri.kelime)) {
								temp = ptr->veri.kackere;
								ptr->veri.kackere = ptr->sonraki->veri.kackere;
								ptr->sonraki->veri.kackere = temp;
								string(temp) = ptr->veri.kelime;
								ptr->veri.kelime = ptr->sonraki->veri.kelime;
								ptr->sonraki->veri.kelime = string(temp);
							}

							else {
								ptr = ptr->sonraki;
							}
						}

					}
				}
			}
		}

		
int main()
{
	setlocale(LC_ALL, "Turkish");
	string harf;
	string str;
	cout << "metin girin: ";
	getline(cin, harf);
	int sayac = 1;
	for (int i = 0; i <= harf.length(); i++)
	{
		if (harf[i] != ' ') {
			str = str + harf[i];
		}
		if (harf[i] == ' ')
		{
			sayac++;
			if (sayac == 1) {
				basa_ekle(str);
				str = "";
			}
			else {
				basa_ekle(str);
				str = "";

			}
		}
		if (harf[i] == NULL)
		{
			sona_ekle(str);
		}
		
	}
	listele();
	int secim;
	string aranan;
	string yeniKelime;
	string silinecek_kelime;
	int sayac3 = 0;
	int pos=0;

	while (true)
	{
		int a = elemansayisi_bulma();
		cout << "Kelime sayısı: " << a << endl;
		cout << "Alfabetik sıralamak için: 1 tuşuna basınız." << endl << "Tekrar sırasına göre sıralamak için: 2 tuşuna basınız." << endl << "Kelime değiştirmek için: 3'i seçiniz." << endl << "kelime silmek için: 4'yi seçiniz." << endl << "Çıkış yapmak için 5'i seçiniz." << endl << "listelemek için 6'yı seçiniz." << endl << "Kelime aramak için 7'yi seçin." << endl;
		cin >> secim;
		if (secim == 3) {
			cout << "Değiştirmek istediğiniz kelimeyi girin: ";
			cin >> aranan;
			sayac3 = ara(aranan);
			cout << endl << "Yeni kelimeyi Girin: ";
			cin >> yeniKelime;
			cout << endl;
			
			if (sayac3 == -1)
			{
				cout << "aradığınız kelime bulunamadı." << endl;
			}
			else {
				kelime_degistirme(sayac3, yeniKelime);
				listele();
			}
		}
		if (secim == 4) {
			cout << "Silmek istediğiniz kelimeyi Girin: ";
			cin >> silinecek_kelime;
			cout << endl;
			pos=ara(silinecek_kelime);

			if (pos == -1)
			{
				cout << "Silmek istediğiniz kelime yok."<<endl;
			}
			if (pos == 1) {
				bas_sil();
				listele();
			}
			else {
				sil(pos);
				listele();
			}
		}
		if (secim == 5)
		{
			break;
		}
		if (secim == 6) {
			listele();

		}
		if (secim == 1)
		{
			for (int i = 0; i < a; i++) {
				alfabetik_sırala();
			}
			listele();
		}
		if (secim == 7) {
			string aranan1;
			int b;
			cout << "aranan kelimeyi girin: ";
			cin >> aranan1;
			b=ara(aranan1);
			if (b == a) {
				cout << a << ". eleman."<<endl;
			}
			else {
				cout << a - b << ". eleman."<<endl;
			}
			
		}
		if (secim == 2) {
			for (int i = 0; i < a; i++) {
				kackez_sırala();
			}
			listele();
		}
	
	}
}


