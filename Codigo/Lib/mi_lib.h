#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    
    espera = 0,
    encendido = 1

} est_t;

typedef struct {
    float vol_a;
    int v_set;
    float  dv;

} volumen_t;

typedef struct {
    int temp_a;
    int t_set_on;
    int t_set_off;
} temperatura_t;

typedef struct 
{
   temperatura_t temperatura;
   volumen_t volumen;
} configuracion_t;

configuracion_t inicio (void); // lee el archivo de configuación e inicializa las variables
char* obt_clave (char *clave); //modifica la cadena key para que solo contenga la clave y devuelve el puntero posicionado en donde se encuentra el valor.
est_t f_espera_l (volumen_t v, unsigned char *p); //apaga la luz de alerta y vuelve a leer el volumen del depósito para devolver el estado correspondiente.
est_t f_encender_l (volumen_t v, unsigned char *p); //enciende la luz de alerta y vuelve a leer el volumen del depósito para devolver el estado correspondiente.
est_t f_espera_e (temperatura_t t, unsigned char *p); //apaga el electroventilador y vuelve a leer el la temperatura para devolver el estado correspondiente.
est_t f_encender_e (temperatura_t t, unsigned char *p); //enciende el electroventilador y vuelve a leer el la temperatura para devolver el estado correspondiente.
