#ifndef utils_h
#define utils_h

#include <Arduino.h>

class Utils {
	
	public:
	
	static void fusion_sort(int tab[],int start,int stop,int taille);
	static void fusion(int tab[],int start,int stop,int middle,int taille);
	
};

#endif
