/*
  Code for SLAVE, give dummy frame

  by 
  Anggara Wijaya (wj.anggara)
  wj.anggara@gmail.com
  https://www.facebook.com/wj.anggara
  https://github.com/wj-anggara
  https://www.instagram.com/wj.anggara/

*/

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char req = Serial.read();
    if (req == '1')
    {
      Serial.print("$INPUT,220.001,300.001,-0.999");
      Serial.print("\r\n");
    }
    else
    {
      return;
    }
  }
}
