#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "alstrokedungeon.h"
#include "dungeongame.h"
#include "function.h"
#include "boolean.h"

Tree create_map(int level, int difficulty){
	/*
	 * Menginisialisasi map dungeon
	 * input jumlah level (kedalaman dungeon), dan kesulitan dungeon
	 * output berupa map dungeon yang siap dimainkan
	 */
	int i, d;
	srand(time(0));

    Tree p;
    Address l, m, r;
	ListOfNode arrLevel[level];
	if(rand() % 100 < difficulty * 10){
    	l = newNode(0);
	}
    if(rand() % 100 < difficulty * 10){
    	m = newNode(0);
	}
	if(rand() % 100 < difficulty * 10){
       	r = newNode(0);
	}
    p = createTree(0, l, m, r, level, difficulty);

	for(int i = 1; i <= level; i++){
		makeListLevel(&(arrLevel[i-1]), &p, i);
	}
	addr loc;
	for(int i = 0; i < level; i++){
		loc = arrLevel[i];
		while(loc != Nil){
			Info(Elmt(loc)) = rand() % difficulty;
			loc = Next(loc);
		}
	}
	return p;
}

void startArt(char* filename){
    pita = fopen(filename, "r");
    ADV();
}

void printArt(char* filename){
	startArt(filename);
	while(currentChar != 'n'){
		printf("%c", currentChar);
		ADV();
	}
	fclose(filename, "r");
}

void print_dungeon(Tree *p){
	/*
	 * Menampilkan peta dungeon ke layar
	 * input berupa tree tidak kosong
	 */
	switch(*p)
		case isOneElmt(*p):
			printArt("portal.txt");
			printf("Kamu melihat sebuah portal bersinar terang di ujung jalan... Apakah kamu ingin memasuki portal ini?");
			break;
		case isNoneLeft(*p) && isNoneMid(*p):
			printArt("R.txt");
			printf("Ruangan ini... hanya memiliki pintu ke kanan.");
			break;
		case isNoneLeft(*p) && isNoneRight(*p):
			printArt("M.txt");
			printf("Ruangan yang kamu masuki hanya memiliki pintu ke depan.");
			break;
		case isNoneMid(*p) && isNoneRight(*p):
			printArt("L.txt");
			printf("Ruangan ini... ternyata hanya memiliki pintu ke kiri.");
			break;
		case isNoneLeft(*p):
			printArt("MR.txt");
			printf("Ruangan ini memiliki 2 pintu, satu ke tengah dan satu ke kanan...");
			break;
		case isNoneMid(*p):
			printArt("LR.txt");
			printf("Setelah melihat sekeliling, kamu melihat 2 pintu... satu ke kiri dan satu ke kanan.");
			break;
		case isNoneRight(*p):
			printArt("LM.txt");
			printf("Ruangan yang kamu masuki ternyata memiliki 2 pintu, satu ke kiri dan satu ke depan.");
			break;
		case isTerner(*p):
			printArt("LMR.txt");
			printf("Ruangan ini memiliki 3 pintu; ke kiri, ke tengah, dan ke kanan...");
			break;
}

