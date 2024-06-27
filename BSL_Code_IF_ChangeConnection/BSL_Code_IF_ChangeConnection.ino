#include <WiFi.h>

// Define the SSID and password for the WiFi networks
String ssid = "nagesh____";
String password = "rahul mehta";

// Create WiFiServer object
WiFiServer server(8080);

// Function to connect to the WiFi network
void connect_to_wifi(const char* ssid, const char* password)
{
    // Begin WiFi connection with provided SSID and password
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");

    // Wait for the connection to establish
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(200);
        Serial.print("...");
    }

    // WiFi connected, print the IP address
    Serial.println();
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Start the server on port 8080
    server.begin();
}

String receive_from_client(WiFiClient &client)
{
    // Check if the client has sent any data
    if (client.available())
    {
        // Read the client's request
        String request = client.readStringUntil('\n');
        request.trim(); // Remove any leading/trailing whitespace
        client.flush(); // Clear the input buffer

        // Convert the request to uppercase
        request.toUpperCase();

        // Send back the uppercase request as confirmation
        client.print("sent: ");
        client.println(request);

        // If the request is "CLOSE", disconnect the client
        if (request == "CLOSE")
        { // Case insensitive check after conversion
            client.stop();
            Serial.println("Client disconnected");
            return "client disconnected";
        }
        

        // Return the uppercase request
        return request;
    }
    // Return an empty string if no data is available
    return "";
}

String receive_from_client_for_new_connection(WiFiClient &client)
{
    // Check if the client has sent any data
    if (client.available())
    {
        // Read the client's request
        String request = client.readStringUntil('\n');
        request.trim(); // Remove any leading/trailing whitespace
        client.flush(); // Clear the input buffer

        // Convert the request to uppercase
        // request.toUpperCase();

        // Send back the uppercase request as confirmation
        client.print("sent: ");
        client.println(request);
        

        // Return the uppercase request
        return request;
    }
    // Return an empty string if no data is available
    return "";
}

#define IN 26
#define LATCH 27
#define CLK 14
#define N_CLR 12
#define LD_M 100

void latch_input(bool *arr, int size)
{
    digitalWrite(N_CLR, LOW);
    delayMicroseconds(50);
    digitalWrite(N_CLR, HIGH);
    for (int i = 0; i < size; i++)
    {
        // Set the data bit
        digitalWrite(IN, arr[i]);

        // Pulse the clock to shift the bit in
        digitalWrite(CLK, HIGH);
        delayMicroseconds(50); // Small delay to ensure the clock pulse is registered
        digitalWrite(CLK, LOW);
        delayMicroseconds(50); // Small delay to ensure the clock pulse is registered
    }

    // Latch the data to the output pins
    digitalWrite(LATCH, HIGH);
    delayMicroseconds(50); // Small delay to ensure the latch pulse is registered
    digitalWrite(LATCH, LOW);
    delayMicroseconds(50); // Small delay to ensure the latch pulse is registered
}

