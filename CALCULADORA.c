/*         ************************
           *   Autor: Saul Lopez  *
           *   Calculadora        *
           ************************   */
//Copyrigth © Saul Lopez//
//Declaraciones de Funciones
void main();   //
void config();
int teclado();
//Incializacion de LCD
sbit LCD_RS at RB1_BIT;
sbit LCD_EN at RB2_BIT;
sbit LCD_D4 at RB4_BIT;
sbit LCD_D5 at RB5_BIT;
sbit LCD_D6 at RB6_BIT;
sbit LCD_D7 at RB7_BIT;

sbit LCD_RS_Direction at TRISB1_BIT;
sbit LCD_EN_Direction at TRISB2_BIT;
sbit LCD_D4_Direction at TRISB4_BIT;
sbit LCD_D5_Direction at TRISB5_BIT;
sbit LCD_D6_Direction at TRISB6_BIT;
sbit LCD_D7_Direction at TRISB7_BIT;

//Variable
int a[5]={0,0,0,0,0};     //Primer numero 5 digitos en vectores
int b[5]={0,0,0,0,0};     //Segundo numero 5 digitos en vectores
int AT;       //        La suma de todos los vectores del primer numero
int BT;       // Las suma de todos los vectores del segundo numero
char ta[7];     //VARIABLE CARACTER PARA REPRESENTAR EL PRIMER NUMERO
char tb[7];     //VARIABLE CARACTER PARA REPRESENTAR EL SEGUNDO NUMERO
int sr = 0;      // Variable para el contador For
int rs = 0;      //Variable para almacenar que operacion solicito
int i=0;         //Variable que lleva la cuenta de cuantos digitos es el numero
int tec = 0;      //Variable que almacena los valores retornados por el teclado de 4X4
int OP = 0;       //Variable del resultado
char to[7];       //Variable del resultado tipo char para poder mostrar el valor en la LCD


void main() {     //Inicia funcion Principal
LCD_Init();       //Inicia la configuracion de la LCD
config();         //Llama a la configuracion de los puertos
encendido:        // Etiqueta que es donde inicia todo en 0
Lcd_Cmd(_LCD_CLEAR); //Limpiamos la LCD
tec = teclado();     //La Variable TEC es igual a la funcion teclado que otorga un valor del teclado
if (tec = 30){      //Solo si apacha el boton encendido entra en funcionamiento de la calculadora
while(1){            //Ciclo o bucle infinito
inicio:              //Etiqueta incio
AT = 0;             //Iniciacion de todo los valores a 0
BT = 0;
a[0] = 0;
a[1] = 0;
a[2] = 0;
a[3] = 0;
a[4] = 0;
b[0] = 0;
b[1] = 0;
b[2] = 0;
b[3] = 0;
b[4] = 0;         //Finalizacion de todo los valores a 0
                        //Copyrigth © Saul Lopez//

         i = 0;    //Variable para contar digitos a 0
         for(sr = 0; sr<5;sr++){  //Inicio del primer contador For.
         tec = teclado();   //La Variable TEC es igual a la funcion teclado que otorga un valor del teclado
         delay_ms(250);     //Retardo de 250ms
         if ( tec <19){     //Solo si apacho un valor numerico menor a 19 entra en este if
            i++;            //Variable Digito +1

                if ( i == 1){ //Si i es igual a 1 almacena el valor de tec en el primer vector
                a[0] = tec;
                PORTC = a[0];
                }
                if ( i  == 2){  //Si i es igual a 2 corre el valor del primer vector al 3 y el valor de tec lo almacena en el vector 2
                a[1] = a[0];
                a[0] = tec;
                }
                if (i == 3){    //Si i es igual a 3 se corren los vectores en su respectivo lugar
                a[2] = a[1];
                a[1] = a[0];
                a[0] = tec;
                }
                if ( i == 4){   //Si i es igual a 4 se corren los vectores en su respectivo lugar
                a[3] = a[2];
                a[2] = a[1];
                a[1] = a[0];
                a[0] = tec;
                }
                if (i == 5){    //Si i es igual a 5 se corren los vectores en su respectivo lugar
                a[4] = a[3];
                a[3] = a[2];
                a[2] = a[1];
                a[1] = a[0];
                a[0] = tec;
                }
              AT = ((a[0]*1)+(a[1]*10)+(a[2]*100)+(a[3]*1000)+(a[4]*10000));   //La suma total de los vectores de pendiendo del lugar almacenado
              IntToStr(AT , ta); //El vlaor total del primer digito los conertimos a una variable String para poder mostrarla en la LCD
              Lcd_Out(1,1,TA);   //Se muestra la variable en LCD

            } //Fin si el tec es menor a 19
         else {  //Si no es menor a 19...
          rs = tec;      //Almacenamos el valor de tec en rs
          if (rs ==19){Lcd_Out(1,8,"+");}   //Si rs es igual 19 se ejecutara una suma y en la LCD sale el signo mas
          if (rs ==20){Lcd_Out(1,8,"-");}   //Si rs es igual 20 se ejecutara una resta y en la LCD sale el signo menos
          if (rs ==21){Lcd_Out(1,8,"*");}   //Si rs es igual 21 se ejecutara una multiplicacion y en la LCD sale el signo de multiplicar
          if (rs ==22){Lcd_Out(1,8,"/");}   //Si rs es igual 22 se ejecutara una divicion y en la LCD sale una diagonal para representar la misma
          if (rs ==30){goto encendido;}     //Si rs es igual a 30 significa un AC/ON asi que va a encendido y muestra el ultimo calculo

          goto inicio2;       // Vamos al inicio2 que es incio de lsegundo digito
         }
                        //Copyrigth © Saul Lopez//
       }
         inicio2:             //etiqueta inicio2
         i =0;                //Variable para contar digitos a 0
         for(sr = 0; sr<5;sr++){  //Inicio del segundo contador For.
         tec = teclado();        //La Variable TEC es igual a la funcion teclado que otorga un valor del teclado
         delay_ms(250);          //Retardo de 250ms
         if ( tec <19){          //Solo si apacho un valor numerico menor a 19 entra en este if
            i++;                  //Variable Digito +1

                if ( i == 1){       //Si i es igual a 1 almacena el valor de tec en el primer vector
                b[0] = tec;
                PORTC = b[0];
                }
                if ( i  == 2){      //Si i es igual a 2 corre el valor del primer vector al 3 y el valor de tec lo almacena en el vector 2
                b[1] = b[0];
                b[0] = tec;
                }
                if (i == 3){        //Si i es igual a 3 se corren los vectores en su respectivo lugar
                b[2] = b[1];
                b[1] = b[0];
                b[0] = tec;
                }
                if ( i == 4){        //Si i es igual a 4 se corren los vectores en su respectivo lugar
                b[3] = b[2];
                b[2] = b[1];
                b[1] = b[0];
                b[0] = tec;
                }
                if (i == 5){         //Si i es igual a 5 se corren los vectores en su respectivo lugar
                b[4] = b[3];
                b[3] = b[2];
                b[2] = b[1];
                b[1] = b[0];
                b[0] = tec;
                }
              BT = ((b[0]*1)+(b[1]*10)+(b[2]*100)+(b[3]*1000)+(b[4]*10000));   //La suma total de los vectores de pendiendo del lugar almacenado
              IntToStr(BT , tb);    //El vlaor total del primer digito los conertimos a una variable String para poder mostrarla en la LCD
              Lcd_Out(1,9,TB);      //Se muestra la variable en LCD


            }
         else { //Si se presiono  un numero con el vlaor asignado mayor a 19 se va a la etiqueta Operacion

                goto OPERACION;

         }

       }
       OPERACION:       //Etiqueta Operacion
       while(1){        //Bucle infinito
       if( rs ==19){    //Si rs ya antes almacenada tiene un valor de 19 se sumaran los dos valores totales.
       OP = AT + BT;
       PORTC = OP;
       }
       if(rs ==20){     //Si rs ya antes almacenada tiene un valor de 20 se restaran los dos valores totales
       OP = AT -BT;
       PORTC = OP;
       }
       if (rs==21){     //Si rs ya antes almacenada tiene un valor de 21 se multiplicaran los dos valores totales
       OP = AT * BT;
       PORTC = OP;
       }
       if (rs ==22){    //Si rs ya antes almacenada tiene un valor de 22 se dividen los dos valores totales
       if (BT != 0){
       OP = AT / BT;
       PORTC = OP;}
       else
       {
       Lcd_Cmd(_LCD_CLEAR);  //Si el valor de el dividendo es 0 en la LCD mostrar mensje error.
       Lcd_Out(1,1,"ERROR");
       delay_ms(2000);
       Lcd_Cmd(_LCD_CLEAR);
       goto inicio;
       }
       }
       IntToStr(OP , to);   //Mostrar en la LCD el valor de la varible que almacena el calculo de las dos variables AT Y BT
       Lcd_Out(2,8,to);
       delay_ms(2000);
       Lcd_Cmd(_LCD_CLEAR);
       goto inicio;        //Regresar a etiqueta incio

            }




                         //Copyrigth © Saul Lopez//


    }

   }
   else{
   goto encendido;
   }
 }

