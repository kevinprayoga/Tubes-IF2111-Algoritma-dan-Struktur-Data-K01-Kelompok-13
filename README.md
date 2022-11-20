<h1 align="center"> Tubes Alstrukdat <h4 align="center">
K01_Kelompok 13 <h4> <h1>

## Deskripsi

<p align="justify"> Sekumpulan mahasiswa Sistem dan Teknologi Informasi mencoba memperbaiki game console yang bernama BNMO untuk membantu Indra dan Doni memperbaiki banyak bug dalam sistemnya, sehingga kami berlima mencoba membuat sistem menu dalam bahasa C. Main menu menggunakan berbagai fungsi untuk menjalankannya, seperti START dan LOAD [filename] pada menu utama, SAVE [filename], CREATE GAME, LIST GAME, DELETE GAME, QUEUE GAME, PLAY GAME, SKIP GAME [n], QUIT, HELP, dan COMMAND LAIN. Selain itu terdapat game yang dibuat oleh kami yaitu RNG, Diner DASH, dan Minesweeper. Program BNMO memanfaatkan berbagai struktur data arraydinamik, mesin karakter & mesin kata, queue, dan struktur data baru yang dibuat demi memenuhi kebutuhan program dalam permainan. <p>

## Anggota

> Muhammad Naufal - 18221089

> Ibnu Khairy Algifari - 18221091

> Christopher Febrian Nugraha - 18221115

> Natasya Vercelly Harijadi - 18221119

> Kevin Prayoga Abdinegara - 18221141

## Alur Program

<p align="justify"> Program dimulai dengan meminta pilih menu START atau LOAD [filename]. Jika kita memulai dengan START, maka program akan memulai dengan membaca isi file dari config.txt (default). Kalau memilih LOAD [filename], maka akan membaca file yang kita ketik. Setelah itu akan masuk ke menu program. Didalamnya terdapat fungsi SAVE [filename] (untuk menyimpan file dengan isi data dari LIST GAME yang kita punya), CREATE GAME (membuat game dan dimasukkan ke dalam LIST GAME yang dimiliki), LIST GAME (menampilkan game apa saja yang dimiliki oleh kita), DELETE GAME (menghapus game yang kita pilih berdasarkan nomor, akan tetapi tidak bisa menghapus game dari urutan satu sampai enam dan game yang terdapat di QUEUE GAME), QUEUE GAME (membuat antrian dengan memilih nomor game yang akan di queue agar game dapat dimainkan), PLAY GAME (untuk memainkan game yang berada pada urutan atas, dan menghapus antrian game tersebut. Jika game yang dimainkan berupa RNG, Diner DASH, dan Minesweeper, maka game dapat dimainkan. Selain game tersebut, game berada dalam fase maintenance), SKIP GAME [n] (game akan dilewati sebanyak n, jika masih tersisa game di queue maka PLAY GAME, kalau sudah tidak ada maka tidak dapat dimainkan), QUIT (keluar dari program dan program akan bertanya apakah ingin di save atau tidak, setelah itu program selesai), HELP (memberikan beberapa komentar bantuan command apa saja yang dimiliki oleh program), COMMAND LAIN (jika kita mengetik command diluar dari ketentuan yang ada, maka program akan meminta command kembali). <p>

## GAME READY

> RNG

> Diner DASH

> Minesweeper

## Directory

📦README.MD 

📦.vscode 

📦bin

    ┣📜Makefile
    ┗📜program.exe  
    
📦data

    ┗📜config.txt 
    
📦docs

    ┣📜IF2111_Form Asistensi TB01_01_13.docx.pdf
    ┗📜IF2111_TB1_01_13.docx.pdf  
    
📦src

    ┣📜asciiart.c
    ┣📜asciiart.h
    ┣📜boolean.h
    ┣📜commandlain.c
    ┣📜commandlain.h
    ┣📜creategame.c
    ┣📜creategame.h
    ┣📜deletegame.c
    ┣📜deletegame.h
    ┣📜dinerdash.c
    ┣📜dinerdash.h
    ┣📜function.c
    ┣📜function.h
    ┣📜gameRNG.c
    ┣📜gameRNG.h
    ┣📜help.c
    ┣📜help.h
    ┣📜listgame.c
    ┣📜listgame.h
    ┣📜main.c
    ┣📜minesweeper.c
    ┣📜minesweeper.h
    ┣📜playgame.c
    ┣📜playgame.h
    ┣📜queuegame.c
    ┣📜queuegame.h
    ┣📜quit.c
    ┣📜quit.h
    ┣📜save.c
    ┣📜save.h
    ┣📜skipgame.c
    ┣📜skipgame.h
    ┣📜startload.c
    ┣📜startload.h
    ┗📂ADT
     ┃ ┣📜arraydin.c
     ┃ ┣📜arraydin.h
     ┃ ┣📜driverarraydin.c
     ┃ ┣📜drivermesinfile.c
     ┃ ┣📜drivermesinkarkata.c
     ┃ ┣📜driverqueue_dinerdash.c
     ┃ ┣📜driverqueue.c
     ┃ ┣📜mesinfile.c
     ┃ ┣📜mesinfile.h
     ┃ ┣📜mesinkar.c
     ┃ ┣📜mesinkar.h
     ┃ ┣📜mesinkata.c
     ┃ ┣📜mesinkata.h
     ┃ ┣📜queue_dinerdash.c
     ┃ ┣📜queue_dinerdash.h
     ┃ ┣📜queue.c
     ┗ ┗📜queue.h

## How to Play

1. Go to folder bin
2. Double Click program file
3. Enjoy your game :)))
