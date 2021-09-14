# Solar-power-monitoring
The fundamental objective of the project is to build an IOT based solar power monitoring
system.ACS 712-20A current sensor is used to sense currrent through the solarcell and voltage
is directly measured because it is lower than 5V but we can use a voltage divider for greater
voltages. Captured data is sent to the server utilizing Wi-Fi in Json format with the help
ofNodeMCU ESP8266.Blynk application is used to view the voltage,current and power to
the user and alert if the power falls below a certain level.