//**********************************//
// A to Z characters :
bool arrA[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrB[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH,
    HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrC1[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrC2[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrC3[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrC4[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrC5[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrC6[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrC7[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrD[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW,
    HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrE[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrG[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH,
    HIGH, LOW, HIGH, LOW, LOW, HIGH, HIGH, LOW,
    LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrH1[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH,
    HIGH, HIGH, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrH2[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrH3[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH,
    HIGH, HIGH, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrH4[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrH5[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW,
    LOW, HIGH, LOW, LOW, HIGH, LOW, LOW, LOW};
bool arrH6[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH,
    LOW, LOW, HIGH, LOW, LOW, HIGH, LOW, LOW};
bool arrH7[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    HIGH, LOW, LOW, HIGH, LOW, LOW, HIGH, HIGH};

bool arrI[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW};

bool arrJ1[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW};
bool arrJ2[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW};
bool arrJ3[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrJ4[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrJ5[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrJ6[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrJ7[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrJ8[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrK[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrL[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH,
    HIGH, HIGH, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrM[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH,
    HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,
    HIGH, HIGH, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrN[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,
    HIGH, HIGH, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrO[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW};

bool arrP[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrQ[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrR[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    HIGH, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrS[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrT[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrU[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH};

bool arrV[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, LOW,
    HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrW[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,
    HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH};

bool arrX[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrY1[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrY2[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool arrY3[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrY4[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool arrZ[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

bool lowarr[] = {
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
    LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

// **************************************//

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);

    // Connect to the WiFi network
    connect_to_wifi(ssid.c_str(), password.c_str());

    // Set pin modes
    pinMode(IN, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(N_CLR, OUTPUT);

    // Initial state setup
    digitalWrite(CLK, LOW);
    digitalWrite(LATCH, LOW);
    digitalWrite(N_CLR, LOW); // Clear the shift register
    delayMicroseconds(50);
    digitalWrite(N_CLR, HIGH); // Enable normal operation
}

void loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        connect_to_wifi(ssid.c_str(), password.c_str());
    }

    // Check if a client has connected to the server
    WiFiClient client = server.available();
    // Data array to be shifted in (32 bits for 4 shift registers)
    // Shift the data in
    if (client)
    {
        Serial.println("Client connected");
        while (client.connected())
        {
            String input = receive_from_client(client);
            
            if (!input.isEmpty())
            {
                Serial.println(input);
                // client.println("hello");
                if (input == "CHANGE CONNECTION")
                {
                    client.print("Enter SSID: ");
                    String new_ssid = receive_from_client_for_new_connection(client);
                    while (new_ssid.isEmpty())
                    {
                        new_ssid = receive_from_client_for_new_connection(client);
                    }
                    new_ssid.trim();

                    client.print("Enter Password: ");
                    String new_password = receive_from_client_for_new_connection(client);
                    while (new_password.isEmpty())
                    {
                        new_password = receive_from_client_for_new_connection(client);
                    }
                    new_password.trim();

                    ssid = new_ssid;
                    password = new_password;
                    connect_to_wifi(ssid.c_str(), password.c_str());
                    // Notify the client
                    client.println("Reconnected to new WiFi network");
                }
                else if (input == "A")
                {
                    latch_input(arrA, 32);
                    delay(LD_M);
                }
                else if (input == "B")
                {
                    latch_input(arrB, 32);
                    delay(LD_M);
                }
                else if (input == "C")
                {
                    latch_input(arrC1, 32);
                    delay(LD_M);
                    latch_input(arrC2, 32);
                    delay(LD_M);
                    latch_input(arrC3, 32);
                    delay(LD_M);
                    latch_input(arrC4, 32);
                    delay(LD_M);
                    latch_input(arrC5, 32);
                    delay(LD_M);
                    latch_input(arrC6, 32);
                    delay(LD_M);
                    latch_input(arrC7, 32);
                    delay(LD_M);
                }
                else if (input == "D")
                {
                    latch_input(arrD, 32);
                    delay(LD_M);
                }
                else if (input == "E")
                {
                    latch_input(arrE, 32);
                    delay(LD_M);
                }
                // else if (input == "F")
                // {
                //     latch_input(arrF, 32);
                //     delay(LD_M);
                // }
                else if (input == "G")
                {
                    latch_input(arrG, 32);
                    delay(LD_M);
                }
                else if (input == "H")
                {
                    latch_input(arrH1, 32);
                    delay(LD_M);
                    latch_input(arrH2, 32);
                    delay(LD_M);
                    latch_input(arrH3, 32);
                    delay(LD_M);
                    latch_input(arrH4, 32);
                    delay(LD_M);
                    latch_input(arrH5, 32);
                    delay(LD_M);
                    latch_input(arrH6, 32);
                    delay(LD_M);
                    latch_input(arrH7, 32);
                    delay(LD_M);
                }
                else if (input == "I")
                {
                    latch_input(arrI, 32);
                    delay(LD_M);
                }
                else if (input == "J")
                {
                    latch_input(arrJ1, 32);
                    delay(LD_M);
                    latch_input(arrJ2, 32);
                    delay(LD_M);
                    latch_input(arrJ3, 32);
                    delay(LD_M);
                    latch_input(arrJ4, 32);
                    delay(LD_M);
                    latch_input(arrJ5, 32);
                    delay(LD_M);
                    latch_input(arrJ6, 32);
                    delay(LD_M);
                    latch_input(arrJ7, 32);
                    delay(LD_M);
                    latch_input(arrJ8, 32);
                    delay(LD_M);
                }
                else if (input == "K")
                {
                    latch_input(arrK, 32);
                    delay(LD_M);
                }
                else if (input == "L")
                {
                    latch_input(arrL, 32);
                    delay(LD_M);
                }
                else if (input == "M")
                {
                    latch_input(arrM, 32);
                    delay(LD_M);
                }
                else if (input == "N")
                {
                    latch_input(arrN, 32);
                    delay(LD_M);
                }
                else if (input == "O")
                {
                    latch_input(arrO, 32);
                    delay(LD_M);
                }
                else if (input == "P")
                {
                    latch_input(arrP, 32);
                    delay(LD_M);
                }
                else if (input == "Q")
                {
                    latch_input(arrQ, 32);
                    delay(LD_M);
                }
                else if (input == "R")
                {
                    latch_input(arrR, 32);
                    delay(LD_M);
                }
                else if (input == "S")
                {
                    latch_input(arrS, 32);
                    delay(LD_M);
                }
                else if (input == "T")
                {
                    latch_input(arrT, 32);
                    delay(LD_M);
                }
                else if (input == "U")
                {
                    latch_input(arrU, 32);
                    delay(LD_M);
                }
                else if (input == "V")
                {
                    latch_input(arrV, 32);
                    delay(LD_M);
                }
                else if (input == "W")
                {
                    latch_input(arrW, 32);
                    delay(LD_M);
                }
                else if (input == "X")
                {
                    latch_input(arrX, 32);
                    delay(LD_M);
                }
                else if (input == "Y")
                {
                    latch_input(arrY1, 32);
                    delay(LD_M);
                    latch_input(arrY2, 32);
                    delay(LD_M);
                    latch_input(arrY3, 32);
                    delay(LD_M);
                    latch_input(arrY4, 32);
                    delay(LD_M);
                }
                else if (input == "Z")
                {
                    latch_input(arrZ, 32);
                    delay(LD_M);
                }
            }
            else
            {
                latch_input(lowarr, 32);
                delay(LD_M);
            }
        }
    }

    // Delay before repeating the loop
    delay(100);
}
