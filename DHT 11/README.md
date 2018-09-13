# DHT-11 Sensor Suhu dan Kelembaban
Sensor DHT 11 merupakan sensor suhu dan kelembaban versi Low Cost
Spesifikasi :
Supply voltage : ± 5 VDC
Temperature range : 0 – 50˚ C error of ± 2˚ C
Humidity : 20 – 90% RH ± 5% RH error
Interface : Digital
Data bus sensor ini bukan TWI / I2C melainkan bus tersendiri dimana nilai 1 & 0 dibedakan melalui LEBAR PULSA HIGH
Berikut cara penggunaannya menggunakan DT-AVR Low Cost Micro System :
1.	Hubungkan Sensor DHT 11 dengan DT-AVR Low Cost Micro System seperti dibawah ini

<img src="/images/dht11.JPG" height="100">

2.	Hubungkan kabel serial ke port usb komputer
3.	Hubungkan DT-HiQ AVR USB ISP mkII ke Port ISP DT-AVR Low Cost Micro System dan kabel data USB ke komputer
4.	Upload program dht11.c ke DT-AVR Low Cost Micro System
5.	Jalankan program monitor COMPort (eg. Terminal, Hypertermina, hterm, dsb) dan atur pada baudrate 9600, 8 bit data, no parity, dan 1 stop bit. 
6.	Jalankan koneksi
7.	Data yang ditampilkan adalah data kelembaban lalu diikuti data temperature dengan format berikut:
Hum = XX RH, Tem = XX C
