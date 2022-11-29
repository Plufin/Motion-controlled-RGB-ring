#include <Adafruit_MPU6050.h> //Include kirjasto sensoriin
#include <Adafruit_NeoPixel.h> //Include kirjasto ledeille
#ifdef __AVR__
#include <avr/power.h> 
#endif
#define PIN       2 
#define NUMPIXELS 16
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50

Adafruit_MPU6050 mpu;
Adafruit_Sensor *mpu_temp, *mpu_accel, *mpu_gyro;

void setup(){
//Sensor setup
Serial.begin(115200);
  while (!Serial)
    delay(10);

  Serial.println("Adafruit MPU6050 test!");

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip"); //Etsitään MPU6050
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 Found!");

//Ring setup
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.setBrightness(50); //LED-kirkkaus
  pixels.begin();

//Määritetään tehtävä kiihtyvyydelle
  mpu_accel = mpu.getAccelerometerSensor();
  mpu_accel->printSensorDetails();
  sensors_event_t accel; 
  mpu_accel->getEvent(&accel);
}


void loop() {
//Otetaan dataa kiihtyvyysanturista
  int Angle, i, a, j, k; //Kulma, syttyvä led sijainti ja siitä riippuvat RGB-arvot
  sensors_event_t accel;
    mpu_accel->getEvent(&accel);
    Angle = (accel.acceleration.y*10); //*10 mappauksen helpottamiseksi

//
i = constrain(map(Angle, -100, 100, 15, 0),0,15); //Anturin antama info käännetään led-valojen määrän mukaan
a = map(Angle, -95, 100, 255, 0); //Eri kulmassa eri väri
j = map(Angle, -95, 100, 0, 100);
k= map(Angle,-95, 100, 0, 255);
//Serial.println(Angle);
    pixels.setPixelColor(i, pixels.Color(a,j,k)); //Väri vaihtuu joka pikselillä

    pixels.show();
    pixels.clear();



delay(DELAYVAL);
}
