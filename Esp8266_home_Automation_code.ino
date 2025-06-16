#include <IRremote.h>
int IRpin =D0;
IRrecv irrecv(IRpin);
decode_results results;

int code;

#define B1 D4
#define B2 D3
#define B3 D2        //for take input from button
#define B4 D1

#define led1 D8
#define led2 D7
#define led3 D6      // for gives the output to the led
#define led4 D5

byte b1=1;
byte b2=1;
byte b3=1;           // store status for debouncing purpose
byte b4=1;

bool state_led1 = LOW;
bool state_led2 = LOW;
bool state_led3 = LOW;     //store status of the button
bool state_led4 = LOW;


unsigned long lastTimeButtonStateChanged=millis();
unsigned long debounceDuration =50; // millis

#include<ESP8266WiFi.h>

#include<ESP8266mDNS.h>

WiFiClient client;
WiFiServer server(80);
String request;

void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2,INPUT_PULLUP);
  pinMode(B3,INPUT_PULLUP);
  pinMode(B4,INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

MDNS.begin("esp");
WiFi.softAP("node","12345678");
   Serial.println();
  Serial.print("nodemcu started");
  Serial.print(WiFi.softAPIP());
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

 client=server.available();  //gets client that is connectect to the server
 if(client==1)
 {
    request=client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
 }

   if(irrecv.decode(&results))
  {
    code = results.value;
    Serial.println(code);
     delay(80);
    irrecv.resume();
  }
  delay(80);
  if(millis()-lastTimeButtonStateChanged >=debounceDuration)
  {
      //For Button 1

    byte buttonState1=digitalRead(B1);
    if(buttonState1 != b1 || code==33444015  ||  request=="GET /led1 HTTP/1.1")
    {
      lastTimeButtonStateChanged =millis();
      b1=buttonState1;
      if (buttonState1==HIGH)
      {
        Serial.println("B1 Button has been released");
        digitalWrite(D8,b1);
        if(state_led1==LOW)
        {
          state_led1=HIGH;
        }
        else if(state_led1==HIGH)
        {
          state_led1=LOW;
        }
      } 
      
      digitalWrite(led1,state_led1); 
      code=0;
    }
    delay(10);

      //For Button 2

    byte buttonState2=digitalRead(B2);
      if(buttonState2 !=b2 || code==33478695  || request=="GET /led2 HTTP/1.1")
      {
        lastTimeButtonStateChanged =millis();
        b2=buttonState2;
        if(buttonState2==HIGH)
        {
          Serial.println("B2 button has been released");
           if(state_led2==LOW)
        {
          state_led2=HIGH;
        }
        else if(state_led2==HIGH)
        {
          state_led2=LOW;
        }
        }
        digitalWrite(led2,state_led2);
        code=0;
      }
      delay(10);

      //For Button 3

      byte buttonState3=digitalRead(B3);
      if(buttonState3 !=b3 || code==33486855  ||request=="GET /led3 HTTP/1.1")
      {
        lastTimeButtonStateChanged =millis();
        b3=buttonState3;
        if(buttonState3==HIGH)
        {
          Serial.println("B3 button has been released");
           if(state_led3==LOW)
        {
          state_led3=HIGH;
        }
        else if(state_led3==HIGH)
        {
          state_led3=LOW;
        }
        }
        digitalWrite(led3,state_led3);
        code=0;
      }
      delay(10);
      
      //For Button 4

       byte buttonState4=digitalRead(B4);
      if(buttonState4 !=b4 || code==33435855 ||request=="GET /led4 HTTP/1.1")
      {
        lastTimeButtonStateChanged =millis();
         delay(10);
        b4=buttonState4;
        if(buttonState4==HIGH)
        {
          Serial.println("B4 button has been released");
           if(state_led4==LOW)
        {
          state_led4=HIGH;
        }
        else if(state_led4==HIGH)
        {
          state_led4=LOW;
        }
        }
        digitalWrite(led4,state_led4);
        code=0;
      }

  }
          MDNS.update();

  client.println("HTTP/1.1 200 ok");
  client.println("Content-Type: text/html");
  client.println("");
  client.print("<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <style>\n"
"            .intd\n"
"            {\n"
"                text-align: center;\n"
"                font-size:20px;\n"
"                scroll-margin-left: 30%;\n"
"            }\n"
"            .inbutton\n"
"            {\n"
"                font-size:30px;\n"
"                color:rgb(255, 255, 161);\n"
"                background-color:rgb(81, 81, 241);\n"
"                padding: 3%;\n"
"                border:10px solid rgb(96, 117, 65);\n"
"                border-radius: 100%;\n"
"                margin-right:40%;\n"
"            }\n"
"            .forstatusbar\n"
"            {\n"
"                font-size:25px;\n"
"                color:red;\n"
"                border-style:double;\n"
"                font-family:Times New Roman;\n"
"                \n"
"             }\n"
"             .lr\n"
"             {\n"
"                font-size:25px;\n"
"                border-style:solid;\n"
"                border-width:5px;\n"
"                padding-left:20%;\n"
"                padding-right: 20%;\n"
"                font-family: Times New Roman;\n"
"             }\n"
"             .inbutton:hover\n"
"             {\n"
"                background-color:rgb(187, 187, 240);\n"
"                color:blue;\n"
"                border-color: rgb(39, 251, 39);\n"
"             }\n"
"             .inbutton:active \n"
"             {\n"
"                background-color:green;\n"
"                border-color:blue;\n"
"            }\n"
"            \n"
"        </style>\n"
"        <body text=\"blue\" bgcolor=\"black\">\n"
"           \n"
"            <table align=\"center\" border=\"0\" width=\"100%\" height=\"750px\">                                                                          \n"
"                <tr ><td colspan=\"2\"><center class=\"forstatusbar\"><b>MY HOME POWER PROFILE</b></center></td></tr>\n"
"                <tr><td colspan=\"2\"> <marquee behavior=\"alternate\"><font color=\"GREEN\" size=\"6%\"><b>Welcome</b></font></marquee></td></tr>\n"
"                    <tr><td colspan=\"2\"><center><b class=\"lr\">Living Room</b></center></td></tr>\n"
"                    <tr height=\"9%\"><td colspan=\"2\"><center></center></td></tr>\n"
"                    <tr><td class=\"intd\"><a href=\"\led1\"\"><button class=\"inbutton\">Device 1</button></a></td><td class=\"intd\">Click Device1</td></tr>\n"
"                    <tr><td class=\"intd\"><a href=\"\led2\"\"><button class=\"inbutton\">Device 2</button></a></td><td class=\"intd\">Click Device2</td></tr>\n"
"                    <tr><td class=\"intd\"><a href=\"\led3\"\"><button class=\"inbutton\">Device 3</button></a></td><td class=\"intd\">Click Device3</td></tr>\n"
"                    <tr><td class=\"intd\"><a href=\"\led4\"\"><button class=\"inbutton\">Device 4</button></a></td><td class=\"intd\">Click Device4</td></tr>\n"
"            </table>\n"
"        </body>\n"
"    </head>\n"
"</html>");
delay(10);
  
}







