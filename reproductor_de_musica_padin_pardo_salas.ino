// C++ code
//
//-------------------------------------------------------------------------
//Libreria para inicializar la pantalla LCD.
#include <Adafruit_LiquidCrystal.h>

//Inicializamos en donde va a estar el pin del buzzer y asignamos la pantalla a la definicion lcd_1.
int buzzer = 12;
Adafruit_LiquidCrystal lcd_1(0x16);
//El funcionamiento en fisico no pudimos hacerlo andar la pantallita, pero en tinkercad funciona
//-------------------------------------------------------------------------
//Definicion de las notas a reproducir con su frecuencia
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
// Notas en las melodias:
// Habria tres canciones predeterminadas cargadas:
// 1- DURACION LARGA - SEE YOU AGAIN
// 2 - DURACION MEDIA - AHORA TE PUEDES MARCHAR
// 3 - DURACION CORTA - SUNFLOWER

int melody[] = {
  //See you again
  NOTE_AS4, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_G5,
  NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_D5, NOTE_C5,
  NOTE_D5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_G5,  
  NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_D5, NOTE_C5,
  NOTE_D5, NOTE_F5, NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_AS5,
  NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_AS5, 0,
  NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, 
  NOTE_C5, NOTE_D5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_G4, NOTE_AS4, NOTE_G4,
  NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_G4, NOTE_AS4, NOTE_G4,
  NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_AS4,
};

int melody1[] = {
  //Ahora te podes marchar
  NOTE_B5, NOTE_GS6, NOTE_FS6, NOTE_FS6, NOTE_E6, NOTE_E6, NOTE_DS6, NOTE_DS6, NOTE_CS6, NOTE_CS6, 0, NOTE_GS5, NOTE_GS5, 0,
  NOTE_B5, NOTE_GS6, NOTE_FS6, NOTE_FS6, NOTE_E6, NOTE_E6, NOTE_DS6, NOTE_DS6, NOTE_CS6, NOTE_CS6, 0, NOTE_GS5, NOTE_GS5, 0,
  NOTE_GS5, NOTE_A5, NOTE_CS6, NOTE_E6, NOTE_DS6, NOTE_DS6, NOTE_B5, NOTE_CS6, NOTE_GS6, NOTE_FS6,
  NOTE_B5, NOTE_GS6, NOTE_FS6, NOTE_FS6, NOTE_E6, NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_FS6, NOTE_GS6, NOTE_CS6, NOTE_CS6, 0,
  NOTE_CS6, NOTE_A6, NOTE_GS6, NOTE_FS6, NOTE_E6, NOTE_GS6, NOTE_FS6, 0,
  NOTE_GS6, NOTE_A6, NOTE_GS6, NOTE_FS6, NOTE_E6, NOTE_FS6, NOTE_FS6, NOTE_E6, 0,
};

int melody2[] = {
 //Sunflower
 NOTE_B5, NOTE_A5, NOTE_B5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_FS5, NOTE_E5, NOTE_D5, 
};
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
// Duraciones de las notas, 1: siendo una nota larga, 2: un poco mas corta,
// 3: mas corta todavia y asi..

int noteDurations2 [] = {
  2, 8, 8, 3, 8, 4, 4, 4, 8, 8, 4, 8, 8, 3, 8, 2
};

int noteDurations1[] = {
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 4, 2, 5,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 4, 2, 6,
    6, 4, 6, 6, 6, 4, 6, 6, 4, 2,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 3, 2,
    6, 3, 3, 6, 4, 3, 3, 3,
    6, 6, 6, 6, 6, 6, 3, 1, 1
};

int noteDurations[]{
  4, 4, 4, 1, 2, 2,
  8, 2, 4, 6, 4, 1,
  8, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
  6, 6, 1, 4, 3, 2,
  8, 2, 4, 6, 6, 1,
  6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
  4, 4, 4, 4, 4, 1, 2,
  3, 5, 3, 5, 3, 
  8, 8, 8, 8, 8, 3, 8, 4, 6, 4, 6, 2,
  8, 8, 8, 
  3, 6, 4, 6, 4, 6, 2,
  8, 8, 8,
  3, 6, 4, 6, 2,
  
}; 
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//Todo nuestro funcionamiento esta en el SETUP y no en el LOOP porque queremos que cuando
//el usuario escriba "SALIR", el codigo se "apague"
//-------------------------------------------------------------------------
//Num de cancion (predeterminado es 1 pero igual despues cambia)
int cancion = 1; 

