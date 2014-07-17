const int EchoPin = 2; // Ultrasonic signal input
const int TrigPin = 3; // Ultrasonic signal output
const int leftmotorpin1 = 8; //signal output of DC geared motor const int leftmotorpin2 = 9;
const int rightmotorpin1 = 6;
const int rightmotorpin2 = 7;
int currDist = 0; // distance
void setup() {
pinMode(EchoPin, INPUT);
for (int pinindex = 3; pinindex < 8; pinindex++) {
pinMode(pinindex, OUTPUT); // set pins 3 to 10 as outputs }
}
void loop() {
currDist = MeasuringDistance(); //measure front distance
if(currDist >20) { nodanger();
}
else if(currDist <10){
backup();
randTrun(); }
else { //whichway(); randTrun();
} }
//measure distance, unit:cm long MeasuringDistance() {
long duration; //pinMode(TrigPin, OUTPUT); digitalWrite(TrigPin, LOW); delayMicroseconds(2); digitalWrite(TrigPin, HIGH); delayMicroseconds(10); digitalWrite(TrigPin, LOW);
//pinMode(EchoPin, INPUT); duration = pulseIn(EchoPin, HIGH);
return duration / 29 / 2; }
// forward
void nodanger() {
digitalWrite(leftmotorpin1, HIGH); digitalWrite(leftmotorpin2, LOW); digitalWrite(rightmotorpin1, HIGH); digitalWrite(rightmotorpin2, LOW); delay(1000);
return; }
//backward void backup() {
digitalWrite(leftmotorpin1, LOW); digitalWrite(leftmotorpin2, HIGH); digitalWrite(rightmotorpin1, LOW); digitalWrite(rightmotorpin2, HIGH); delay(500);
}
void totalhalt() { digitalWrite(leftmotorpin1, HIGH); digitalWrite(leftmotorpin2, HIGH); digitalWrite(rightmotorpin1, HIGH); digitalWrite(rightmotorpin2, HIGH); return;
delay(500);
}
//turn left
void body_lturn() {
digitalWrite(leftmotorpin1, LOW); digitalWrite(leftmotorpin2, HIGH); digitalWrite(rightmotorpin1, HIGH); digitalWrite(rightmotorpin2, LOW); delay(500);
totalhalt(); }
//turn right
void body_rturn() {
digitalWrite(leftmotorpin1, HIGH); digitalWrite(leftmotorpin2, LOW); digitalWrite(rightmotorpin1, LOW); digitalWrite(rightmotorpin2, HIGH); delay(500);
totalhalt(); }
void randTrun(){
long randNumber; randomSeed(analogRead(0)); randNumber = random(0, 10); if(randNumber > 5) {
body_rturn(); }
else {
body_lturn(); }
}
