#ifndef ENTETE_HTTP_H
#define ENTETE_HTTP_H

  #include <WiFiS3.h>
  void entete_http_200(WiFiClient *client, const __FlashStringHelper* contentType);
  void entete_http_204(WiFiClient *client);
  
#endif