void setup() {
  //Inicializar pantalla, serial y buzzer
  Serial.begin(9600);
  lcd_1.begin(8, 9);
  pinMode(buzzer, OUTPUT);

  //Es la primera vez que el usuario esta reproduciendo una cancion?
  bool primeraVez = true;

  //Podria haber sido en void loop { } tambien, pero de manera infinita lo hacemos en el setup
  //porque queremos que el codigo termine de ejecutarse cuando el usuario pone
  //SALIR
  while (true) {
    while (Serial.available() > 0) {
      Serial.read();
      
    }

    lcd_1.clear();
    
    if (primeraVez) {
      //Si es la primera vez solicitamos que cancion reproducir
      lcd_1.setCursor(0, 0);
      lcd_1.print("Elige cancion:");
      lcd_1.setCursor(0, 1);
      lcd_1.print("1, 2 o 3 en Serial");
      Serial.println("Ingrese el numero de la cancion (1, 2 o 3):");
      primeraVez = false;
    } else {
      //Sino preguntamos cual cancion quiere reproducir
      lcd_1.setCursor(0, 0);
      lcd_1.print("Otra? (1 o 2)");
      lcd_1.setCursor(0, 1);
      lcd_1.print("o escribi SALIR");
      Serial.println("Ingrese otra cancion (1, 2 o 3) o escriba SALIR:");
    }


    while (Serial.available() == 0) {
      delay(50);
    }

    //Leemos input del usuario

    String entrada = Serial.readString();

    if (entrada == "SALIR") {
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      break;
      //Si es SALIR, limpiamos la pantalla y cerramos el codigo
    }
  
    //Por las dudas convierte la entrada de cancion a numero entero
    int cancion = entrada.toInt();

    if (cancion != 1 && cancion != 2 && cancion != 3) {
      //Si no es ninguna de las opciones, imprimimos que es invalido
      Serial.println("Opcion invalida. Escriba 1, 2, 3 o SALIR.");
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Opcion invalida");
      delay(1000);
      continue;
    }

    
    int totalNotas = 0;
    
	//Iniciamos la cantidad de notas totales de cada cancion
    if (cancion == 1) {
      totalNotas = 68;
    } else if (cancion == 2){
      totalNotas = 94;
    } else if (cancion == 3) {
      totalNotas = 16;
    }
	
    //Bucle que hace que toque las notas en orden y con su duracion
    for (int thisNote = 0; thisNote < totalNotas; thisNote++) {
      float noteDuration = 0;
      int notaActual = 0;

      if (cancion == 1) {
        //Calculacion de longitud de notas
        noteDuration = 1000.0 / noteDurations1[thisNote];
        notaActual = melody1[thisNote];

        //Subtitulos, cuando llega a X nota la pantalla se actualiza
        //con su subtitulo apropiado
        switch (thisNote) {
          case 0:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("Si tu me");
            lcd_1.setCursor(0, 1);
            lcd_1.print("hubieras dicho");
            break;
          case 7:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("siempre la");
            lcd_1.setCursor(0, 1);
            lcd_1.print("verdad");
            break;
          case 14:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("si hubieras");
            lcd_1.setCursor(0, 1);
            lcd_1.print("respondido");
            break;
          case 21:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("cuando te");
            lcd_1.setCursor(0, 1);
            lcd_1.print("llame");
            break;
          case 28:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("si hubieras");
            lcd_1.setCursor(0, 1);
            lcd_1.print("amado");
            break;
          case 34:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("cuando te ame");
            break;
          case 38:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("serias en mi");
            lcd_1.setCursor(0, 1);
            lcd_1.print("sueno");
            break;
          case 45:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("la mejor mujer");
            break;
          case 51:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("si no supiste");
            lcd_1.setCursor(0, 1);
            lcd_1.print("amar");
            break;
          case 59:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("ahora te podes");
            lcd_1.setCursor(0, 1);
            lcd_1.print("marchar");
            break;
        }
      } 
      
      //Lo mismo que antes pero para la segunda cancion
      else if (cancion == 2) {
        noteDuration = 1000.0 / noteDurations[thisNote];
        notaActual = melody[thisNote];
        
          switch (thisNote) {
          case 0:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("It's been a"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("long day"));
            break;
          case 6:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("without you,"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("my friend"));
            break;
          case 12:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("And I'll tell"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("you all about it"));
            break;
          case 19:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("when I see"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("you again"));
            break; 
          case 27:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("We've come"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("a long way"));
            break; 
          case 33:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("from where we"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("began"));
            break;
          case 39:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("Oh, I'll tell"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("you all about it"));
            break;
          case 46:
         	lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("When I see you"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("again..."));
        }
      }

        //Tercerca cancion, la mas corta
        
        else if (cancion == 3) {
        noteDuration = 1000.0 / noteDurations2[thisNote];
        notaActual = melody2[thisNote];
        
          switch (thisNote) {
          case 0:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("Ooh- o- o- oh"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("ooh- ooh"));
            break;
          case 8:
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print(F("Some things you"));
            lcd_1.setCursor(0, 1);
            lcd_1.print(F("just cant refuse"));
            break;
        }
      }
    
      

      //Reproduce el siguiente sonido y añade una espera chiquita entre nota y nota
      tone(buzzer, notaActual, noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(buzzer);
    }
  }
}

void loop() {
  
}
