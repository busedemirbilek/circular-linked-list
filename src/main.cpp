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
#include <fstream>
#include<iostream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include"DosyaIslemler.h"
#include"Root.h"

using namespace std;

int main()
{
    DosyaIslemler dosyaIslem;
    Root anaOlaylar;
    int elemanlar[200], elemanSayisi[1];
    

    for (int i = 0; i < dosyaIslem.SatirSayisi() - 1; i++)
    {
        dugum* root;
        root = NULL;
        int bagliListeDizisi[200], bagliListeUzunlugu[1];
        dosyaIslem.Elemanlar(i + 1, elemanlar, elemanSayisi);
        root = anaOlaylar.anaOlaylarVeriEkle(root, elemanlar[0]);

        for (int j = 0; j < elemanSayisi[0] - 1; j++)
        {
           root = anaOlaylar.anaOlaylarVeriEkle(root, elemanlar[j + 1]);
        }
        anaOlaylar.listele(root, bagliListeDizisi, bagliListeUzunlugu);
        dosyaIslem.SifreYazdir(bagliListeDizisi, bagliListeUzunlugu[0]);
    }
    system("pause");
    return 0;
}

