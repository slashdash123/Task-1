/*
 * main.h
 *
 *  Created on: Mar 14, 2022
 *      Author: domen
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>


extern void vsota_cifer_id_um(int32_t stevilo);
extern void shranjevanje_st_polje(int32_t stevilo_n, int32_t stevilo_m);
extern void drugo_najvecje_stevilo(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e);
extern void ImaTriDelitelje(int32_t n);
extern bool prastevilo(int32_t n);
extern void zamik_elementov(int32_t a);
extern void pretvorba_ure(uint32_t mili_enota);
extern void izpis_binarno(int stevilo);
extern void sodo_liho(uint32_t stevilo);
extern void zlog_po_zlog(int32_t stevilo_32bit);
extern int16_t StevecBitov(int16_t stevilo);
extern void stetje_bitov(int16_t stevilo);
extern void binarni_palindrom(int16_t stevilo);
extern bool palindrom_funkcija(int16_t stevilo);


int16_t StevecBitov(int16_t stevilo)
{
    int16_t count = 0;
    while (stevilo)
    {
        count += stevilo & 1;
        stevilo >>= 1;
    }
    return count;
}


#endif /* MAIN_H_ */
