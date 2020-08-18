# TP máquinas de estado - Refrigeración de un automóvil

*Maquina de estado del sistema de refrigeración de un automóvil.*

## Memoria descriptiva

Mi sistema representa un control del funcionamiento de la refrigeración de un automóvil. Las variables que determinan el pasaje de un estado a otro son la __temperatura__ y __volumen__ del líquido refrigerante. 

- Temperatura: Es leída por un único sensor y determina el *ON/OFF* del electroventilador, con temperatura de encendido y de corte configurable. Mientras el sensor lea una temperatura menor a la temperatura de encendido, el electroventilador permanecerá *OFF*. Una vez que el líquido supere la temperatura de encendido, se activa la conexión a masa del electroventilador para que se encienda, y permanecerá *ON* mientras el líquido tenga una temperatura superior a la temperatura de corte. Una vez que el sensor lea una temperatura menor a la temperatura de corte, se cortará la conexión a masa, haciendo que el electroventilador vuelva al estado *OFF* y permanecerá en espera hasta que la temperatura vuelva a aumentar.

- Volumen: Es leído por un único sensor, con volumen mínimo y delta configurable. Mientras el líquido del depósito supere el volumen mínimo menos deltaV la máquina permanecerá en estado de espera. Cuando el sensor lea que el volumen se encuentra por debajo de ese valor se encenderá una luz de alerta para indicar que el depósito debe ser llenado. La luz permanecerá encendida mientras el volumen sea menor al volumen mínimo más deltaV. Una vez superado ese valor, la luz se apagará y la maquina volverá al estado de espera.



## Diagrama

![./recursos/Diagrama.png](https://github.com/Ana-Francioni/TP-maquinas-de-estado/blob/master/Recursos/Diagrama.png)