void intro(boolean skip){
	if(!skip){
		printArt("vandun.txt");
		printf("\n\nKamu adalah seorang petualang yang sedang singgah di Kota Vandun.");
		sleep(1000);
		printf("\nSebagai seorang petualang, kamu sering berkelana mencari harta dan juga bekerja serabutan.");
		sleep(1000);
		printf("\nTentu saja, para petualang juga bisa mencari pekerjaan atau quest dengan menyambangi guild.");
		sleep(1000);
		printf("\nGuild setiap kota berbeda-beda, tapi yang pasti adalah mereka selalu menyambut petualang dengan baik.");
		sleep(1000);
		printf("\n\n...Sebelum memulai hari, kamu memesan ayam Takol yang terkenal enak dan murah.");
		sleep(1000);
		printf("\n\"Ah! Makanan di kota ini sungguh enak!\" Ucapmu setelah menghabiskan makananmu.");
		sleep(1000);
		printf("\nKetika kamu memasuki guild, kamu melihat ada orang berkerumun. Rupanya ada quest menarik yang diincar banyak orang.");
		sleep(1000);
		printf("\nQuest ini membutuhkan dua orang untuk menjelajahi sebuah dungeon yang terkenal angker.");
		sleep(1000);
		printf("\n\nDungeon ini disebut... Al-Stroke Dungeon. Tidak ada yang tahu asal usul nama dungeon ini.");
		sleep(1000);
		printf("\nAda yang bilang, bahwa nama tersebut berisi kutukan. Sementara yang lain menganggap nama itu menandakan harta.");
		sleep(1000);
		printf("\n\"Hmm, perlu dua orang ya...\" pikirmu. Kamu jelas ingin memasuki dungeon ini, tapi siapa yang bisa menjadi pendampingmu?");
		sleep(1000);
		printf("\nOrang-orang hanya ramai membicarakan dungeon ini, tapi tidak ada yang berani memasukinya.");
		sleep(1000);
		printf("\nKamu lekas mengambil kertas pengumuman quest, menandakan kamu bersedia melaksanakannya.");
		sleep(1000);
		printf("\n\nNamun, sayangnya otakmu baru berpikir lurus setelah kamu melihat kerumunan orang itu bubar.");
		sleep(1000);
		printf("\n\"Ah, aku perlu satu orang lagi ya...\" Ucapmu perlahan. Semua orang kembali ke urusannya masing-masing.");
		sleep(1000);
		printf("\nKecuali... tiga orang wanita yang menghampirimu.");
		sleep(1000);
		printf("\n\n\"Oi, kamu mau masuk ke dungeon itu tapi belum ada teman? Ajak aku.\" Ucap wanita dengan rambut putih.");
		sleep(1000);
		printf("\n\n\"Apa maksudmu? Tentu saja aku yang akan dia pilih! Lihat pedangku!\" Ucap wanita dengan rambut hijau.");
		sleep(1000);
		printf("\n\n\"Bawa aku... Aku bisa membantumu lebih baik dari dua serangga ini.\" Ucap wanita dengan rambut hitam.");
		sleep(1000);
		printf("\n\nKamu memang memerlukan bantuan salah satu dari mereka. Dungeon ini harus dimasuki oleh tim dua orang.");
		sleep(1000);
		printf("\nLagipula, mereka semua terlihat seperti wanita yang memiliki kekuatan untuk membantumu di dungeon.\n");
		sleep(1000);
		system("cls");
		printf("\nPertanyaannya adalah... siapakah yang akan kamu pilih?");
		sleep(2000);
		system("cls");
	}
}

