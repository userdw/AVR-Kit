# DT-SENSE ULTRASONIC AND INFRARED RANGER
## PENDAHULUAN
DT-SENSE ULTRASONIC AND INFRARED RANGER merupakan modul pengukur jarak non-kontak yang sangat mudah dihubungkan dengan berbagai sistem berbasis mikrokontroler. Untuk memicu dan membaca data pengukuran dengan DT-SENSE ULTRASONIC AND INFRARED RANGER hanya memerlukan 1 buah pin mikrokontroler. Selain itu disediakan antarmuka komunikasi I2C sehingga beberapa modul DT-SENSE ULTRASONIC AND INFRARED RANGER serta peralatan lain yang mendukung protocol komunikasi I2C dapat digunakan bersama cukup dengan 2 buah pin mikrokontroler. 
Sebuah modul DT-SENSE ULTRASONIC AND INFRARED RANGER terdiri dari sebuah Ultrasonic Ranger dan dapat dihubungkan dengan 2 buah sensor Infrared Ranger (GP2D12). Ultrasonic Ranger berkerja dengan cara memancarkan sinyal ultrasonic (yang memiliki frekuensi jauh di atas jangkauan pendengaran manusia) dan menghasilkan pulsa atau data keluaran yang menyatakan jarak yang ditempuh oleh sinyal tersebut sebelum menyentuh sebuah obyek dan memantul kembali. Sensor infrared ranger terdiri dari sebuah LED infrared dan sebuah Position Sensing Device (PSD). Sensor mengukur jarak obyek yang memantulkan cahaya infra merah melalui proses triangulasi. Keluaran analog dari sensor Infrared Ranger diubah oleh modul DT-SENSE ULTRASONIC AND INFRARED RANGER menjadi berbentuk pulsa atau data keluaran yang menyatakan jarak obyek yang memantulkan cahaya infra merah tersebut. Contoh aplikasi dari DT-SENSE ULTRASONIC AND INFRARED RANGER adalah untuk robot cerdas, smart vehicle, pintu otomatis, sekuriti, dan lain sebagainya.
### SPESIFIKASI DT-SENSE ULTRASONIC AND INFRARED RANGER
Spesifikasi DT-SENSE ULTRASONIC AND INFRARED RANGER sebagai
berikut:
* Terdiri dari sebuah Ultrasonic Ranger dan dapat dihubungkan dengan 2
buah sensor Infrared Ranger GP2D12 (opsional).
* Memiliki 2 buah antarmuka yang dapat aktif bersama yaitu:
* Pulse Width / Lebar Pulsa (10 µs/mm)
* I2C-bus
* Dapat di-cascade hingga 8 modul dengan hanya 2 pin I/O (menggunakan
antarmuka I2C-bus).
* Single supply 5 VDC.
* Supply Current (tanpa sensor infrared ranger):
* Aktif: 17 mA typ.
* Reduced Operation: 13 mA typ.
* Power Down: 7 mA typ.
* Power Down + Reduced Operation: 2 mA typ.
* Siklus pengukuran yang cepat.
* Pembacaan dapat dilakukan tiap 25 ms (40 Hz rate).
* Spesifikasi Ultrasonic Ranger:
* Jangkauan: 2 cm hingga 3 m
* Obyek 0 – 2 cm diukur berjarak 2 cm
* Burst Frequency: 40 kHz – 16 VPP sinyal kotak
* Tidak ada dead zone (tidak ada blank spot antara 2 cm hingga 3 m)
* Jangkauan Infrared Ranger: 10 cm hingga 80 cm.
* Ketelitian Ranger: 5 mm.
* Input Trigger: pulsa negatif TTL, 20 µs min.
* Pin Busy/Ready menunjukkan aktifitas sensor.
* Tidak perlu delay sebelum pengukuran berikutnya.
* Output langsung berupa jarak (dalam milimeter) sehingga mengurangi
beban mikrokontroler.
* Kompensasi kesalahan pengukuran akibat perubahan temperatur sekitar
dan reflektifitas obyek dapat diatur.
### HUBUNGAN DT-SENSE ULTRASONIC AND INFRARED RANGER DENGAN GP2D12
J5 dan J6 berfungsi untuk menghubungkan modul sensor infrared ranger
GP2D12 ke modul DT-SENSE ULTRASONIC AND INFRARED RANGER.

