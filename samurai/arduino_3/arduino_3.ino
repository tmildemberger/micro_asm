int analogPin = 3;
int pwmOut = 11;
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pwmOut, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
  Serial.println(val);
  analogWrite(pwmOut, val/4);
  delay(40);
}
