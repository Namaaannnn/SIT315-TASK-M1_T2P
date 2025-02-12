#define PIR 2
#define LED_PIN 5

int input = 0;
volatile bool LEDstate = false;

ISR(INT0_vect)
{
  PORTD ^= (1 << LED_PIN);
  
  Serial.println("Interrupt has occured");
  puts("Interrupt has occured");
}

void setup() {
  Serial.begin(9600);
  Serial.println("Program Running...");
  puts("Program Running...");
  
  DDRD |= (1 << LED_PIN);
  DDRD &= ~(1 << PIR);

  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);

  EIMSK |= (1 << INT0);
  sei();
}

void loop() {
  delay(1000);
}
