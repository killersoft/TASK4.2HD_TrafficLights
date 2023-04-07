const pin_t GREEN_LED = D2; //Use pin 2 for Green LED
const pin_t ORANGE_LED = D3; //Use pin 3 for Orange LED
const pin_t RED_LED = D4;  //Use pin 4 for Red LED

// The following line is optional, but recommended in most firmware.
// It allows your code to run before the cloud is connected.
SYSTEM_THREAD(ENABLED);

void setup()
{
    // register the cloud function
    Particle.function("TheLights", TrafficLights); //Register the traffic lights cloud function
    pinMode(GREEN_LED, OUTPUT); // Config the PIN for output
    pinMode(ORANGE_LED, OUTPUT); // Config the PIN for output
    pinMode(RED_LED, OUTPUT); // Config the PIN for output
}

// this function automagically gets called upon a matching POST request
int TrafficLights(String command)
{
    digitalWrite(GREEN_LED, LOW); //TURN OFF LED
    digitalWrite(ORANGE_LED, LOW);//TURN OFF LED
    digitalWrite(RED_LED, LOW);//TURN OFF LED

    if(command == "red")
    {
        digitalWrite(RED_LED, HIGH); //TURN ON RED LED
        return 1;
    }
    if(command == "orange")
    {
        digitalWrite(ORANGE_LED, HIGH);//TURN ON ORANGE LED
        return 1;
    }
    if(command == "green")
    {
        digitalWrite(GREEN_LED, HIGH); //TURN ON GREEN LED
        return 1;
    }
    if(command == "off")
    {
        //Dont need anything here
        return 1;
    }
  else return -1; // FAILED or NOT a spectifed color
}


void loop() 
{
// Dont need anything in here as we are waiting on function callbacks
}