int playdungeon(){
	int seed_lvl = undef, seed_diff = undef;
	char d_comm;
	char chosen;
	boolean finish = false;
	boolean skip = false;
	boolean error = true;

	system("cls");
	printArt("title.txt");
	printf("\nSelamat datang di game dungeon ini. Petualangan menarik menanti, namun kematian selalu mengikutimu...");
	printf("\nDungeon ini memiliki banyak harta karun untuk ditemukan, namun pilihlah jalur petualanganmu dengan bijak.");
	printf("\nKamu tidak bisa kembali ke ruangan yang telah kamu jelajahi, dan setiap ruangan memiliki rahasia tersendiri...");
	printf("\nPress ENTER key to start...");
	fgetchar();
	
	while(seed_lvl == undef || seed_diff == undef){ //memilih level dan difficulty disini
		printf("\nSeberapa dalamkah dungeon ini..? (3 <= depth <= 8)\n");
		STARTWORD();
		if (currentWord.TabWord[0] && wordToInt(currentWord) >= 3 && wordToInt(currentWord) <= 8 && isNum(wordToString(currentWord)))
		{
			seed_lvl= wordToInt(currentWord);
		}
		else
		{
			error = true;
		}
		printf("\nSeberapa sulitkah dungeon ini..? (1-2 mudah, 3-4 sedang, >=5 sulit)\n");
		STARTWORD();
		if (currentWord.TabWord[0] && wordToInt(currentWord) >= 1 && isNum(wordToString(currentWord)))
		{
			seed_diff= wordToInt(currentWord);
		}
		else
		{
			error = true;
		}
		if (error)
		{
			printf("Input Anda salah, coba lagi.\n");
			error = false;
			currentWord.TabWord[0] = undef;
			printf("\nPress ENTER key to back...");
			fgetchar();
		}
	}

	Tree p = create_map(seed_lvl, seed_diff);
	Tree loc = p;

	system("cls");
	error = true;
	while(error){
		printf("Apakah Anda mau menonton intro? (y/n)\n");
		STARTWORD();
		if(currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'n' || currentWord.TabWord[0] == 'N'){
			if(currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'Y'){
				skip = true;
			}
			error = false;
		}
		if(error){
			printf("Input Anda salah, coba lagi.\n");
			currentWord.TabWord[0] = undef;
			printf("\nPress ENTER key to back...");
			fgetchar();
		}
	}

	intro(skip);

	error = true;
	while(error){ //memilih pendamping disini
		system("cls");
		printf("\nPilih salah satu!\n");
		printf("\nA: Wanita berambut putih.\nB: Wanita berambut hijau.\nC: Wanita berambut hitam.");
		STARTWORD();
		if(currentWord.TabWord[0] == 'A' || currentWord.TabWord[0] == 'a' || currentWord.TabWord[0] == 'B' || currentWord.TabWord[0] == 'b' || currentWord.TabWord[0] == 'C' || currentWord.TabWord[0] == 'c'){
			chosen = currentWord.Tabword[0];
			error = false;
		}
		if(error){
			printf("Input Anda salah, coba lagi.\n");
			currentWord.TabWord[0] = undef;
			printf("\nPress ENTER key to back...");
			fgetchar();
		}
	}

	Chara player, partner, skel, zomb, gob, spid, wit, vamp, boss;
    makeChara(&player, 0);
    makeChara(&skel, 4);
    makeChara(&gob, 5);
    makeChara(&zomb, 6);
    makeChara(&spid, 7);
    makeChara(&wit, 8);
    makeChara(&vamp, 9);
    makeChara(&boss, 10);

	if(chosen == 'a' || chosen == "A"){
        makeChara(&partner, 1);
		printf("\nHmph. Lama sekali kamu memilih. Ayo, kita siap-siap.");
    }
    else if(chosen == 'b' || chosen == "B"){
        makeChara(&partner, 2);
		printf("\nWoooo! Ayo kita jelajahi dungeon itu, semua hartanya milikku ya!");
    }
    else if(chosen == 'c' || chosen == "C"){
        makeChara(&partner, 3);
		printf("\nHehe. Aku tahu kamu pasti pilih aku. Ayo kita bersiap.");
    }

	printf("\n");
	printChara(partner);
	printf("\nPress ENTER key to back...");
	fgetchar();

	system("cls");
	printArt("gate.txt");
	printf("\n\nKalian berdua tiba di depan gerbang dungeon. Gerbang besar berwarna putih ini bersinar redup di bawah sinar rembulan.");
	sleep(1000);
	printf("\nTerlihat ornamen-ornamen yang terlihat indah pada gerbang, dan kalian dapat merasakan gerbang itu magis.");
	sleep(1000);
	printf("\nNamun, di balik gerbang ini... terdapat aura jahat yang gelap, Seolah-olah disegel oleh gerbang ini sejak dahulu kala.");
	sleep(1000);
	printf("\n\"Kamu sudah siap?\" tanya teman disampingmu. Kamu mengangguk dan kalian membuka gerbang itu dengan mantra dari petugas guild.");
	sleep(1000);
	printf("\nPress ENTER key to start...");
	fgetchar();

	while(!finish){
		system("cls");
		switch(loc)
			case loc == p:
				printf("\n\nKalian memasuki dungeon ini. Ruangan pertama yang kalian lihat merupakan ruangan yang tidak terurus.");
				sleep(2000);
				printf("\nWalau begitu, kalian yakin bahwa ruangan ini aman... untuk sekarang.");
				sleep(1000);
				break;
			case Info(loc) == 0:
				printf("\n\nKalian memasuki ruangan yang terlihat kusam. Terdapat beberapa barang tersebar diruangan.");
				sleep(2000);
				printf("\nDari pengamatan kalian, ruangan ini terlihat aman...");
				sleep(1000);
				printArt("chest.txt");
				break;
			case Info(loc) == 1:
				printf("\n\nRuangan yang kalian masuki merupakan ruangan yang gelap. Terdapat suatu suara disekitar kalian.");
				sleep(2000);
				printf("\nSetelah mengamati, kalian menyadari bahwa ada %d kerangka manusia yang hidup!", seed_diff);
				sleep(1000);
				printArt("skeleton.txt");
				break;
			case Info(loc) == 2:
				printf("\n\nRuangan kali ini terasa aneh. Kalian merasa seperti ada yang bernafas...");
				sleep(2000);
				printf("\nKalian melihat ke sekitar dengan obor di tangan, dan ternyata ada %d goblin!", seed_diff);
				sleep(1000);
				printArt("goblin.txt");
				break;
			case Info(loc) == 3:
				printf("\n\nRuangan ini seperti kuburan. Melihat banyak batu nisan, temanmu bersembunyi dibelakangmu.");
				sleep(2000);
				printf("\nTidak lama kemudian, tangan-tangan orang mati muncul dari tanah! Ada %d zombie yang bangkit!", seed_diff);
				sleep(1000);
				printArt("zombie.txt");
				break;
			case Info(loc) == 4:
				printf("\n\nRuangan ini... sepertinya normal. Ruangan ini layaknya ruangan kantin yang sudah usang.");
				sleep(2000);
				printf("\nBaru saja kalian ingin beristirahat, tiba-tiba ada suara dari atas! %d laba-laba besar turun menyerbu!", seed_diff);
				sleep(1000);
				printArt("spider.txt");
				break;
			case Info(loc) == 5:
				printf("\n\nKalian tahu bahwa... ruangan ini bukanlah ruangan biasa. Dekorasinya masih terjaga. Keadaan ruangan ini agak usang namun rapi.");
				sleep(2000);
				printf("\nCermin terpampang di dinding, lilin yang menjaga cahaya di ruangan. Seseorang tinggal disini!");
				sleep(2000);
				printf("\n\"Kalian sangat berani masuk kemari... Tapi, waktunya untuk kalian mati!\"\nSeorang penyihir mengarahkan tangannya ke arah kalian!");
				sleep(1000);
				printArt("witch.txt");
				break;
			case Info(loc) == 6:
				printf("\n\nRuangan ini sangat gelap. Bahkan cahaya obor kalian tidak bisa menerangi seluruh ruangan.");
				sleep(2000);
				printf("\nFirasat kalian bereaksi. Seseorang atau sesuatu mengawasi kalian dari kegelapan!");
				sleep(2000);
				printf("\n\"Kamu... Terlihat enak!\"\nSeorang vampir terbang cepat ke arah kalian!");
				sleep(1000);
				printArt("vampire.txt");
				break;
			case Info(loc) == 7:
				printf("\n\nMelangkah keluar dari portal itu, kalian merasakan sesuatu yang sangat jahat.");
				sleep(2000);
				printf("\nUdara disini kering, tekanan mental sangat tinggi, dan gelap nya mencekam.");
				sleep(2000);
				printf("\n\"Selamat, selamat! Para petualang berani, kuucapkan selamat!!\" Suara tersebut memecah keheningan.");
				sleep(2000);
				printf("\nTempat kalian berdiri seakan bergetar, dan daerah sekitar kalian mulai bercahaya redup.\nDi ujung ruangan terlihat sesuatu...");
				sleep(2000);
				printf("\nSesuatu menyerupai manusia, yang sepertinya terbuat dari bayangan terlihat seperti sedang berdiri.");
				sleep(2000);
				printf("\nCahaya tidak bisa menerangi daerah sekitarnya. Aura jahat yang kuat terpancar darinya...");
				sleep(2000);
				printf("\n\"Kalian mencapai ruang-- atau bisa dibilang penjaraku!\"\nKalian bisa melihat ruangan ini retak dan di dekat bayangan itu terlihat asap ungu dan api gelap.")
				sleep(2000);
				printf("\nWaktu terasa lambat... Kurasa sudah saatnya kalian mengalahkan dia. Semoga beruntung!");
				sleep(1000);
				printArt("void.txt");
				break;
		if(Info(loc) > 0){
			
		}

	}
}