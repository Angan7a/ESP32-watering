#include <WiFi.h>
#include"http.hpp"

// Replace with your network credentials

const char* ssid = "CGA2121_VzpmSRV";
const char* password = "b1e514f452ea181e991056b9cbee3df73acdb2c5e8bc6dafcd96c66a9840bb48";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";

// Assign output variables to GPIO pins
const int output26 = 26;
const int output27 = 27;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
            } else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
            }
string page =  load_page();
for(int i = 0; i < page.size(); i++)
{
client.print(page[i]);
}
/* client.println("<html>");
 client.println("<style>");
 client.println("ul {column-count: 3; column-gap: 18rem;}");
 client.println("</style>");

client.println("<body>");

client.println("<p><b>Ustawienia czasu podlewania:</b></p>");
client.println("<ul class=\"checkboxes\">");
client.println("<form action=\"/act\" method=\"get\">");
client.println("<li><label><input type=\"checkbox\" name=\"text24\" value=\"24\" />0:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text1\" value=\"1\" />1:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text2\" value=\"2\" />2:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text3\" value=\"3\" />3:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text4\" value=\"4\" />4:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text5\" value=\"5\" />5:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text6\" value=\"6\" />6:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text7\" value=\"7\" />7:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text8\" value=\"8\" />8:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text9\" value=\"9\" />9:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text10\" value=\"10\" />10:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text11\" value=\"11\" />11:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text12\" value=\"12\" />12:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text13\" value=\"13\" />13:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text14\" value=\"14\" />14:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text15\" value=\"15\" />15:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text16\" value=\"16\" />16:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text17\" value=\"17\" />17:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text18\" value=\"18\" />18:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text19\" value=\"19\" />19:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text20\" value=\"20\" />20:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text21\" value=\"21\" />21:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text22\" value=\"22\" />22:00</label></li>");
client.println("<li><label><input type=\"checkbox\" name=\"text23\" value=\"23\" />23:00</label></li>");
client.println("</ul>");
*/
/*
            // Display the HTML web DDD
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");

            // Display current state, and ON/OFF buttons for GPIO 26
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 27
            client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button
            if (output27State=="off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
*/
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
