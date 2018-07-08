#ifndef Time_h
#define Time_h

#include <Arduino.h>

class Time {
	
	public: /* On défini ces méthodes public */

	Time(int hour, int minute);	
	int get_hour(); /* Renvoi la valeur de l'heure */
	int get_minute(); /* Renvoi la valeur des minutes */
	void set_hour(int hour); /* Modifie la valeur de l'heure*/
	void set_minute(int minute); /*Modifie la valeur des minutes */
	bool is_equal(int hour,int minute); /* Permet de savoir si on équalité entre les objets */
	bool is_inf_equal(int hour, int minute); /* Permet de savoir si notre objet est plus petit */
	bool is_sup_equal(int hour,int minute); /* Permet de savoir si notre objet est plus grand */
	bool is_inf(int hour, int minute); /* Permet de savoir si notre objet est plus petit */
	bool is_sup(int hour,int minute); /* Permet de savoir si notre objet est plus grand */
	void add_hour(int hour); /*Permet d'ajouter des heures */
	void add_minute(int minute); /*Permet d'ajoutr des minutes */
	~Time();
	
	private:
	
	int m_hour;
	int m_minute;
};

#endif