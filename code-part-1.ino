#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Definir o tipo do sensor DHT e o pino de leitura
#define DHTPIN D4
#define DHTTYPE DHT11

// Inicializar o objeto DHT
DHT dht(DHTPIN, DHTTYPE);

// Inicializar o objeto do display LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Inicializar o monitor serial
  Serial.begin(9600);

  // Inicializar o objeto DHT
  dht.begin();

  // Inicializar o objeto do display LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Ler a umidade do sensor DHT
  float humidity = dht.readHumidity();

  // Ler a temperatura do sensor DHT
  float temperature = dht.readTemperature();

  // Verificar se ocorreu algum erro na leitura do sensor DHT
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Erro ao ler o sensor DHT!");
    return;
  }

  // Mostrar os valores lidos no monitor serial
  Serial.print("Umid.: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temp.: ");
  Serial.print(temperature);
  Serial.println("C");

  // Mostrar os valores lidos no display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umid.: ");
  lcd.print(humidity);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp.: ");
  lcd.print(temperature);
  lcd.print("C");
  
  // Aguardar 2 segundos antes de fazer uma nova leitura
  delay(2000);
}
