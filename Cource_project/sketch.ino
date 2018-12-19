#define DATA 6
#define LATCH 8
#define CLOCK 10

#define DATA_T 5
#define LATCH_T 12
#define CLOCK_T 11

int coins_team1 = 0;
int coins_team2 = 0;

/*
    0 = второй разряд первого
    1 = первый разряд первого
    2 = второй разряд второго
    3 = первый разряд второго
    4 = стрелки и единицы обоих игроков
    5 = таймы
*/

//              0 1 2 3 4 
int tablo[] = { 0,0,0,0,0 };
int  time[] = { 0,0,0,0   };
int   out[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//                0   1  2   3   4  5  6  7  8   9 
int master[] =  {119,65,110,107,89,59,63,97,127,123};

void shift(int IN, int type){
    if (type != 0) { IN += 128; }

    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, IN);
    digitalWrite(LATCH, HIGH);
}

void shift_t(int IN){
    digitalWrite(LATCH_T, LOW);
    shiftOut(DATA_T, CLOCK_T, LSBFIRST, master[IN]);
    digitalWrite(LATCH_T, HIGH);
}

void shift_driver() {
    int hun1 = 0, hun2 = 0;
    int arr1 = 0, arr2 = 0;
    if (coins_team1 > 0) { hun1 = 1; }
    if (coins_team2 > 0) { hun2 = 1; }

  	shift( master[tablo[0]], hun1 );
  	shift( master[tablo[1]], arr1 );
    shift( master[tablo[2]], hun2 );
    shift( master[tablo[3]], arr2 );      
    shift( master[tablo[4]], 0 );
}	

void time_driver() {
    shift_t( time[0] );
    shift_t( time[1] );
    shift_t( time[2] );   
    shift_t( time[3] );
} 

void setup(){
    // Управление счетом
    pinMode(LATCH, OUTPUT); 
    pinMode(CLOCK, OUTPUT);
    pinMode(DATA, OUTPUT);
    // Управление временем
    pinMode(DATA_T, OUTPUT);
    pinMode(LATCH_T, OUTPUT); 
    pinMode(CLOCK_T, OUTPUT);

    shift_driver(); time_driver();
    Serial.begin(9600);
}

void push() {
    coins_team1 = out[0];
    coins_team2 = out[4];

    tablo[0] = out[8];
    tablo[1] = out[6];
    tablo[2] = out[5];
    tablo[3] = out[2];
    tablo[4] = out[1];

    time[0] = out[14];
    time[1] = out[13];
    time[2] = out[11];
    time[3] = out[10];

    shift_driver(); time_driver();
}


void loop(){
    if (Serial.available() > 0) {
        delay(5);
        for (int i = 0; Serial.available() > 0; i++) {
            out[i] = Serial.read() - '0';
            if (out[i] == 35) { out[i] = 0; i = -1;
                // Serial.println(1111);
            }
        }

        for (int i = 0; i < 15; i++) {
            Serial.println(out[i]);
        }
        Serial.println(9999999);
        Serial.flush();
        push();
    }
    delay(500);
}


// S011X015X5X01X50E