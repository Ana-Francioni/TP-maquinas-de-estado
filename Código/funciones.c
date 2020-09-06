#include "../Código/mi_lib.h"

configuracion_t inicio (void){ 

    /*
        codigo
    */
} // lee el archivo de configuación e inicializa las variables

est_t f_espera_l (volumen_t v, unsigned char *p){
    est_t estado;
    *p = 0;
    printf ("Ingrese volumen del deposito: \t\n");
    fflush (stdin);
    scanf ("%d", &v.vol_a);

    if (v.vol_a >= (v.v_set-v.dv)){
        estado = espera;
    }else
    {
        estado = encendido;
    }
    return estado;    


} //apaga la luz de alerta y vuelve a leer el volumen del depósito para devolver el estado correspondiente.

est_t f_encender_l (volumen_t v, unsigned char *p){
    est_t estado;
    *p = 1;
    printf ("Ingrese volumen del deposito: \t\n");
    fflush (stdin);
    scanf ("%d", &v.vol_a);

    if (v.vol_a >= (v.v_set + v.dv)){
        estado = espera;
    }
    else
    {
        estado = encendido;
    }
    return estado;

} //enciende la luz de alerta y vuelve a leer el volumen del depósito para devolver el estado correspondiente.

est_t f_espera_e (temperatura_t t, unsigned char *p){
    est_t estado;
    *p = 0;
    printf ("Ingrese la temperatura del liquido: \t\n");
    fflush (stdin);
    scanf ("%d", t.temp_a)
    if (t.temp_a < t.t_set_on){
        estado = espera;
    }    
    else{
        estado = encendido;
    }
    return estado;

} //apaga el electroventilador y vuelve a leer el la temperatura para devolver el estado correspondiente.

est_t f_encender_e (temperatura_t t, unsigned char *p){
    est_t estado;
    *p = 1;
    printf ("Ingrese la temperatura del liquido: \t\n");
    fflush (stdin);
    scanf ("%d", t.temp_a)
    if (t.temp_a < t.t_set_off){
        estado = espera;
    }    
    else{
        estado = encendido;
    }
    return estado;
} //enciende el electroventilador y vuelve a leer el la temperatura para devolver el estado correspondiente.

void emulacion (unsigned char l, unsigned char e){
    if (l)
        printf ("Luz alerta encendida\n");
    else
        printf ("Luz alerta apagada");
    
     if (e)
        printf ("Electroventilador encendido\n");
    else
        printf ("Electroventilador apagado");
} //imprime en pantalla si la luz y el electro estan encendidos o apagados