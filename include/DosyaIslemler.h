#ifndef DOSYAISLERMLER_H
#define DOSYAISLERMLER_H
#include<iostream>

using namespace std;

class  DosyaIslemler{
	public:
		int SatirSayisi();
		int SayiyaDonustur(string);
		void Elemanlar(int, int[], int[]);
		void SifreYazdir(int[], int);
	
};



#endif /* DOSYAISLERMLER */
