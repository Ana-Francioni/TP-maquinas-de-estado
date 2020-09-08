#include "../Lib/mi_lib.h"

configuracion_t inicio (void){ 
    configuracion_t v;
    FILE *cfp;
    char cad[40], *clave, *val, i;
    char variables[4][20] = {"t_set_on", "t_set_off", "v_set", "dv"};
    if ((cfp = fopen("../Conf/conf.conf", "rb")) == NULL){
        printf ("Error. No se encuentra el archivo.\n");
    }
    fgets (cad, 40, cfp);
    while (!feof(cfp)){
        clave = cad;
        if ((*clave)!= '#' && strlen(clave) > 0){
            val = obt_clave(clave);
            for (i=0; i<4; i++){
                if (!strcmp(clave, variables[i])){
                    switch (i){
                        case 0:
                            v.temperatura.t_set_on = atoi (val);
                            break;
                        case 1:
                            v.temperatura.t_set_off = atoi (val);
                            break;
                        case 2:
                            v.volumen.v_set = atoi (val);
                            break;
                        case 3:
                            v.volumen.dv = atof (val);
                            break;

                    }
                }
            }
        }
        fgets (cad, 40, cfp);
    }
    printf ("El limite máximo de temperatura del motor para comenzar a enfriar es de: %d \n", v.temperatura.t_set_on);
    printf ("El limite mínimo de temperatura del motor para dejar de enfriar es de: %d \n", v.temperatura.t_set_off);
    printf ("El limite mínimo de la cantidad de líquido en el deposito es de: %d L \n", v.temperatura.t_set_on);
    printf ("El delta de volumen es de %f L \n", v.volumen.dv);
    fclose (cfp);
   return v; 
} // lee el archivo de configuación e inicializa las variables

char* obt_clave (char *clave){
    char i = 0;
    while (*(clave+i) != ' '){
        i++;
    }
    *(clave + i) = 0;
    return clave+i+1;
} //modifica la cadena key para que solo contenga la clave y devuelve el puntero posicionado en donde se encuentra el valor.


est_t f_espera_l (volumen_t v, unsigned char *p){
    unsigned char a;
    est_t estado;
    *p = 0;
    printf ("Luz alerta apagada\n");
    printf ("Ingrese volumen del deposito: \t");
    fflush (stdin);
    scanf ("%f", &v.vol_a);
    printf ("\n");
    if ((float)v.vol_a > ((float)v.v_set - v.dv)){
        estado = espera;
    }
    else
    {
        estado = encendido;
        
    }
     return estado;   


} //apaga la luz de alerta y vuelve a leer el volumen del depósito para devolver el estado correspondiente.

est_t f_encender_l (volumen_t v, unsigned char *p){
    est_t estado;
    *p = 1;
    printf ("Luz alerta encendida\n");
    printf ("Ingrese volumen del deposito: \t");
    fflush (stdin);
    scanf ("%f", &v.vol_a);
    printf ("\n");
    if ((float)v.vol_a >= ((float)v.v_set + v.dv)){
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
    printf ("Electroventilador apagado\n");
    printf ("Ingrese la temperatura del liquido: \t");
    fflush (stdin);
    scanf ("%d", &t.temp_a);
    printf ("\n");
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
    printf ("Enfriando liquido \n");
    printf ("Ingrese la temperatura del liquido: \t");
    fflush (stdin);
    scanf ("%d", &t.temp_a);
    printf ("\n");
    if (t.temp_a <= t.t_set_off){
        estado = espera;
    }    
    else{
        estado = encendido;
    }
    return estado;
} //enciende el electroventilador y vuelve a leer el la temperatura para devolver el estado correspondiente.


