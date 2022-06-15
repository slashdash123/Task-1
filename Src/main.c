/*
 * main.c
 *
 *  Created on: 7 Oct, 2021
 *      Author: domen
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "../inc/main.h"

int main()
{
	//vsota_cifer_id_um(55);

	//shranjevanje_st_polje(8,3);

	//drugo_najvecje_stevilo(-20,-100,-5,-300,-600);

	//ImaTriDelitelje(500);

	//zamik_elementov(4);

	//pretvorba_ure(50045);


	//***** 2. sklop *****

	//izpis_binarno(600);

	//sodo_liho(24);

	//zlog_po_zlog(32);

	//stetje_bitov(9);

	binarni_palindrom(9);

	return 0;
}


void vsota_cifer_id_um(int32_t stevilo)
{
	int32_t vsota=0;
	int32_t n;

	while(stevilo>0)
	{
		n=stevilo%10;
		vsota=vsota+n;
		stevilo=stevilo/10;
	}

	printf("Vsota je=%d\n",vsota);
}


void shranjevanje_st_polje(int32_t stevilo_n, int32_t stevilo_m)
{
	int32_t polje_izhod[stevilo_m];

	printf("Polje števil n=%d, ki so deljiva s m=%d je:\n", stevilo_n, stevilo_m);

	int32_t k = 1;
	int32_t novi_m = stevilo_m;

	for (int32_t i=0; i<stevilo_n; i++)
	{
		printf("%d ", polje_izhod[i]=novi_m*k);
		k++;
	}
}


void drugo_najvecje_stevilo(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e)
{
	int32_t polje[5]={a,b,c,d,e};

	int32_t najvecje_st;
	int32_t drugo_najvecje_st;

	if(polje[0] > polje[1])
		{
		najvecje_st = polje[0];
		drugo_najvecje_st  = polje[1];
		}
	else
		{
		najvecje_st = polje[1];
		drugo_najvecje_st  = polje[0];
		}

	for(int32_t i=2; i < 5; i++)
	{
	      if( najvecje_st < polje[i] )
	      {
	    	  drugo_najvecje_st = najvecje_st;
	    	  najvecje_st = polje[i];
	      }
	      else if( drugo_najvecje_st < polje[i] )
	      {
	    	  drugo_najvecje_st =  polje[i];
	      }
	}


	printf("Drugo največje število je: %d ", drugo_najvecje_st);
}


void ImaTriDelitelje(int32_t n)
{
	printf("Števila s tremi delitelji v intervalu od 1 do %d so: ", n);

	    for(int32_t i = 2; i * i <= n; i++)
	    {
	        // preveri prastevilo
	        if (prastevilo(i))
	        {
	            if (i * i <= n)
	            {
	            	//izpiši števila po vrstnem redu
	                printf("%d ", i * i );
	            }
	        }
	    }

}


bool prastevilo(int32_t n)
{
    for(int32_t i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
        	 return false;
        }
    }
    return true;
}


void zamik_elementov(int32_t n)
{
		int32_t polje[n];
		time_t t1;
		srand ((unsigned) time (&t1));

		//Izračun dolžine array-a
		int32_t dolzina = sizeof(polje)/sizeof(polje[n]);

		printf("Začetno polje z naključnimi vrednostmi: ");

		//Izpis orginalnega array-a in seed random števila
		for (int32_t i=0; i<dolzina; i++)
			{
				  polje[i]=rand()%10;
				  printf("%d ",polje[i]);
			}

		printf("\n");

		int32_t counter = 1;

		   //Zamik za n-krat v desno
		for(int32_t i = 0; i < n; i++)
		   {
			   int32_t j, zadnji;

			   printf("Polje po %d. koraku: ", counter);

			   //Shrani zadnji element array-a
			   zadnji = polje[dolzina-1];

			   for(j = dolzina-1; j > 0; j--)
					 {
						//Zamakni element array-a za eno mesto
						polje[j] = polje[j-1];
					 }

				//Zadnji element v array-u bo prestavljen na začetek arraya
				polje[0] = zadnji;
				counter++;

				for(int32_t i = 0; i< dolzina; i++)
					{
						printf("%d ", polje[i]);
					}

				printf("\n");
		  }
}


void pretvorba_ure(uint32_t mili_enota)
{
	//1 mili_unit enota predstavlja 100ms
	uint32_t milisekunde=0;
	uint32_t ure=0, minute=0, sekunde=0, milisekunde_ostanek=0;

	milisekunde = mili_enota * 100;

	ure = milisekunde / 3600000;
	milisekunde = milisekunde % 3600000;

	minute = milisekunde / 60000;
	milisekunde = milisekunde % 60000;

	sekunde = milisekunde / 1000;
	milisekunde = milisekunde % 1000;

	milisekunde_ostanek = milisekunde;

	printf("%02d h %02d m %02d s %03d ms \n", ure, minute, sekunde, milisekunde_ostanek);
}


void izpis_binarno(int stevilo)
{
    int j;

    for(int i = 31; i >= 0; i--)
    {
        j = stevilo >> i;

        if((i == 7) || (i == 15) || (i == 23))
        {
        	printf(" ");
        }
        if(j & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}


void sodo_liho(uint32_t stevilo)
{
		printf("Bitna operacija & - sodo/liho:\n");
		if(!(stevilo & 1))
		{
			printf("Število %d je sodo", stevilo);
		}
		else
		{
			printf("Število %d je liho", stevilo);
		}

		printf("\n\n");

		printf("Bitna operacija | - sodo/liho:\n");
		if((stevilo | 1) > stevilo)
		{
			printf("Število %d je sodo", stevilo);
		}
		else
		{
			printf("Število %d je liho", stevilo);
		}

		printf("\n\n");

		printf("Bitna operacija ^ - sodo/liho:\n");
		if((stevilo ^ 1) == (stevilo + 1))
		{
			printf("Število %d je sodo", stevilo);
		}
		else
		{
			printf("Število %d je liho", stevilo);
		}


		printf("\n\n");

		printf("Bitna operacija << >> - sodo/liho:\n");

		int temp = (stevilo >> 1) << 1;

		if(temp == stevilo)
		{
			printf("Število %d je sodo", stevilo);
		}
		else
		{
			printf("Število %d je liho", stevilo);
		}

		printf("\n\n");
}


void zlog_po_zlog(int32_t stevilo_32bit)
{
	int32_t stevilo_32bit_1 = 0, stevilo_32bit_2 = 0, stevilo_32bit_3 = 0, stevilo_32bit_4 = 0;

	//zadnjih 8 bitov iz 32 bitnega števila v novo potem pa v vsakem koraku 3x shiftamo za 8 v desno, dokler ne pridemo do 32
	stevilo_32bit_1 = stevilo_32bit;
	stevilo_32bit = stevilo_32bit >> 8;
	stevilo_32bit_2 = stevilo_32bit;
	stevilo_32bit = stevilo_32bit >> 8;
	stevilo_32bit_3 = stevilo_32bit;
	stevilo_32bit = stevilo_32bit >> 8;
	stevilo_32bit_4 = stevilo_32bit;
}


void stetje_bitov(int16_t stevilo)
{
	printf("%d", StevecBitov(stevilo));
}


void binarni_palindrom(int16_t stevilo)
{
		if (palindrom_funkcija(stevilo))
	 	{
	        printf("%d je palindrom", stevilo);
	    }
	    else
	    {
	        printf("%d ni palindrome", stevilo);
	    }
}


bool palindrom_funkcija(int16_t stevilo)
{
    // `rev` shrani obratno vrednost binarne reprezentacije "stevilo"
    int16_t rev = 0;

    // izvajaj dokler niso vsi biti "stevilo" procesirani
    int16_t k = stevilo;
    while (k)
    {
        // dodaj najbolj desni bit v "rev"
        rev = (rev << 1) | (k & 1);
        k = k >> 1;     // izpusti zadnji bitf
    }

    // vrne true če je "reverse(stevilo) enako kot "stevilo"
    return stevilo == rev;
}
