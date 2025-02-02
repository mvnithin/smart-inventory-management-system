#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
const char * myWriteAPIKey = "PK0WSCJ66DOMUE9D";
const char *ssid =  "Nithin-hp15s";     // Enter your WiFi Name
const char *pass =  "12345678"; // Enter your WiFi Password
unsigned long myChannelNumber = 2693870;
WiFiClient client;

int trigPin = D6;
int echoPin = D7;
int Chocolate=0;
int Icecream=0;

int trig1Pin = D1;
int echo1Pin = D2;
void setup() {
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(trig1Pin, OUTPUT);
  pinMode(echo1Pin, INPUT);
  Serial.begin(115200);
  ThingSpeak.begin(client);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
     {
            delay(550);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
}

void loop(){
     Product1();
     Product2();
  }
void Product1(){
    delay(500); // Small delay between readings
    Serial.println("\n");
    int duration, distance;

    // Triggering the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echo duration
    duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout to avoid 0 readings

    // Convert to distance
    distance = (duration / 2) / 29.1;
    Serial.print("distance value ");
    Serial.println(distance);

    // Determine stock level based on distance
    if (distance < 23) {
        Icecream = 5;
    } else if (distance < 35) {
        Icecream = 4;
    } else if (distance < 47) {
        Icecream = 3;
    } else if (distance < 60) {
        Icecream = 2;
    } else if (distance < 70) {
        Icecream = 1;
    } else {
        Icecream = 0;
    }

    // Print and upload to ThingSpeak
    Serial.print(Icecream);
    Serial.println("  Icecream");
    ThingSpeak.writeField(myChannelNumber, 1, Icecream, myWriteAPIKey);
}

// void Product1(){
// delay(500);// reading will be taken after ....miliseconds
// Serial.println("\n");
// int duration, distance;
//     digitalWrite (trigPin, HIGH);
//     delayMicroseconds (10);
//     digitalWrite (trigPin, LOW);
//     duration = pulseIn (echoPin, HIGH);
//     distance = (duration/2) / 29.1;
//     Serial.println(distance);
   
//     if (distance <23) {  // Change the number for long or short distances.
//     Icecream=5;
//     Serial.println("\n");
//     Serial.print(Icecream); 
//     Serial.print("  Icecream");
//     }
//     if (distance >23 && distance <35) {  // Change the number for long or short distances.
//     Icecream=4;
//     Serial.println("\n");
//     Serial.print(Icecream);
//     Serial.print("  Icecream"); 
//     }
//     if (distance >35 && distance <47) {  // Change the number for long or short distances.
//     Icecream=3;
//     Serial.println("\n");
//     Serial.print(Icecream);
//     Serial.print("  Icecream"); 
//     }
//     if (distance >47 && distance <60) {  // Change the number for long or short distances.
//     Icecream=2;
//     Serial.println("\n");
//     Serial.print(Icecream);
//     Serial.print("  Icecream"); 
//     }
//     if (distance >60 && distance <70) {  // Change the number for long or short distances.
//     Icecream=1;
//     Serial.println("\n");
//     Serial.print(Icecream); 
//     Serial.print("  Icecream");
//     }
//     if(distance >70){
//     Icecream= 0; 
//     Serial.println("\n");    
//     Serial.print(Icecream);
//     Serial.print("  Icecream");
//     }
//     ThingSpeak.writeField(myChannelNumber, 1,Icecream, myWriteAPIKey);
 
//       }
    
void Product2(){
delay(500);// reading will be taken after ....miliseconds
Serial.println("\n");
int duration, distance;
    digitalWrite (trig1Pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trig1Pin, LOW);
    duration = pulseIn (echo1Pin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.println(distance);
    if (distance <23) {  // Change the number for long or short distances.
    Chocolate=5;
    Serial.println("\n");
    Serial.print(Chocolate);
    Serial.print("Chocolate"); 
    }
    if (distance >23 && distance<35) {  // Change the number for long or short distances.
    Chocolate=4;
    Serial.println("\n");
    Serial.print(Chocolate); 
    Serial.print("  Chocolate");
    }
    if (distance >35 && distance< 47) {  // Change the number for long or short distances.
    Chocolate=3;
    Serial.println("\n");
    Serial.print(Chocolate); 
    Serial.print("  Chocolate");
    }
    if (distance >47 && distance< 60) {  // Change the number for long or short distances.
    Chocolate=2;
    Serial.println("\n");
    Serial.print(Chocolate);
    Serial.print("  Chocolate"); 
    }
    if (distance >60 && distance< 70) {  // Change the number for long or short distances.
    Chocolate=1;
    Serial.println("\n"); 
    
    Serial.print(Chocolate);
    Serial.print("  Chocolate"); 
    }
    if(distance>70){
    Chocolate= 0; 
    Serial.print(Chocolate);
    Serial.print("  Chocolate");
     
    }
    ThingSpeak.writeField(myChannelNumber, 2,Chocolate, myWriteAPIKey);

    }