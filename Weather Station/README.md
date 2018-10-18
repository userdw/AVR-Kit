# DHT-11 Sensor Suhu dan Kelembaban
Sensor DHT 11 merupakan sensor suhu dan kelembaban versi Low Cost

Spesifikasi :
* Supply voltage : ± 5 VDC
* Temperature range : 0 – 50˚ C error of ± 2˚ C
* Humidity : 20 – 90% RH ± 5% RH error
* Interface : Digital

Data bus sensor ini bukan TWI / I2C melainkan bus tersendiri dimana nilai 1 & 0 dibedakan melalui LEBAR PULSA HIGH
Berikut cara penggunaannya menggunakan Mikrokontroller ATmega16A :
1.	Hubungkan Sensor DHT 11 dengan Mikrokontroller ATmega16A seperti dibawah ini

<img src="/images/dht11.JPG" height="200">

2.	Hubungkan kabel serial ke port usb komputer
3.	Upload program ```dht11.c``` ke Mikrokontroller ATmega16A
4.	Jalankan program monitor COMPort (eg. Terminal, Hyperterminal, hterm, dsb) dan atur pada baudrate 9600, 8 bit data, no parity, dan 1 stop bit. 
5.	Jalankan koneksi
6.	Data yang ditampilkan adalah data kelembaban lalu diikuti data temperature dari sensor DHT 11 dengan format berikut:
**Hum = XX RH, Tem = XX C**
