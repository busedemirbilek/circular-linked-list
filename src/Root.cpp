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
#include "Root.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <fstream>
#include<string>
#include <cstdlib>

void Root::listele(dugum* r, int bagliListeDizisi[], int bagliListeUzunlugu[]) {
	int sayac = 0;
	while (r != NULL) 
	{
		bagliListeDizisi[sayac] = r->veri;
		sayac++;
		r = r->ileri;
	}
	bagliListeUzunlugu[0] = sayac;
}

int Root::ebebBul(dugum* r, int veri) {
	int kucukSayi, buyukSayi, i, ebob = 1, modSonuc;
	
	if (r->veri > veri) {
		kucukSayi = veri;
	}
	else {
		kucukSayi = (r->veri);
	}

	for (i = 1; i < kucukSayi + 1; i++) {

		if (((r->veri) % i == 0) && ((veri % i) == 0)) {
			//r->obebSayac = i;
			ebob = i;
		}
	}
	return ebob;
}

dugum* Root::durum(dugum* r, int veri) {
	int kucukSayi, i, ebob, modSonuc;

	modSonuc = (r->veri) % veri;

	if (modSonuc == 0) {	// mod 0 ise saða bir düðüm ekle


		dugum* temp = (dugum*)malloc(sizeof(dugum));
		temp->ileri = r->ileri;
		temp->once = r;
		r->ileri = temp;
		//r->once=NULL;

		if (temp->ileri != NULL) {
			temp->ileri->once = temp;
		}
		temp->veri = veri;
		temp->obebSayac = ebebBul(r, veri);//ebob;

		return r;

	}
	else { // else durumuna girildiðinde listenin sol tarafýna ekleme yapýlmakta

		if (r->once == NULL) { //  liste baþý ise baþa düðüm ekle

			dugum* temp = (dugum*)malloc(sizeof(dugum));
			temp->veri = veri;
			temp->ileri = r;
			temp->obebSayac = ebebBul(r, veri);//ebob;
			r->once = temp;
			temp->once = NULL;

			return temp;
		}

		dugum* iter = r;

		i = 1;
		while (iter->once != NULL && i <= modSonuc) { // mod 0 dan farklý ise mod kadar ilerle düðüm ekle
			iter = iter->once;
			i = i + 1;
		}
		while (iter->ileri != NULL && iter->veri < veri && r->obebSayac > ebebBul(iter, veri)) {
			iter = iter->ileri;

		}

		modSonuc = veri % iter->veri;
		if (modSonuc == 0) {
			dugum* temp = (dugum*)malloc(sizeof(dugum));
			temp->obebSayac = ebebBul(iter, veri);//ebob;
			temp->veri = veri;
			temp->once = iter;
			iter->ileri = temp;
			temp->ileri->once = temp;
			iter->ileri->ileri = temp->ileri;

			while (iter->once != NULL && iter->obebSayac > r->obebSayac) {
				iter = iter->once;
			}
			r = iter;
			return r;

			//return temp;
		}
		else {
			i = 1;
			while (iter->once != NULL && i <= modSonuc) {
				iter = iter->once;
				i = i + 1;
			}
			if (iter->once == NULL) {
				dugum* temp = (dugum*)malloc(sizeof(dugum));
				temp->ileri = iter;
				iter->once = temp;
				temp->obebSayac = ebebBul(r, veri);//ebob;
				temp->veri = veri;
				while (iter->ileri != NULL && r->obebSayac < iter->obebSayac) {
					iter = iter->ileri;
				}
				r = iter;
				return r;
				//return temp;
			}
			dugum* temp = (dugum*)malloc(sizeof(dugum));
			iter->ileri = temp;
			temp->once = iter;
			temp->obebSayac = ebebBul(r, veri);//ebob;
			temp->veri = veri;

			while (iter->once != NULL && r->obebSayac > iter->obebSayac) {
				iter = iter->once;
			}
			r = iter;
			return r;
			//return temp;

		}
	}
}

dugum* Root::durum2(dugum* r, int veri) {

	//printf("r->obebSayac: %d\n",r->obebSayac);
	int kucukSayi, i, ebob, modSonuc;
	dugum* iter = r;
	while (iter->ileri != NULL && iter->veri < veri && r->obebSayac > ebebBul(iter, veri)) {
		iter = iter->ileri;
	}

	modSonuc = (veri) % (iter->veri);
	if (modSonuc == 0) {
		dugum* temp = (dugum*)malloc(sizeof(dugum));
		//printf("r->veri: %d, ebob: %d\n",r->veri,ebob);
		temp->ileri = r->ileri;
		temp->veri = veri;
		temp->once = r;
		r->ileri = temp;
		temp->obebSayac = ebebBul(r, veri);// ebob;
		if (temp->ileri != NULL && temp->once != NULL) {
			temp->ileri->once = temp;
			temp->once->ileri = temp;
		}

		return temp;
	}
	else {
		i = 1;
		while (iter->once != NULL && i <= modSonuc) {
			iter = iter->once;
			if (iter->obebSayac > r->obebSayac) {
				r = iter;
				//dugum *iter=r;				
			}
			i = i + 1;
		}
		//	printf("r->obebSayac: %d, iter->obebSayac: %d\n",r->obebSayac,iter->obebSayac);
		if (iter->once == NULL) {
			dugum* temp = (dugum*)malloc(sizeof(dugum));
			temp->ileri = iter;
			iter->once = temp;
			temp->once = NULL;
			temp->obebSayac = ebebBul(r, veri);//ebob;
			temp->veri = veri;

			return temp;


		}
		dugum* temp = (dugum*)malloc(sizeof(dugum));

		temp->ileri = iter->ileri;
		iter->ileri = temp;
		temp->once = iter;
		temp->obebSayac = ebebBul(r, veri);//ebob;
		temp->veri = veri;

		if (temp->ileri != NULL) {
			temp->ileri->once = temp;

		}

		return r;
	}
}

dugum* Root::anaOlaylarVeriEkle(dugum* r, int veri) {
	int kucukSayi, buyukSayi, i, ebob, modSonuc;

	if (r == NULL) {
		r = (dugum*)malloc(sizeof(dugum));
		r->ileri = NULL;
		r->once = NULL;
		r->obebSayac = 0;
		ebob = r->obebSayac;
		r->veri = veri;
		return r;
	}

	if (r->veri >= veri)
	{
		if (ebebBul(r, veri) >= r->obebSayac) {
		return 	durum(r, veri);
		}
		else {
		return	durum2(r, veri);
		}
		//return r;
	}
	else {
		if (ebebBul(r, veri) >= r->obebSayac) {
			return durum(r, veri);
		}
		else {
		return	durum2(r, veri);
		}
		//return r;
	}
}
