# [Arduino Uno R4 WiFi] Webserver day/night toggle

Notes :
- ouvrir le fichier .ino dans l'EDI Arduino (version 2.2.1 pour ma part) ;
- renseignez l'identifiant SSID/mot de passe de votre box/routeur dans l'onglet du fichier arduino_secrets.h ;
- l'adresse IP prise par le serveur s'affiche dans le Terminal Série (115200 bauds), faire éventuellement un Reset de la carte après téléversement ;
- CSS de la checkbox (fichier css.h) : Licence MIT, Copyright (c) 2023 Josetxu (https://codepen.io/josetxu/pen/Poxwpme)
- pour cette démo, je suis simplement parti sur les bases de l'exemple fourni par Arduino : https://github.com/arduino/ArduinoCore-renesas/tree/main/libraries/WiFiS3/examples/WiFiWebServer ;
- bibliothèque supplémentaire à installer : SafeString (https://www.arduino.cc/reference/en/libraries/safestring/) ;
- sans système de fichiers, les codes statiques HTML/CSS/JavaScript sont stockés dans des const char*, voir index.h, css.h et javascript.h ;
