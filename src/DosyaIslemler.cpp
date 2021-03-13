/**
* @file BuseDemirbilek
* @description Dosyadan okunan her satýrdaki sayýlarýn dairesel çift baðlý listeye
  aktarýlmasý,istenenleri tamamlamasý,istenenleri listeye iþleyip ilgili þifrenin oluþturulmasý,
   ekrana basýlmasý
* @course 1.ogretim B grubu
* @assignment 1
* @date 16.08.2020
* @author Buse Nur Demirbilek
*/
#include<iostream>
#include"DosyaIslemler.h"
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string>

int DosyaIslemler::SatirSayisi()
{
    int sayac = 1;
    ifstream dosyaOku("src/Sayilar.txt");
    string satir = "";

    if (dosyaOku.is_open()) {

        while (getline(dosyaOku, satir)) {
            sayac++;
        }

        dosyaOku.close();
    }
    return sayac;
}

int DosyaIslemler::SayiyaDonustur(string sayi)
{
    int carpim = 1, sonuc = 0, temp;
    for (int i = sayi.length() - 1; i >= 0; i--)
    {
        temp = sayi[i] - 48;
        sonuc += temp * carpim;
        carpim = carpim * 10;
    }

    return sonuc;
}

void DosyaIslemler::Elemanlar(int satirSayisi, int elemanlar[], int elemanSayisi[])
{
    int sayac = 1, diziSayac = 0, boslukKonum = 0, sayiKonum = 0;
    int indexNo;
    bool dongu = true;
    ifstream dosyaOku("src/Sayilar.txt");
    string satir = "";
    int a;
    if (dosyaOku.is_open()) {

        while (getline(dosyaOku, satir)) {
            if (sayac == satirSayisi)
            {
                while (dongu)
                {
                    indexNo = satir.find(" ", boslukKonum);
                    elemanlar[diziSayac] = SayiyaDonustur(satir.substr(sayiKonum, indexNo - boslukKonum));
                    a = SayiyaDonustur(satir.substr(sayiKonum, indexNo - boslukKonum));
                    boslukKonum = indexNo + 1;
                    sayiKonum = indexNo + 1;
                    diziSayac++;
                    if (indexNo == -1)
                        dongu = false;
                }
            }
            sayac++;
        }

        dosyaOku.close();
        elemanSayisi[0] = diziSayac;
    }
}

void DosyaIslemler::SifreYazdir(int bagliListeDizisi[], int bagliListeUzunlugu)
{
    for (int i = 0; i < bagliListeUzunlugu; i++)
    {
        char temp;
        temp = char(bagliListeDizisi[i]);
        cout << temp;
    }
    cout << endl;
}
