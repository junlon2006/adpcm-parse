/* 
 * adpcm.h - include file for adpcm coder. 
 * 
 * Version 1.0, 7-Jul-92. 
 **/ 

#ifndef _SRC_SERVICE_UNI_ADPCM_H_
#define _SRC_SERVICE_UNI_ADPCM_H_

typedef struct adpcm_state {
    short valprev;        /* Previous output value */
    char index;          /* Index into stepsize table */
} adpcm_state_t;

/*len unit is bytes*/
void adpcm_coder (short indata[], char outdata[], int len,  adpcm_state_t *state);
void adpcm_decoder(char indata[], short outdata[], int len, adpcm_state_t *state);

#endif  //_SRC_SERVICE_UNI_ADPCM_H_



