#include "OurSpark.h"
#include <IRremote.h>
#include <Servo.h>    // 声明调用Servo.h库
Servo myservo;        // 创建一个舵机对象
int recvPin = 4;//定义红外接收器的引脚为3
IRrecv irrecv(recvPin);
decode_results results;
int pos = 0;          // 变量pos用来存储舵机位置
long KEY_CODE_A = 0x1FE807F;
long KEY_CODE_B = 0x1FE40BF;
long KEY_CODE_C=0x1FEC03F;

ColorLEDController LEDController1(2, 8);  //第一个2表示最大级联ColorLED个数，第二个6表示使用D6口。

void setup() {
  myservo.attach(6);
  irrecv.enableIRIn(); // 初始化红外接收器
  Serial.begin(9600);


}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);//以16进制换行输出接收代码
    Serial.println();//为了便于观看输出结果增加一个空行
    irrecv.resume(); // 接收下一个值
  }

  //按下１键的事件
  if (results.value == KEY_CODE_A ) {
       
      for(pos = 0; pos < 180; pos += 1){    // 舵机从0°转到180°，每次增加1°          
      myservo.write(pos);           // 给舵机写入角度   
      delay(15);                    // 延时15ms让舵机转到指定位置
   }
    
      
   }
  if (results.value == KEY_CODE_B ) {
       
 LEDController1.ShowColor(0,255,250,205); //第一个参数表示点亮0号灯，让其显示红光
  delay(1000);  //延迟1秒输出

    } 
  if (results.value == KEY_CODE_C ) {
       
 LEDController1.ShowColor(0,0,0,0);
  delay(1000);  //延迟1秒输出    
      
   }
}
