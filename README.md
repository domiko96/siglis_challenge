# SIGLIS NRF52840 Challenge Dominik Kogel

## Task
BLE Peripheral

### Server - Du schreibst eine kleine Firmware (Server) auf dem nRF5 SDK 17.0.2 für das Nordic nRF52840-DK.
* Diese legt einen eigenen BLE Service mit einem Characteristic offen (als BLE Peripheral Server)
* Das Characteristic ist beschreib- und lesbar.
* Das Characteristic ist fix in der Länge (uint8_t).
* Der Server sendet all 4 Sekunden ein BLE Advertisement (damit ein Client danach scannen kann)
* Beim Beschreiben des Characteristic durch einen BLE Client blinkt die Board-LED gemäss Fizzbuzz-Regeln mehrfach auf (300ms Periode, 50% On, 50% Off):
   ** 10-mal falls der Wert durch fünf und drei teilbar ist
   ** Oder 3-mal falls der Wert durch drei teilbar ist
   ** Oder 5-mal falls der Wert durch fünf teilbar ist
   ** Ansonsten nur 1-mal
   ** 0 ist auch teilbar
* Falls der Taster «Button 1» auf dem Development-Kit gedrückt wird, soll der Zahlenwert im Characteristic um 1 erhöht werden.
  ** Falls dieser bereits 255 ist, soll er auf 0 zurückgesetzt werden
  ** Die Board-LED soll hier entsprechend der vorgenannten Regeln aufblinken.
  ** Ein verbundener Client soll über den geänderten Wert benachrichtigt werden (BLE Notify)
  ** Es ist kein Pairing oder sonstige BLE Security notwendig

### BLE Client - Du schreibst einen kleinen Client für den Fizzbuzz (CLI, Browser, App oder Desktop). Die Programmierumgebung ist dir hier selber überlassen.
* Der Client nimmt automatisch Verbindung zum BLE Peripheral auf.
  Entsprechende Ausgaben auf die Konsole protokollieren den Verbindungsaufbau
  Falls kein Peripheral verbunden ist, die Verbindung getrennt wurde oder kein Peripheral gefunden werden kann, versucht der Client trotzdem weiterhin eine Verbindung aufzubauen
* Eine Werteeingabe erlaubt das Beschreiben des Characteristic sobald eine Verbindung besteht
  Der Client registriert sich für die BLE Notifications des Characteristic, um beim Pressen der Taste den aktuellen Wert auszugeben (z.B. durch Überschreiben des Texteingabefeldes, Konsolen-Ausgabe, etc.)

## Environment
* SDK was copied into folder ./server/SDK (the SDK is not in the repo! - so just copy it in or create a symlink)
