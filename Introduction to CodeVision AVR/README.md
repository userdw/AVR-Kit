# Introduction to CodeVision AVR C Compiler
## Cara membuat proyek baru
### Tanpa CodeWizard AVR
1. Buka program CodeVision AVR pada *dekstop* dengan klik ganda icon (cvavr2 - Shortcut)
2. Pada menu **File** pilih **New**
<img src="/images/newfile.png" height="400">

3. Pada jendela *Create New File* pilih Project dan klik **OK**
<img src="/images/project.JPG" height="100">

4. Untuk membuat proyek baru tanpa bantuan CodeWizard AVR klik **No** pada jendela yang muncul berikutnya
<img src="/images/no wizard.JPG" height="100">

5. Setelah itu pilih direktori untuk menyimpan proyek yang akan dibuat, misalnya pada direktori '''D:\CobaAVR\''', kemudian isi nama proyek tersebut, sebagai contoh '''Tes.prj''' lalu klik **Save**
<img src="/images/save.JPG" height="300">

6. Pada jendela *Configure Project Tes.prj*, tab C Compiler, pilih mikrokontroler yang digunakan misalnya ATmega16A dan pilih frekuensi Clock (kristal) yang digunakan, misalnya 4 MHz. kemudian klik **OK** 
<img src="/images/configure.JPG" height="300">

Langkah pembuatan proyek baru selesai tetapi belum dapat digunakan untuk membuat program C. Agar dapat digunakan untuk membuat program C diperlukan pembuatan *file* c
7. Klik menu **File** pilih **New** kemudian pada jendela *Create New File* pilih **Source** dan klik **OK** . Akan terdapat *file* c dengan nama '''untitled.c'''. Pada menu **File** pilih **Save As** kemudian isi nama *file* c yang akan dibuat, sebagai contoh "Program1.c"

<img src="/images/source.JPG" height="100">
<img src="/images/file c.JPG" height="300">

8. Untuk menggabungkan '''Program1.c''' dengan proyek '''Tes.prj''' yaitu klik pada menu **project**, pilih **Configure**.
<img src="/images/project-configure.png" height="200">

9. Pada label *Files* pilih **Add**.
10. Kemudian pilih '''Program1.c''' dan klik **Open**. Program C tersebut ditambahkan ke dalam proyek '''Tes.prj''', klik **OK**
<img src="/images/add c.JPG" height="300">

### Dengan CodeWizard AVR
Selain membuat proyek baru dengan cara yang telah dibahas sebelum ini, ada cara lain yang lebih mudah dan cepat yaitu dengan menggunakan CodeWizard AVR.
Langkah-langkahnya sebagai berikut :
Pada menu **File** pilih **New** atau klik ikon <img src="/images/icon.JPG" height="30">, kemudian pada jendela *Create New File* pilih **Project** dan klik **OK**. Untuk membuat proyek baru dengan bantuan CodeWizard AVR klik **Yes**
