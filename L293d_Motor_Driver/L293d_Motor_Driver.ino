const int inputPin3  = 9;   // Pin  7 of L293D IC
const int inputPin4  = 8;   // Pin  2 of L293D IC


void setup()
{
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
}

void loop()
{
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW);  
}

//Input 1  Input 2 Result
//0 0 Stop
//0 1 Anti Clockwise
//1 0 Clockwise
//1 1 Stop
