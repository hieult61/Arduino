int measurePin = A0;              //Chân đọc giá trị
int ledPower = 10;                //Chân led IR

unsigned int samplingTime = 280;  //Thời gian chờ
unsigned int deltaTime = 40;
unsigned int sleepTime = 9680;

float voMeasured = 0;             //Giá trị thô (analog)
float calcVoltage = 0;            //Giá trị điện áp
float dustDensity = 0;            //Mật độ bụi

void setup()
{
  Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
}

void loop()
{
  digitalWrite(ledPower,LOW);           //Bật IR
  delayMicroseconds(samplingTime);      //Chờ

  voMeasured = analogRead(measurePin);  //Đọc giá trị vào

  delayMicroseconds(deltaTime);         //Chờ
  digitalWrite(ledPower,HIGH);          //Tắt IR
  delayMicroseconds(sleepTime);         //Chờ

  calcVoltage = voMeasured*(5.0/1024);  //Biến đổi sang dòng điện
  dustDensity = 0.17*calcVoltage-0.1;   //Biến đổi sang mật độ bụi

  if (dustDensity < 0)                
  {
    dustDensity = 0.00;
  }

  //Xuất ra Serial
  Serial.println("Giá trị thô (0-1023):");             
  Serial.println(voMeasured);

  Serial.println("Điện áp:");
  Serial.println(calcVoltage);

  Serial.println("Mật độ bụi:");
  Serial.println(dustDensity);

  Serial.println("------------");

  delay(1000);
}
