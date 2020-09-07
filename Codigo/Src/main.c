#include "../Src/funciones.c"

int main (){
    est_t estadoE = espera, estadoL = espera;
    configuracion_t variables;
    unsigned char luz=0, electrovent=0;

    variables = inicio ();

    est_t (*pl []) (volumen_t, unsigned char*) = {f_espera_l, f_encender_l};
    est_t (*pe []) (temperatura_t, unsigned char*) = {f_espera_e, f_encender_e};

    while (1){
        estadoL = (*pl [estadoL]) (variables.volumen, &luz);   
        estadoE = (*pe [estadoE]) (variables.temperatura, &electrovent);        
    }
    return 0;
}
