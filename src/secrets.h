#include <pgmspace.h>

#define SECRET

const char ssid[] = "redewifi";
const char pass[] = "senha";

#define THINGNAME "thing id"

int8_t TIME_ZONE = -3;
//#define USE_SUMMER_TIME_DST  // descomente se voce estiver em horario de verãonce

const char MQTT_HOST[] = "eugenioprod-iothub.azure-devices.net";
const char MQTT_USER[] = "eugenioprod-iothub.azure-devices.net/" THINGNAME "/api-version=2017-06-30";
const int MQTT_PORT = 8883;
const char MQTT_SUB_TOPIC[] = "$iothub/methods/POST/#";
const char MQTT_PUB_TOPIC[] = "devices/" THINGNAME "/messages/events/";


// Copie aqui o seu certificado CA do EUGENIO (ex: CAxxxxx.pem) ▼
static const char cacert[] PROGMEM = "certificado CA";


// Copie aqui o seu certificar do cliente do EUGENIO (ex: xxxxx.pem) ▼
static const char client_cert[] PROGMEM = "certificado cliente";

// Copie aqui a sua chave privada do certificado do cleinte do EUGENIO (ex: xxxxx.key.pem) ▼
static const char privkey[] PROGMEM = "chave provada cliente";
