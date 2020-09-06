#include <stdio.h>

typedef enum {
    espera,
    encendido

} est_t;

typedef struct {
    unsigned char vol_a;
    unsigned char v_set;
    unsigned char dv;

} volumen_t;

typedef struct {
    unsigned char temp_a;
    unsigned char t_set_on;
    unsigned char t_set_off;
} temperatura_t;

typedef struct 
{
   temperatura_t temperatura;
   volumen_t volumen;
} configuracion_t;

configuracion_t inicio (void); // lee el archivo de configuación e inicializa las variables
est_t f_espera_l (volumen_t v, unsigned char *p); //apaga la luz de alerta y vuelve a leer el volumen del depósito para devolver el estado correspondiente.
est_t f_encender_l (volumen_t v, unsigned char *p); //enciende la luz de alerta y vuelve a leer el volumen del depósito para devolver el estado correspondiente.
est_t f_espera_e (temperatura_t t, unsigned char *p); //apaga el electroventilador y vuelve a leer el la temperatura para devolver el estado correspondiente.
est_t f_encender_e (temperatura_t t, unsigned char *p); //enciende el electroventilador y vuelve a leer el la temperatura para devolver el estado correspondiente.
void emulacion (unsigned char l, unsigned char e); //imprime en pantalla si la luz y el electro estan encendidos o apagados