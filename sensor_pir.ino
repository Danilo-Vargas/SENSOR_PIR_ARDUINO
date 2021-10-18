
// USO DEL SENSOR PIR

// Aldo Danilo Vargas Esquivel - 15/10/2021

// INCLUIMOS LAS BIBLIOTECAS QUE SE USARAN

#include <Servo.h>

// DECLARAMOS LOS PINES DE ARDUINO

#define PIR 2 // Sensor PIR
#define LED 13 // LED
#define BUZ 4 // Buzzer
#define PIN_SERVO 5 // Servomotor

// VARIABLES DE ENTORNO

bool PIR_STATE;
int  deg_1 = 0;

// OBJETOS SERVO

Servo Servo_1;

// FUNCIONES

void readPIR(){ // Lee el valor del sensor PIR

    PIR_STATE = digitalRead(PIR);

}

void activate(){ // Activa la alarma (Led y servomotor)

    digitalWrite( LED, 1 );

    digitalWrite( BUZ, 1 );
    delay(200);
    digitalWrite( BUZ, 0 );
    delay(100);
    digitalWrite( BUZ, 1 );
    delay(200);
    digitalWrite( BUZ, 0 );
    delay(100);
    digitalWrite( BUZ, 1 );
    delay(200);
    digitalWrite( BUZ, 0 );
    delay(100);
    digitalWrite( BUZ, 1 );
    delay(200);
    digitalWrite( BUZ, 0 );
    delay(500);

    Servo_1.write(180);
    delay(1500);
    digitalWrite( LED, 0 );

}

void desactivate(){ // Desactiva la alarma (Led y servomotor)

    digitalWrite( LED, 0 );
    digitalWrite( BUZ, 0 );

    Servo_1.write(0);
    delay(1500);

}

void setState(){

    readPIR();

    if ( PIR_STATE == 1 ) {
        activate();
    } else {
        desactivate();
    }

}

void setup()
{
	pinMode( PIR, INPUT );
	pinMode( LED, OUTPUT );
	pinMode( BUZ, OUTPUT );

    Servo_1.attach(PIN_SERVO);
    Servo_1.write(0);
    delay(100);

    Serial.begin(9600);
}

void loop()
{
    setState();
    Serial.println(PIR_STATE);
}
