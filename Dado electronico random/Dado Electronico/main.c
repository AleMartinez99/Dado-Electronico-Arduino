/*
 * MIT License
 *
 * Copyright (c) 2021 [Lucas Ferrini - FacuFalcone]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

int botonRandomActual = LOW;
int botonRandomAnterior = LOW;

int botonUpActual = LOW;
int botonUpAnterior = LOW;

int botonDownActual = LOW;
int botonDownAnterior = LOW;

int randomRebotes;
int numeroActual = 0;

void setup(){
  	Serial.begin(9600);
	for(int i=5;i<12;i++)
    {
        pinMode(i, OUTPUT);
    }
	for(int i=2;i<5;i++)
  	{
        pinMode(i, INPUT);
  	}
}

void prender1(){

    digitalWrite(8, HIGH);

    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
}

void prender2(){

    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);

    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
}

void prender3(){

   	digitalWrite(7, HIGH);
  	digitalWrite(8, HIGH);
  	digitalWrite(11, HIGH);

	digitalWrite(5, LOW);
  	digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);

}

void prender4(){

    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);

    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
}

void prender5(){

    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);

    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
}

void prender6(){
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);

    digitalWrite(8, LOW);
}

void rebotar(){
    randomRebotes = random(3, 5);
    for (int i = 0; i <= randomRebotes; i++) {
        numeroAzar();
        delay(300);
  }
}

void numeroAzar(){
    numeroActual = random(1, 6);
    mostrarNumero(numeroActual);
}

void cambiarValor(int valor){
    int aux = numeroActual + valor;
  if(aux <= 6 && aux >= 1){
    numeroActual = aux;
    mostrarNumero(numeroActual);
  }
}

void mostrarNumero(int numero){

  switch (numero) {
    case 1:
      prender1();
      break;
    case 2:
      prender2();
      break;
    case 3:
      prender3();
      break;
    case 4:
      prender4();
      break;
    case 5:
      prender5();
      break;
    case 6:
      prender6();
      break;
  }
}

void loop() {
  botonRandomActual = digitalRead(2);

  if(botonRandomActual == HIGH && botonRandomActual != botonRandomAnterior){
      rebotar();
      numeroAzar();
  }
    botonRandomAnterior = botonRandomActual;

    if (numeroActual != 0) {
        botonDownActual = digitalRead(3);
        botonUpActual = digitalRead(4);

        if(botonUpActual == HIGH && botonUpActual != botonUpAnterior){
          cambiarValor(1);
      }
        if(botonDownActual == HIGH && botonDownActual != botonDownAnterior){
          cambiarValor(-1);
      }

        botonUpAnterior = botonUpActual;
        botonDownAnterior = botonDownActual;
    }
}