void config(){    //Funcion de Configuracion
TRISD = 240;      //TRISD con los primeros puertos cuatro puertos como salidas y los otros 4 como entradas Digitales
PORTD = 0;        //PORTD CON VALOR INICAL DE 0
TRISC = 0;
PORTC = 0;
}
int teclado(){   //Funcion teclado
   while (1){
    PORTD = 0b00000001;

if (RD4_BIT ==1){
delay_ms(10);
return 1;

}
if (RD5_BIT ==1){
delay_ms(10);
return 2;
}
if (RD6_BIT ==1){
delay_ms(10);
return 3;
}
if (RD7_BIT ==1){
delay_ms(10);
return 19;  //Retorna 19 que es igual a "+"
}
PORTD = 0b00000010;
if (RD4_BIT ==1){
delay_ms(10);
return 4;
}
if (RD5_BIT ==1){
delay_ms(10);
return 5;
}
if (RD6_BIT ==1){
delay_ms(10);
return 6;
}
if (RD7_BIT ==1){
delay_ms(10);
return 20;      //Retorna 20 que es igual a "-"
}
PORTD = 0b00000100;
if (RD4_BIT ==1){
delay_ms(10);
return 7;
}
if (RD5_BIT ==1){
delay_ms(10);
return 8;
}
if (RD6_BIT ==1){
delay_ms(10);
return 9;
}
if (RD7_BIT ==1){
delay_ms(10);
return 21;       //Retorna 21 que es igual a "*"
}
PORTD = 0b00001000;
if (RD4_BIT ==1){
delay_ms(10);
return 30;      //Retorna que es igual a "AC/ON"
}
if (RD5_BIT ==1){
delay_ms(10);
return 0;
}
if (RD6_BIT ==1){
delay_ms(10);
return 31;     //Retorna 11 que es igual a "="
}
if (RD7_BIT ==1){
delay_ms(10);
return 22;      //Retorna 22 que es igual a  "/"
}
      }
   }
   //Copyrigth © Saul Lopez//
   //Copyrigth © Saul Lopez//
   //Copyrigth © Saul Lopez//