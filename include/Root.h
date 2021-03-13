#ifndef ROOT_H
#define ROOT_H
#include<iostream>

using namespace std;
typedef struct n {
	int veri;
	struct n* ileri;
	struct n* once;
	int obebSayac;
}dugum;

class Root{
	public:				
		dugum* durum(dugum* r, int veri);
		dugum* durum2(dugum* r, int veri);
		void listele(dugum* r, int[], int[]);
		int ebebBul(dugum* r, int veri);
		dugum* anaOlaylarVeriEkle(dugum* r, int veri);
	};



#endif /* ROOT */
