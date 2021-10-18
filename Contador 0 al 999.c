 //Delcaracion de Funciones
void main (void); //Funcion Principal
void config (void); //Funcion de Configuaracion de Puertos.
 //Declaracion de Variables Globales
short unidades[10]  = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67}; //ESTOS SON LOS VALORES DE 0-9 EN EL DISPLAY
short decenas[10]  = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67};
short centenas[10]  = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67};
int a=0;
int b=0;
int c_1=0;
int suma = 0;
void main() {
     config();
     while (1){

        for (c_1=0;c_1<10;c_1++){       //USAMOS UNA CASCADA DE CICLOS FOR
           for (b=0;b<10;b++){          //UN CICLO PARA LAS UNIDADES, OTRO PARA DECENAS
               for (a=0;a<10;a++){      //Y OTRO PARA LAS CENTENAS
                   for (suma=0;suma<1;suma++){        //ESTE FOR ES PARA EL TIEMPO AL QUE VA IR CONTANDO.
                      PORTB = unidades[a];
                      PORTD = 1;
                      delay_ms(7);
                      PORTB = decenas[b];
                      PORTD = 2;
                      delay_ms(7);
                      PORTB = centenas[c_1];
                      PORTD = 4;
                      delay_ms(7);}
               }
            }
        }
     }
}
             
                     
 void config(){
     TRISB = 0X00;
     TRISD = 0X00;
     PORTB = 0X00;
     PORTD = 0X00;
}