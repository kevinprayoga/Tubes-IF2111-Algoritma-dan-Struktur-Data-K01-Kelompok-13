<h1 align="center"> TUBES ALSTRUKDAT <h4 align="center">
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

> HANGMAN

> TOWER OF HANOI

> SNAKE ON METEOR

> Minesweeper

> Alstrokedungeon

## Directory

📦bin

    ┣📜Makefile
    ┗📜program.exe  
    
📦data

    ┣📜config.txt 
    ┣📜hangman.txt 
    ┗📜savefile.txt 
    
📦docs

    ┣📜IF2111_TB1_01_13.docx.pdf  
    ┗📜IF2111_TB2_01_13.docx.pdf  
    
📦src

    ┣📂ADT
    ┃ ┣📜arraydin.c
    ┃ ┣📜arraydin.h
    ┃ ┣📜driverarraydin.c
    ┃ ┣📜driverlistlinier.c
    ┃ ┣📜driverlistofmap.c
    ┃ ┣📜drivermesinfile.c
    ┃ ┣📜drivermesinkarkata.c
    ┃ ┣📜driverpoint.c
    ┃ ┣📜driverqueue_dinerdash.c
    ┃ ┣📜driverqueue.c
    ┃ ┣📜driverset.c
    ┃ ┣📜driverstack.c
    ┃ ┣📜driverstackTOH.c
    ┃ ┣📜dungeon_tree.c
    ┃ ┣📜dungeon_tree.h
    ┃ ┣📜listlinier.c
    ┃ ┣📜listlinier.h
    ┃ ┣📜listofmap.c
    ┃ ┣📜listofmap.h
    ┃ ┣📜mesinfile.c
    ┃ ┣📜mesinfile.h
    ┃ ┣📜mesinkar_dungeon.c
    ┃ ┣📜mesinkar_dungeon.h
    ┃ ┣📜mesinkar.c
    ┃ ┣📜mesinkar.h
    ┃ ┣📜mesinkata.c
    ┃ ┣📜mesinkata.h
    ┃ ┣📜point.c
    ┃ ┣📜point.h
    ┃ ┣📜queue_dinerdash.c
    ┃ ┣📜queue_dinerdash.h
    ┃ ┣📜queue.c
    ┃ ┣📜queue.h
    ┃ ┣📜set.c
    ┃ ┣📜set.h
    ┃ ┣📜stack.c
    ┃ ┣📜stack.h
    ┃ ┣📜stackTOH.c
    ┃ ┗📜stackTOH.h
    ┣📜boolean.c
    ┣📜boolean.h
    ┣📜console.c
    ┣📜console.h
    ┗📜main.c

📦README.MD

## How to Compile Driver ADT

Notes: Ubah CD ke folder bin

1. Driver arraydin

    gcc -o driverarraydin ../src/ADT/driverarraydin.c ../src/ADT/arraydin.c

2. Driver list linier

    gcc -o driverlistlinier ../src/ADT/driverlistlinier.c ../src/ADT/listlinier.c ../src/ADT/point.c ../src/boolean.c

3. driver list of map

    gcc -o driverlistofmap ../src/ADT/driverlistofmap.c ../src/ADT/arraydin.c ../src/ADT/mesinkar.c ../src/ADT/mesinkata.c ../src/ADT/mesinfile.c ../src/ADT/queue.c ../src/ADT/queue_dinerdash.c ../src/ADT/stack.c ../src/ADT/stackTOH.c ../src/ADT/listofmap.c ../src/ADT/set.c ../src/ADT/listlinier.c ../src/ADT/point.c ../src/console.c ../src/GAME/gameRNG.c ../src/GAME/dinerdash.c ../src/GAME/minesweeper.c ../src/GAME/towerofhanoi.c ../src/GAME/hangmanset.c ../src/GAME/asciihangman.c ../src/GAME/snake.c ../src/boolean.c

4. driver mesin file

    gcc -o drivermesinfile ../src/ADT/drivermesinfile.c ../src/ADT/arraydin.c ../src/ADT/mesinkar.c ../src/ADT/mesinkata.c ../src/ADT/mesinfile.c ../src/ADT/queue.c ../src/ADT/queue_dinerdash.c ../src/ADT/stack.c ../src/ADT/stackTOH.c ../src/ADT/listofmap.c ../src/ADT/set.c ../src/ADT/listlinier.c ../src/ADT/point.c ../src/console.c ../src/GAME/gameRNG.c ../src/GAME/dinerdash.c ../src/GAME/minesweeper.c ../src/GAME/towerofhanoi.c ../src/GAME/hangmanset.c ../src/GAME/asciihangman.c ../src/GAME/snake.c ../src/boolean.c

5. driver mesin kar kata

    gcc -o drivermesinkarkata ../src/ADT/drivermesinkarkata.c ../src/ADT/mesinkar.c ../src/ADT/mesinkata.c ../src/boolean.c

6. driver point

    gcc -o point ../src/ADT/driverpoint.c ../src/ADT/point.c ../src/boolean.c

7. driver queue_dinerdash

    gcc -o driverqueuediner ../src/ADT/queue_dinerdash.c ../src/ADT/driverqueue_dinerdash.c ../src/ADT/mesinkar.c ../src/ADT/mesinkata.c ../src/boolean.c

8. driver queue

    gcc -o driverqueue ../src/ADT/driverqueue.c ../src/ADT/queue.c

9. driver set

    gcc -o driverset ../src/ADT/driverset.c ../src/ADT/set.c ../src/boolean.c

10. driver stack

    gcc -o driverstack ../src/ADT/driverstack.c ../src/ADT/stack.c ../src/boolean.c

11. driver stackTOH

    gcc -o driverstackTOH ../src/ADT/driverstackTOH.c ../src/ADT/stackTOH.c ../src/boolean.c

## How to Play in Windows

1. Go to folder bin
2. Open cmd with directory is bin
3. compile this:

    gcc -o program ../src/main.c ../src/ADT/arraydin.c ../src/ADT/mesinkar.c ../src/ADT/mesinkata.c ../src/ADT/mesinfile.c ../src/ADT/queue.c ../src/ADT/queue_dinerdash.c ../src/ADT/stack.c ../src/ADT/stackTOH.c ../src/ADT/listofmap.c ../src/ADT/set.c ../src/ADT/listlinier.c ../src/ADT/point.c ../src/console.c ../src/GAME/gameRNG.c ../src/GAME/dinerdash.c ../src/GAME/minesweeper.c ../src/GAME/towerofhanoi.c ../src/GAME/hangmanset.c ../src/GAME/asciihangman.c ../src/GAME/snake.c ../src/boolean.c

2. Double Click program.exe
3. Enjoy your game :)))
