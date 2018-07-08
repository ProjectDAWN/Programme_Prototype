#include "Utils.h"

void Utils::fusion_sort(int tab[],int start,int stop,int taille) {
	int middle;
	if (start<stop) {
		middle=(start+stop)/2;
		fusion_sort(tab,start,middle,taille);
		fusion_sort(tab,middle+1,stop,taille);
		fusion(tab,start,stop,middle,taille);
	}
}

void Utils::fusion(int tab[],int start,int stop,int middle, int taille) {
	int old_tab[taille];
	for (int i = 0 ; i<taille; i++) {
		old_tab[i]=tab[i];
	}
	int i1 = start;
	int i2 = middle + 1;
	int i = start;
	while (i1 <= middle && i2 <= stop)
	{
		if(old_tab[i1] <= old_tab[i2])
		{
			tab[i] = old_tab[i1];
			i1++;
		}
		else
		{
			tab[i] = old_tab[i2];
			i2++;
		}
		i++;
	}
	if (i <= stop)
	{
		while(i1 <= middle)
		{
			tab[i] = old_tab[i1];
			i1++;
			i++;
		}
		while(i2 <= stop)
		{
			tab[i] = old_tab[i2];
			i2++;
			i++;
		}
	}
}

