#define ON LOW
#define OFF HIGH
#define traffic_light_top_green A0
#define traffic_light_red A1
#define traffic_light_bottom_green A2
#define traffic_light_yellow_friend A3

#define red1 10
#define red2 11
#define red3 12
#define red4 13

#define wait_time 500


void setup()
{
pinMode(traffic_light_top_green, OUTPUT);
pinMode(traffic_light_red, OUTPUT);
pinMode(traffic_light_bottom_green, OUTPUT);
pinMode(traffic_light_yellow_friend, OUTPUT);
pinMode(red1, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(red3, OUTPUT);
pinMode(red4, OUTPUT);

}

void loop()
{
digitalWrite(red1, ON); delay(wait_time);
digitalWrite(red2, ON); delay(wait_time);
digitalWrite(red3, ON); delay(wait_time);
digitalWrite(red4, ON); delay(wait_time);

digitalWrite(red1, OFF); delay(wait_time);
digitalWrite(red2, OFF); delay(wait_time);
digitalWrite(red3, OFF); delay(wait_time);
digitalWrite(red4, OFF); delay(wait_time);

digitalWrite(traffic_light_top_green, ON); delay(wait_time);
digitalWrite(traffic_light_red, ON); delay(wait_time);
digitalWrite(traffic_light_bottom_green, ON); delay(wait_time);
digitalWrite(traffic_light_yellow_friend, ON); delay(wait_time);

digitalWrite(traffic_light_top_green, OFF); delay(wait_time);
digitalWrite(traffic_light_red, OFF); delay(wait_time);
digitalWrite(traffic_light_bottom_green, OFF); delay(wait_time);
digitalWrite(traffic_light_yellow_friend, OFF); delay(wait_time);

}