<img src="/images/usirr 1.JPG" height="100">

### PERANGKAT LUNAK DT-SENSE ULTRASONIC AND INFRARED RANGER
Waktu yang dibutuhkan modul DT-SENSE ULTRASONIC AND INFRARED
RANGER mulai menyala hingga siap dioperasikan (Start-up Time) = 50 ms.
### SPESIFIKASI ANTARMUKA I2C-BUS
Frekuensi SCL maksimum untuk DT-SENSE ULTRASONIC AND
INFRARED RANGER adalah 65 kHz.
### MENCOBA DT-SENSE ULTRASONIC AND INFRARED RANGER
1.	Jalankan program monitor COMPort (mis: Terminal, Hyper Terminal, dsb.) dan atur pada baudrate 9600, 8 bit data, no parity, dan 1 stop bit. Kemudian jalankan koneksi !
2.	Atur setting selektor sehingga alamat terprogram I2C adalah 111 (lepas /seluruh jumper J3).
3.	Aktifkan pull-up I2C (pasang seluruh jumper J7 & J8).
4.	Hubungkan COM Port Komputer dengan DT-AVR Low Cost Micro System melalui UART RS-232.
5.	Upload Program USIRR.c ke DT-AVR Low Cost Micro System
6.	Hubungkan DT-AVR Low Cost Micro System dengan modul DT-Sense USIRR (yang akan diuji) dengan hubungan sebagai berikut:

<img src="/images/usirr 2.JPG" height="100">

7.	Atur posisi modul DT-Sense USIRR sehingga ujung sensor ultrasonic berada pada jarak 10 cm dari obyek (dinding, kardus, dsb).
8.	Tekan tombol “Reset” DT-AVR Low Cost Micro System.
9.	Pada monitor COMPort akan terkirim 4 kelompok data sebagai berikut:

I2C=0100  PUL=0100  IR1=XXXX  IR2=XXXX
OK

•	CATATAN: 
•	Nilai I2C dan PUL bukan merupakan nilai yang eksak (pasti bernilai 0100). Tetapi bisa berkisar antara 0950 – 0150.
•	Nilai IR1 dan IR2 tidak perlu diperhatikan (XXXX = abaikan).

10.	Hubungkan Sensor Infrared Ranger GP2D12 pada jumper J5 dengan koneksi sebagai berikut:

<img src="/images/usirr 3.JPG" height="100">

11.	Atur posisi Sensor Infrared Ranger GP2D12 sehingga ujung sensor berada pada jarak 10 cm dari obyek (dinding, kardus, dsb).
12.	Tekan tombol “Reset” DT-AVR Low Cost Micro System.
13.	Pada monitor COMPort akan terbaca 4 kelompok data sebagai berikut:

I2C=XXXX  PUL=XXXX  IR1=0100  IR2=XXXX
OK

•	CATATAN: 
•	Nilai IR1 bukan merupakan nilai yang eksak (pasti bernilai 0100). Tetapi bisa berkisar antara 0950 – 0150.
•	Nilai I2C, PUL dan IR2 tidak perlu diperhatikan (XXXX = abaikan).

14.	Hubungkan Sensor Infrared Ranger GP2D12 pada jumper J6 dengan koneksi sebagai berikut:

<img src="/images/usirr 4.JPG" height="100">

15.	Atur posisi Sensor Infrared Ranger GP2D12 sehingga ujung sensor berada pada jarak 10 cm dari obyek (dinding, kardus, dsb).
16.	Tekan tombol “Reset” DT-AVR Low Cost Micro System.
17.	Pada monitor COMPort akan terbaca 4 kelompok data sebagai berikut:

I2C=XXXX  PUL=XXXX  IR1=XXXX  IR2=0100
OK

•	CATATAN: 
•	Nilai IR2 bukan merupakan nilai yang eksak (pasti bernilai 0100). Tetapi bisa berkisar antara 0950 – 0150.
•	Nilai I2C, PUL dan IR1 tidak perlu diperhatikan (XXXX = abaikan).

18.	Pastikan bahwa kata terakhir yang muncul pada langkah 17 adalah OK. Jika tidak ada OK, tekan tombol “Reset” DT-AVR Low Cost Micro System beberapa kali hingga muncul OK (maksimal 3 kali).

19.	Ulangi mulai langkah 6 untuk modul yang lain.
