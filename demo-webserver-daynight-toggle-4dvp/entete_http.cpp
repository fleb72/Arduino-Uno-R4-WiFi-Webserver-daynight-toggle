#include <WiFiS3.h>

void entete_http_200(WiFiClient *client, const __FlashStringHelper *contentType) {
  client->println(F("HTTP/1.1 200 OK"));
  client->print(F("Content-Type: "));
  client->println(contentType);
  client->println(F("Connection: close"));
  client->println();
}

void entete_http_204(WiFiClient *client) {
  client->println(F("HTTP/1.1 204 No Content"));
  client->println();
}