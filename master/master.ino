/*
  Code for MASTER, please see the srial frame on Code for SLAVE
  Simple serial parsing using pointer and read string function and fast reading. 
  Sample code useing arduino mega and using serial 0,1,&2. you can modify for your systems

  by 
  Anggara Wijaya (wj.anggara)
  wj.anggara@gmail.com
  https://www.facebook.com/wj.anggara
  https://github.com/wj-anggara
  https://www.instagram.com/wj.anggara/
*/

int ptr_in = 0;
char * pch_in;
String Header_in;
char str_buff_in[256];
float v_in, i_in, c_in;
String str_in;

int ptr_out = 0;
char * pch_out;
String Header_out;
char str_buff_out[256];
float v_out, i_out, c_out;
String str_out;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(115200);
  Serial2.begin(115200);
}

void loop()
{
  Scan();

  Serial.println(Header_in);
  Serial.println(v_in, 3);
  Serial.println(i_in, 3);
  Serial.println(c_in, 3);
  Serial.println();
  Serial.println(Header_out);
  Serial.println(v_out, 3);
  Serial.println(i_out, 3);
  Serial.println(c_out, 3);
  Serial.println();
}

void Scan()
{
  Serial1.println("1");
  Serial2.println("1");
  str_in = Serial1.readStringUntil('\n');
  str_out = Serial2.readStringUntil('\n');
  delay(1000);

  str_in.toCharArray(str_buff_in, str_in.length() + 1);
  pch_in = strtok (str_buff_in, ",");
  while (pch_in != NULL)
  {
    if (ptr_in == 0) Header_in  = pch_in;
    if (ptr_in == 1) v_in       = atof(pch_in);
    if (ptr_in == 2) i_in       = atof(pch_in);
    if (ptr_in == 3) c_in       = atof(pch_in);
    pch_in = strtok(NULL, ",");
    ptr_in++;
  }
  ptr_in = 0;

  str_out.toCharArray(str_buff_out, str_in.length() + 1);
  pch_out = strtok (str_buff_out, ",");
  while (pch_out != NULL)
  {
    if (ptr_out == 0) Header_out  = pch_out;
    if (ptr_out == 1) v_out       = atof(pch_out);
    if (ptr_out == 2) i_out       = atof(pch_out);
    if (ptr_out == 3) c_out       = atof(pch_out);
    pch_out = strtok(NULL, ",");
    ptr_out++;
  }
  ptr_out = 0;
}
