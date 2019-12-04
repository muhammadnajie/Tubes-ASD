#include "iostream"
#include "windows.h"
#include "conio.h"
#include "ctime"
#include "cstring"
#include "iomanip"
#include "algorithm"
#include "vector"
using namespace std;
const int BIRU = 9;
const int PUTIH = 7;
const int ENTER = 13;
typedef struct BSTNode *adrBSTNode;
typedef int unikID;
struct strstc {
	string* s;
	int n;
	strstc(int a = 10){
		s = new string[a];
		n = 0;
	}
	void insert(string a){
		s[n++] = a;
	}
};
struct BSTNode{
    int id_stasiun;
    string nama_stasiun, provinsi, kota, kecamatan;
    adrBSTNode left, right;
	void tampil(){
		cout<<setw(13)<<std::left<<"ID Stasiun"<<": "<<id_stasiun<<endl;
		cout<<setw(13)<<std::left<<"Nama Stasiun"<<": "<<nama_stasiun<<endl;
		cout<<setw(13)<<std::left<<"Provinsi"<<": "<<provinsi<<endl;
		cout<<setw(13)<<std::left<<"Kota"<<": "<<kota<<endl;
		cout<<setw(13)<<std::left<<"Kecamatan"<<": "<<kecamatan<<endl;
	}
};
struct BSTree{
    adrBSTNode root;
    int NbElmt;
    BSTree(){
        root = NULL;
        NbElmt = 0;
    }

    adrBSTNode BuatNode(int id_stasiun, string nama_stasiun, string provinsi, string kota, string kecamatan){
        adrBSTNode temp = new BSTNode();
        temp->id_stasiun = id_stasiun;
        temp->nama_stasiun = nama_stasiun;
        temp->provinsi = provinsi;
        temp->kota = kota;
        temp->kecamatan = kecamatan;
        return temp;
    }

    bool IsTreeOneElement(){
        return root->left == NULL && root->right == NULL;
    }

    bool IsTreeEmpty(){
        return root == NULL;
    }

    void Insert(int id, string nama_stasiun, string provinsi, string kota, string kecamatan){
        NbElmt++;
        bool left = 0;
        adrBSTNode temp = root;
        adrBSTNode newNode = BuatNode(id, nama_stasiun, provinsi, kota, kecamatan);
        //Kondisi tree kosong
        if(root == NULL){
            root = newNode;
            return;
        }
        
        while(temp != NULL){
            if(nama_stasiun <= temp->nama_stasiun){ // Cek apakah sebelah kiri
                if(temp->left != NULL) temp = temp->left;
                else{
                    left = true;
                    break;
                }
            }else {
                if(temp->right != NULL) temp = temp->right;
                else break;
            }
        }
        
        if(left){
 //       	cout << " X";
        	temp->left = newNode;	
		} 
        else {
   //     	cout << "Y";
			temp->right = newNode;
        	
		}
    }

    adrBSTNode Search(string nama_stasiun){
        adrBSTNode temp = root;
        while(temp != NULL){
            if(nama_stasiun == temp->nama_stasiun)
                return temp;
            else if(nama_stasiun < temp->nama_stasiun)
                temp = temp->left;
            else
                temp = temp->right;

        }
        return NULL;
    }

    void PrintPreOrder(adrBSTNode R){
        if(R != NULL){
            cout << R->nama_stasiun << endl;
            PrintPreOrder(R->left);
            PrintPreOrder(R->right);
        }
    }
	void InOrder(adrBSTNode R){
        if(R != NULL){
            InOrder(R->left);
			cout<<R->nama_stasiun<<endl;
            InOrder(R->right);
        }
    }
    void InOrder(adrBSTNode R, strstc &s){
        if(R != NULL){
            InOrder(R->left, s);
			s.insert(R->nama_stasiun);
            InOrder(R->right, s);
        }
    }

    void PrintPostOrder(adrBSTNode R){
        if(R != NULL){
            PrintPostOrder(R->left);
            PrintPostOrder(R->right);
            cout << R->nama_stasiun << endl;
        }
    }

};
struct single_list {
	struct jdl{
		string tanggal,jam;
	};
	struct node {
		string ID_Kereta, asal, tujuan, kelas, harga;
		int jumlah_gerbong, kapasitas, jumlah_kursi_terisi;
		jdl jadwal;
		node* next;
        void tampil(){
			CONSOLE_SCREEN_BUFFER_INFO cbsi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi);
        	COORD pos = cbsi.dwCursorPosition;
            cout<<setw(15)<<left<<"ID Kereta"<<": "<<ID_Kereta;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Stasiun Asal"<<": "<<asal;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Stasiun Tujuan"<<": "<<tujuan;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Tanggal"<<": "<<jadwal.tanggal.substr(6, 2)<<"-"<<jadwal.tanggal.substr(4,2)<<"-"<<jadwal.tanggal.substr(0, 4);
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Jam"<<": "<<jadwal.jam;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Kelas"<<": "<<kelas;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Banyak Gerbong"<<": "<<jumlah_gerbong;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Kapasitas"<<": "<<kapasitas;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Terisi"<<": "<<jumlah_kursi_terisi;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(15)<<left<<"Harga"<<": Rp."<<harga<<",00";
        }
	};
	node *first, *last;
	single_list(){
		first = NULL;
		last = NULL;
	}
	bool isEmpty(){
		return (first == NULL);
	}
	node* allocating(string ID_Kereta,string asal,string tujuan,string kelas,unsigned int jumlah_gerbong,unsigned int kapasitas,unsigned int jumlah_kursi_terisi,jdl jadwal, string harga) {
		node* newnode = new node;
		newnode->ID_Kereta = ID_Kereta;
		newnode->asal = asal;
		newnode->tujuan	= tujuan;
		newnode->kelas = kelas;
		newnode->jumlah_gerbong = jumlah_gerbong;
		newnode->kapasitas = kapasitas;
		newnode->jumlah_kursi_terisi = jumlah_kursi_terisi;
		newnode->jadwal = jadwal;
        newnode->harga = harga;
		newnode->next = NULL;
		return newnode;
	}
	void insertFirst(string ID_Kereta,string asal,string tujuan,string kelas,unsigned int jumlah_gerbong,unsigned int kapasitas,unsigned int jumlah_kursi_terisi,jdl jadwal, string harga){
		node* newnode = allocating(ID_Kereta,asal,tujuan,kelas,jumlah_gerbong,kapasitas,jumlah_kursi_terisi,jadwal,harga);
		newnode->next = first;
		first = newnode;
		if(last == NULL) last = newnode;
	}
	void insertAfter(node* prev, string ID_Kereta,string asal,string tujuan,string kelas,unsigned int jumlah_gerbong,unsigned int kapasitas,unsigned int jumlah_kursi_terisi,jdl jadwal, string harga){
		if (isEmpty())
			insertFirst(ID_Kereta,asal,tujuan,kelas,jumlah_gerbong,kapasitas,jumlah_kursi_terisi,jadwal,harga);
		else{
			node* newnode = allocating(ID_Kereta,asal,tujuan,kelas,jumlah_gerbong,kapasitas,jumlah_kursi_terisi,jadwal,harga);
			if(prev->next == NULL) last = newnode;
			newnode->next = prev->next;
			prev->next = newnode;
		}
	}
	void insertN(string ID_Kereta,string asal,string tujuan,string kelas,unsigned int jumlah_gerbong,unsigned int kapasitas,unsigned int jumlah_kursi_terisi,jdl jadwal, string harga){
		if(isEmpty()) insertFirst(ID_Kereta,asal,tujuan,kelas,jumlah_gerbong,kapasitas,jumlah_kursi_terisi,jadwal, harga);
		else{
			node* temp = first, *prev = NULL;
			while( temp != NULL && temp->jadwal.tanggal < jadwal.tanggal ){
				prev = temp;
				temp = temp->next;
			}
			if(NULL == prev) insertFirst(ID_Kereta,asal,tujuan,kelas,jumlah_gerbong,kapasitas,jumlah_kursi_terisi,jadwal,harga);
			else insertAfter(prev, ID_Kereta,asal,tujuan,kelas,jumlah_gerbong,kapasitas,jumlah_kursi_terisi,jadwal,harga);
		}
	}

};
struct Hash{
	single_list* data;
	unsigned int nElmt;
	Hash(){
		data = new single_list[100];
		nElmt = 0;
	}
	void insert(string ID_Kereta,string asal,string tujuan,string kelas,unsigned int jumlah_gerbong,unsigned int kapasitas,unsigned int jumlah_kursi_terisi,single_list::jdl jadwal,string harga){
		int index =((ID_Kereta[0]-48)*10) + (ID_Kereta[1]-48);
		data[index].insertN(ID_Kereta,asal,tujuan,kelas,jumlah_gerbong,kapasitas,jumlah_kursi_terisi,jadwal,harga);
		nElmt++;
	}
	single_list::node* FindAll (string asal, string tujuan, string tanggal){
		single_list::node* temp ;
		for(int i=0;i<100;i++){
			temp = data[i].first;
			while(temp){
				if(temp->asal == asal && temp->tujuan == tujuan && temp->jadwal.tanggal == tanggal){
					return temp;
				}
				temp=temp->next;
			}
		}
		return NULL;
	}
	single_list::node* CariID(string ID_Kereta){
		single_list::node* temp;
		int index = (ID_Kereta[0]-48)*10 + ID_Kereta[1] - 48;
		temp = data[index].first;
		while(temp && temp->ID_Kereta != ID_Kereta){
			temp = temp->next;
		}
		return temp;
	}
};
struct double_list {
    struct info_tiket {
        string nama, id_kereta, asal, tujuan, tanggal, jam, harga, kelas;
		int id_tiket;
        void tampil(){
			CONSOLE_SCREEN_BUFFER_INFO cbsi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi);
        	COORD pos = cbsi.dwCursorPosition;
            cout<<setw(10)<<left<<"Nama"<<": "<<nama;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(10)<<left<<"ID Tiket"<<": "<<id_tiket;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(10)<<left<<"ID Kereta"<<": "<<id_kereta;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(10)<<left<<"Asal"<<": "<<asal;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(10)<<left<<"Tujuan"<<": "<<tujuan;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(10)<<left<<"Tanggal"<<": "<<tanggal.substr(6, 2)<<"-"<<tanggal.substr(4,2)<<"-"<<tanggal.substr(0, 4);
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(10)<<left<<"Jam"<<": "<<jam;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(10)<<left<<"Kelas"<<": "<<kelas;
			++pos.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            cout<<setw(10)<<left<<"Harga"<<": Rp."<<harga<<",00\n";
        }
    };
    struct node {
        info_tiket info;
        node *next, *prev;
    };
    node *first, *last;
	int id;
    double_list(){
		id = 0;
        first = NULL;
        last = NULL;
    }
    bool isEmpty(){
        return (first == NULL);
    }
    node* allocating(string nama, int id_tiket, string id_kereta, string asal, string tujuan, string tanggal, string jam, string harga, string kelas) {
        node* newnode = new node;
        newnode->info.nama = nama;
        newnode->info.id_tiket = id_tiket;
        newnode->info.id_kereta = id_kereta;
        newnode->info.asal = asal;
        newnode->info.tujuan = tujuan;
        newnode->info.tanggal = tanggal;
        newnode->info.jam = jam;
        newnode->info.harga = harga;
        newnode->info.kelas = kelas;
        newnode->next = NULL;
        newnode->prev = NULL;
        return newnode;
    }
    void insertFirst(string nama, int id_tiket, string id_kereta, string asal, string tujuan, string tanggal, string jam, string harga, string kelas){
        node* newnode = allocating(nama, id_tiket, id_kereta, asal, tujuan, tanggal, jam, harga, kelas);
        newnode->next = first;
        if(first != NULL) first->prev = newnode;
        first = newnode;
        if(last == NULL) last = newnode;
    }
    void insertAfter(node* prev, string nama, int id_tiket, string id_kereta, string asal, string tujuan, string tanggal, string jam, string harga, string kelas){
        if (isEmpty()) {
            insertFirst(nama, id_tiket, id_kereta, asal, tujuan, tanggal, jam, harga, kelas);
        }
        else{
            node* newnode = allocating(nama, id_tiket, id_kereta, asal, tujuan, tanggal, jam, harga, kelas);
            if(prev->next == NULL) last = newnode;
            newnode->next = prev->next;
            newnode->prev = prev;
            if(prev->next != NULL) (prev->next)->prev = newnode;
            prev->next = newnode;
        }
    }
    void insertLast(string nama, int id_tiket, string id_kereta, string asal, string tujuan, string tanggal, string jam, string harga, string kelas){
        insertAfter(last, nama, id_tiket, id_kereta, asal, tujuan, tanggal, jam, harga, kelas);
    }
    node* find(int id_tiket){
        node* temp = first;
        while(temp != NULL && temp->info.id_tiket != id_tiket){
            temp = temp->next;
        }
        return temp;
    }
    void insert(string nama, int id_tiket, string id_kereta, string asal, string tujuan, string tanggal, string jam, string harga, string kelas){
        if(isEmpty()) insertFirst(nama, id_tiket, id_kereta, asal, tujuan, tanggal, jam, harga, kelas);
        else{
            node* temp = first, *prev = NULL;
            while( temp != NULL && temp->info.id_tiket < id_tiket ){
                prev = temp;
                temp = temp->next;
            }
            if(NULL == prev) insertFirst(nama, id_tiket, id_kereta, asal, tujuan, tanggal, jam, harga, kelas);
            else insertAfter(prev, nama, id_tiket, id_kereta, asal, tujuan, tanggal, jam, harga, kelas);
        }
    }
    void deleteFirst(){
        if (!isEmpty()) {
            node* temp = first;
            first = first->next;
            if(first != NULL) first->prev = NULL;
			else last = NULL;
            delete temp;
        }
    }
    bool deleteAfter(node* pred){
        if(pred == NULL){
            deleteFirst();
            return true;
        } else if (!isEmpty() && pred->next != NULL) {
            node* temp = pred->next;
            if (temp->next == NULL) last = pred;
            pred->next = temp->next;
            if(pred->next != NULL) (pred->next)->prev = pred;
            delete temp;
            return true;
        }
        return false;
    }
    void deleteBefore(node* sucs){
        if(!isEmpty() && sucs->prev != NULL){
            if((sucs->prev)->prev == NULL) deleteFirst();
            else deleteAfter((sucs->prev)->prev);
        }
    }
    void Delete(){
        if (!isEmpty()) {
            deleteAfter(last->prev);
        }
    }
    void display(){
        node* temp = first;
        int no = 1;
        while (temp != NULL) {
            cout<<"#"<<no<<"\n";
            temp->info.tampil();
            no++;
            temp = temp->next;
        }
    }
    void displayBack(){
        node* temp = last;
        int no = 1;
        while (temp != NULL) {
            cout<<"#"<<no<<"\n";
            temp->info.tampil();
            no++;
            temp = temp->prev;
        }
    }
};
struct inter{
    private:
        void movcur(short x, short y){
            COORD koord = {x, y};
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koord);
        }
        void ubahwarna(int a){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
        }
        COORD CursorPosition(){
            CONSOLE_SCREEN_BUFFER_INFO cbsi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi);
            return cbsi.dwCursorPosition;
        }
        unsigned short update_menu(string isi[], bool down, unsigned short int stat, const unsigned short int max){
            COORD pos = CursorPosition();
            int awal = pos.X-(isi[stat].length());
            ubahwarna(PUTIH);
            movcur(awal, pos.Y);
            cout<<isi[stat];
            ubahwarna(BIRU);
            if (down) {
                if(stat+1 == max){
                    movcur(awal, pos.Y-stat);
                    stat = 0;
                }
                else{
                    movcur(awal, pos.Y+1);
                    stat++;
                }
            }
            else{
                if(stat == 0){
                    movcur(awal, pos.Y-stat+max-1);
                    stat = max-1;
                }
                else{
                    movcur(awal, pos.Y-1);
                    stat--;
                }
            }
            cout<<isi[stat];
            ubahwarna(PUTIH);
            return stat;
        }
        struct tm* getTanggal(){
            time_t tt;
            struct tm* tm;
            time(&tt);
            tm = localtime(&tt);
            return tm;
        }
        void update_tanggal(struct tm* ti, bool up){
            if(up){
                if(!((ti->tm_mon == max.tm_mon) && (ti->tm_year == max.tm_year) && (ti->tm_mday == max.tm_mday))){
                    ti->tm_mday += 1;
                    mktime(ti);
                }
                else copytm(*ti, &min);
            }
            else{
                if(!((ti->tm_mon == min.tm_mon) && (ti->tm_year == min.tm_year) && (ti->tm_mday == min.tm_mday))){
                    ti->tm_mday -= 1;
                    mktime(ti);
                }
                else copytm(*ti, &max);
            }
            COORD pos = CursorPosition();
            movcur(pos.X-10, pos.Y);
            ubahwarna(BIRU);
            cout<<setw(2)<<ti->tm_mday<<" ";
            cout<<setw(2)<<ti->tm_mon+1<<" ";
            cout<<ti->tm_year+1900;
            ubahwarna(PUTIH);
        }
        unsigned int state_update_tanggal(struct tm* ti, bool right, int state){
          int a[3] = {ti->tm_mday, ti->tm_mon+1, ti->tm_year+1900};
          if(right){
            if(state == 2) state = 0;
            else state++;
          }
          else{
            if(state == 0) state = 2;
            else state--;
          }
          COORD pos = CursorPosition();
          movcur(pos.X-10, pos.Y);
          for (size_t i = 0; i < 3; i++) {
            if(i == state) ubahwarna(BIRU);
            if(i < 2) cout<<setw(2);
            cout<<a[i];
            if(i < 2) cout<<" ";
            ubahwarna(PUTIH);
          }
          return state;
        }
        void copytm(struct tm &a, struct tm* b){
            a.tm_mon = b->tm_mon;
            a.tm_mday = b->tm_mday;
            a.tm_year = b->tm_year;
        }
		unsigned short update_menu(std::vector<single_list::node*> &isi, bool down, unsigned short int stat, const unsigned short int max, int pos[][2]){
            ubahwarna(PUTIH);
            movcur(pos[stat][0], pos[stat][1]);
            cout<<"#"<<stat+1<<endl;
			isi[stat]->tampil();
            ubahwarna(BIRU);
            if (down) {
                if(stat+1 == max){
					stat = 0;
                }
                else{
                    stat++;
                }
            }
            else{
                if(stat == 0){
					stat = max-1;
                }
                else{
					stat--;
                }
            }
			movcur(pos[stat][0], pos[stat][1]);
			cout<<"#"<<stat+1<<endl;
			isi[stat]->tampil();
            ubahwarna(PUTIH);
            return stat;
        }
		int strtoint(string id){
			int id_num = 0;
			if(id.length() <= 9){
				for (size_t i = 0; i < id.length(); i++) {
					if(int('0') <= int(id[i]) <= int('9')) id_num = id_num*10 + int(id[i])-48;
					else return -1;
				}
				return id_num;
			}
			else return -1;
		}
		bool cek(string nama){
			for (size_t i = 0; i < nama.length(); i++) {
				if(!(('a' <= nama[i] && nama[i] <= 'z') || ('A' <= nama[i] && nama[i] <= 'Z') || nama[i] == ' '))
					return true;
			}
			return false;
		}
    public:
        struct tm max = {}, min = {};
        inter(){
            struct tm* temp;
            time_t tt;
            time(&tt);
            temp = localtime(&tt);
            copytm(min, temp);
            temp->tm_mon += 1;
            mktime(temp);
            copytm(max, temp);
            string s = "Selamat Datang di Aplikasi Pesan Tiket Kereta Api";
            movcur((80-s.length())/2, 20);
            cout<<s<<endl;
            movcur(20, CursorPosition().Y);
            cout<<"Tekan ";
            ubahwarna(10);
            cout<<"'ENTER'";
            ubahwarna(PUTIH);
            cout<<" untuk masuk ke menu utama";
            while(getch() != ENTER);
            system("cls");
        }
        struct tm menu_tanggal(){
            COORD pos;
            char input;
            unsigned int state = 0;
            struct tm* ti = getTanggal();
            ubahwarna(BIRU);
            cout<<setw(2)<<ti->tm_mday<<" ";
            cout<<setw(2)<<ti->tm_mon+1<<" ";
            cout<<ti->tm_year+1900;
            while((input = getch()) != ENTER){
                switch (toupper(input)) {
                    case 'W' : update_tanggal(ti,1); break;
                    case 'S' : update_tanggal(ti, 0); break;
                }
            }
            struct tm temp;
            copytm(temp, ti);
			ubahwarna(PUTIH);
            return temp;
        }
        void akhir(){
            system("cls");
            string s = "Terima kasih telah menggunakan Aplikasi Pesan Tiket Kereta Api";
            movcur((80-s.length())/2, 20);
            cout<<s<<endl;
        }
        void kembali_utama(){
            cout<<"Tekan ";
            ubahwarna(10);
            cout<<"'ENTER'";
            ubahwarna(PUTIH);
            cout<<" untuk kembali ke menu utama";
            while(getch() != ENTER);
        }
        unsigned short int menu(string s[], int n, int t = -1){
            COORD pos, temppos;
            char input;
			unsigned int state = (t == 0) ? 1 : 0;
            for (size_t i = 0; i < n; i++) {
                temppos = CursorPosition();
                if(state == i){
                    ubahwarna(BIRU);
                }
                cout<<s[i];
                if (state == i) {
                    pos = CursorPosition();
                }
                movcur(temppos.X, temppos.Y+1);
                ubahwarna(PUTIH);
            }
            //cout<<"S : Geser ke bawah.    W : Geser ke Atas.";
            movcur(pos.X, pos.Y);
            while((input = getch()) != ENTER){
                switch (toupper(input)) {
                    case 'W' :
						state = update_menu(s, 0, state, n);
						if(state == t) state = update_menu(s, 0, state, n);
						break;
                    case 'S' :
						state = update_menu(s, 1, state, n);
						if(state == t) state = update_menu(s, 1, state, n);
						break;
                }
            }
            movcur(pos.X-s[0].length(), pos.Y+n+1);
            return state;
        }
		single_list::node* menu(vector<single_list::node*> &s, int n, int t = -1){
            COORD posc, temppos, akhir;
			int awal = CursorPosition().X;
            char input;
			unsigned int state = (t == 0) ? 1 : 0;
			int pos[n][2];
            for (size_t i = 0; i < n; i++) {
                temppos = CursorPosition();
				pos[i][0] = temppos.X;
				pos[i][1] = temppos.Y;
                if(state == i){
                    ubahwarna(BIRU);
                }
				cout<<"#"<<i+1<<endl;
                s[i]->tampil();
				if(i < n-1) cout<<endl;
                if (state == i){
                    posc = CursorPosition();
                }
				akhir = CursorPosition();
                movcur(awal, akhir.Y+1);
                ubahwarna(PUTIH);
            }
            movcur(posc.X, posc.Y);
            while((input = getch()) != ENTER){
                switch (toupper(input)) {
                    case 'W' :
						state = update_menu(s, 0, state, n, pos);
						break;
                    case 'S' :
						state = update_menu(s, 1, state, n, pos);
						break;
                }
            }
            movcur(awal, akhir.Y+1);
            return s[state];
        }
        unsigned short int main(string s[], int n){
            COORD pos = CursorPosition();
            movcur(pos.X+10, pos.Y);
            cout<<"_____Main Menu______"<<endl;
			COORD temppos;
            char input;
			unsigned int state = 0;
            for (size_t i = 0; i < n; i++) {
                temppos = CursorPosition();
                if(state == i){
                    ubahwarna(BIRU);
                }
                cout<<s[i];
                if (state == i) {
                    pos = CursorPosition();
                }
                movcur(temppos.X, temppos.Y+1);
                ubahwarna(PUTIH);
            }
            cout<<"S : Geser ke bawah.    W : Geser ke Atas.";
            movcur(pos.X, pos.Y);
            while((input = getch()) != ENTER){
                switch (toupper(input)) {
                    case 'W' :
						state = update_menu(s, 0, state, n);
						break;
                    case 'S' :
						state = update_menu(s, 1, state, n);
						break;
                }
            }
            movcur(pos.X-s[0].length(), pos.Y+n+1);
            return state;
        }
		void cari_tiket(double_list &l, Hash &h, BSTree &t){
            system("cls");
            string id = "";
            cout<<"Masukkan ID Tiket yang ingin dicari : ";
			while (id == "") getline(cin, id);
			int id_num = strtoint(id);
			if(id_num == -1){
				cout<<"Maaf, Tiket yang Anda cari tidak ditemukan!"<<endl;
				kembali_utama();
				return;
			}
            double_list::node* a = l.find(id_num);
            if(a) {
                cout<<"Info Tiket :"<<endl;
                a->info.tampil();
                cout<<"\n\nInfo Kereta :"<<endl;
                single_list::node* kereta = h.CariID(a->info.id_kereta);
				if(!kereta){
					cout<<a->info.id_kereta;
					kembali_utama();
					return;
				}
                kereta->tampil();
				BSTNode* asal = t.Search(a->info.asal);
				cout<<"\n\nInfo Stasiun Asal :"<<endl;
				asal->tampil();
				asal = t.Search(a->info.tujuan);
				cout<<"\nInfo Stasiun Tujuan :"<<endl;
				asal->tampil();
            }
            else{
                cout<<"Maaf, Tiket yang Anda cari tidak ditemukan!"<<endl;
            }
			cout<<endl;
            kembali_utama();
        }
        void tampilkan_tiket(double_list &l){
            system("cls");
            cout<<"Daftar Tiket yang sudah terpesan :"<<endl;
            if(l.isEmpty()) cout<<"Tidak ada tiket yang dipesan"<<endl;
            else l.display();
            cout<<"Tekan ";
            ubahwarna(10);
            cout<<"'ENTER'";
            ubahwarna(PUTIH);
            cout<<" untuk kembali ke menu utama";
            while(getch() != ENTER);
        }
        void batalkan_tiket(double_list &l, Hash &h){
            system("cls");
            string cari = "", pil[2] = {"Ya", "Tidak"};
            int jawaban;
            cout<<"Masukkan ID Tiket yang ingin dibatalkan : ";
			while(cari == "") getline(cin, cari);
			int id_num = strtoint(cari);
			if(id_num == -1){
				cout<<"Tidak ada tiket yang sesuai dengan ID tiket yang anda masukkan"<<endl;
				kembali_utama();
				return;
			}
            double_list::node* a = l.find(id_num);
            if(a) {
                a->info.tampil();
                cout<<"Apakah Anda yakin ingin membatalkan tiket ini ?"<<endl;
                jawaban = menu(pil, 2);
                if(!jawaban) {
					single_list::node* kereta = h.CariID(a->info.id_kereta);
					kereta->jumlah_kursi_terisi--;
                    if(l.deleteAfter(a->prev)) cout<<"Tiket Anda Berhasil dibatalkan"<<endl;
                    else cout<<"Tiket Anda gagal dibatalkan"<<endl;
                }
            }
            else{
                cout<<"Tidak ada tiket yang sesuai dengan ID tiket yang anda masukkan"<<endl;
            }
            kembali_utama();
        }
		void pesan_tiket(double_list &l, Hash &h, BSTree &t){
			system("cls");
			string asal, tujuan;
			struct tm tanggal;
			int n;
			strstc s;
			string nama = "";
			COORD pos = CursorPosition();
			t.InOrder(t.root, s);
			cout<<"Masukkan nama anda : ";
			COORD awal = CursorPosition();
			getline(cin, nama);
			while(nama == "" || cek(nama)){
				cout<<"Nama anda tidak boleh kosong dan hanya boleh mengandung huruf dan spasi";
				movcur(awal.X, awal.Y);
				cout<<setw(nama.length())<<"";
				movcur(awal.X, awal.Y);
				getline(cin, nama);
			}
			system("cls");
			movcur(pos.X, pos.Y);
			cout<<"Nama : "<<nama<<endl;
			cout<<"Pilih Stasiun Asal : ";
			n = menu(s.s, s.n);
			asal = s.s[n];
			system("cls");
			movcur(pos.X, pos.Y);
			cout<<"Nama : "<<nama<<endl;
			cout<<"Stasiun Asal : "<<asal;
			cout<<endl<<"Pilih Stasiun Tujuan : ";
			n = menu(s.s, s.n, n);
			tujuan = s.s[n];
			system("cls");
			movcur(pos.X, pos.Y);
			cout<<"Nama : "<<nama<<endl;
			cout<<"Stasiun Asal : "<<asal<<endl;
			cout<<"Stasiun Tujuan : "<<tujuan<<endl;
			pos = CursorPosition();
			cout<<"Pilih Tanggal : ";
			tanggal = menu_tanggal();
			movcur(pos.X, pos.Y);
			cout<<"Tanggal keberangkatan : "<<setw(2)<<tanggal.tm_mday<<" "<<setw(2)<<tanggal.tm_mon+1<<" "<<tanggal.tm_year+1900<<endl;
			char temp[30];
			strftime(temp, 30, "%Y%m%d", &tanggal);
			string format(temp);
			single_list::node *start = h.FindAll(asal, tujuan, format);
			vector<single_list::node*> daf_ker;
			if(start){
				while(start && start->jadwal.tanggal == format){
					if(start->jumlah_kursi_terisi < start->kapasitas) daf_ker.insert(daf_ker.end(), start);
					start = start->next;
				}
				single_list::node* kereta = menu(daf_ker, daf_ker.size());
				system("cls");
				cout<<setw(10)<<left<<"Nama"<<": "<<nama<<"\n";
	            cout<<setw(10)<<left<<"ID Kereta"<<": "<<kereta->ID_Kereta<<"\n";
	            cout<<setw(10)<<left<<"Asal"<<": "<<asal<<"\n";
	            cout<<setw(10)<<left<<"Tujuan"<<": "<<tujuan<<"\n";
	            cout<<setw(10)<<left<<"Tanggal"<<": "<<format.substr(6, 2)<<"-"<<format.substr(4,2)<<"-"<<format.substr(0, 4)<<"\n";
	            cout<<setw(10)<<left<<"Jam"<<": "<<kereta->jadwal.jam<<"\n";
	            cout<<setw(10)<<left<<"No Kursi"<<": "<<kereta->jumlah_kursi_terisi+1<<"\n";
	            cout<<setw(10)<<left<<"Kelas"<<": "<<kereta->kelas<<"\n";
	            cout<<setw(10)<<left<<"Harga"<<": Rp."<<kereta->harga<<",00\n\n";
				cout<<"Apakah anda yakin ingin memesan tiket ini : ";
				string yes[2] = {"Ya", "Tidak"};
				if(!menu(yes, 2)){
					++(kereta->jumlah_kursi_terisi);
					l.insert(nama, ++(l.id), kereta->ID_Kereta, asal, tujuan, format, kereta->jadwal.jam, kereta->harga, kereta->kelas);
					cout<<endl<<"Selamat tiket anda berhasil diproses.";
				}
			}
			else{
				cout<<"------Maaf tiket yang anda cari tidak ditemukan------";
			}
			cout<<endl;
			kembali_utama();
		}
        void ubah_tiket(double_list &l, Hash &h, BSTree &t){
            system("cls");
			single_list::node* kereta, *mula;
			string nama;
            string id = "";
			cout<<"Masukkan ID Tiket yang ingin dicari : ";
			while (id == "") {
				getline(cin, id);
			}
			int id_num = strtoint(id);
			if(id_num == -1){
				cout<<"Maaf, tidak ada tiket yang sesuai dengan ID Tiket anda"<<endl;
				kembali_utama();
				return;
			}
            double_list::node* a = l.find(id_num);
            if(a){
				nama = a->info.nama;
				kereta = h.CariID(a->info.id_kereta);
				mula = kereta;
				cout<<endl;
        		a->info.tampil();
				cout<<"Apa yang anda ingin ubah dari tiket anda?"<<endl;
				string b[2] = {"Nama", "Kereta"};
				int hasil = menu(b, 2);
				if(!hasil){
					cout<<"Masukkan Nama Anda yang baru : ";
					COORD awal = CursorPosition();
					getline(cin, nama);
					while(nama == "" || cek(nama)){
						cout<<"Nama anda tidak boleh kosong dan hanya boleh mengandung huruf dan spasi";
						movcur(awal.X, awal.Y);
						cout<<setw(nama.length())<<"";
						movcur(awal.X, awal.Y);
						getline(cin, nama);
					}
				}
				else{
					system("cls");
					strstc s;
					struct tm tanggal;
					COORD pos = CursorPosition();
					string asal, tujuan;
					t.InOrder(t.root, s);
					cout<<"Pilih Stasiun Asal : ";
					int n = menu(s.s, s.n);
					asal = s.s[n];
					system("cls");
					movcur(pos.X, pos.Y);
					cout<<"Stasiun Asal : "<<asal;
					cout<<endl<<"Pilih Stasiun Tujuan : ";
					n = menu(s.s, s.n, n);
					tujuan = s.s[n];
					system("cls");
					movcur(pos.X, pos.Y);
					cout<<"Stasiun Asal : "<<asal<<endl;
					cout<<"Stasiun Tujuan : "<<tujuan<<endl;
					pos = CursorPosition();
					cout<<"Pilih Tanggal : ";
					tanggal = menu_tanggal();
					movcur(pos.X, pos.Y);
					cout<<"Tanggal keberangkatan : "<<setw(2)<<tanggal.tm_mday<<" "<<setw(2)<<tanggal.tm_mon+1<<" "<<tanggal.tm_year+1900<<endl;
					char temp[30];
					strftime(temp, 30, "%Y%m%d", &tanggal);
					string format(temp);
					single_list::node *start = h.FindAll(asal, tujuan, format);
					vector<single_list::node*> daf_ker;
					if(start){
						while(start && start->jadwal.tanggal == format){
							if(start->jumlah_kursi_terisi < start->kapasitas && start != kereta) daf_ker.insert(daf_ker.end(), start);
							start = start->next;
						}
						if(daf_ker.size() == 0){
							cout<<"Maaf, Tidak ada kereta lain yang memiliki rute seperti tiket anda"<<endl;
							return;
						}
						kereta = menu(daf_ker, daf_ker.size());
					}
					else{
						cout<<"Maaf tiket yang anda cari tidak ditemukan"<<endl;
						kembali_utama();
						return;
					}
				}
            }
            else {
                cout<<"Maaf, tidak ada tiket yang sesuai dengan ID Tiket anda"<<endl;
				kembali_utama();
				return;
            }
			double_list::info_tiket tujuan;
			tujuan.nama = nama;
	        tujuan.id_tiket = a->info.id_tiket;
	        tujuan.id_kereta = kereta->ID_Kereta;
	        tujuan.asal = kereta->asal;
	        tujuan.tujuan = kereta->tujuan;
	        tujuan.tanggal = kereta->jadwal.tanggal;
	        tujuan.jam = kereta->jadwal.jam;
	        tujuan.harga = kereta->harga;
	        tujuan.kelas = kereta->kelas;
			system("cls");
			COORD pos = CursorPosition();
			COORD awal = pos;
			int max = (tujuan.asal.length() > tujuan.tujuan.length()) ? tujuan.asal.length() : tujuan.tujuan.length();
			a->info.tampil();
			pos.X += max+23;
			pos.Y += 4;
			movcur(pos.X, pos.Y);
			cout<<" menjadi |\\";
			movcur(pos.X, ++pos.Y);
			cout<<"|========| \\";
			movcur(pos.X, ++pos.Y);
			cout<<"|========| /";
			movcur(pos.X, ++pos.Y);
			cout<<"         |/";
			movcur(pos.X+15, awal.Y);
			tujuan.tampil();
			cout<<"Apa anda yakin dengan perubahan ini? ";
			string c[2] = {"Ya", "Tidak"};
			int hasil = menu(c, 2);
			if(!hasil){
				mula->jumlah_kursi_terisi--;
				kereta->jumlah_kursi_terisi++;
				a->info = tujuan;
				cout<<endl<<"Tiket anda berhasil diubah";
			}
			cout<<endl;
            kembali_utama();
        }
};
int main(int argc, char const *argv[]) {
	
	
	//Resize windows console
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 525, TRUE);
    inter Tampilan;
    BSTree Stasiun;
    Hash Kereta;
    double_list Tiket;
	Stasiun.Insert(1, "ITERA", "Lampung", "Bandar Lampung", "Way Huwi");
    Stasiun.Insert(2, "KORPRI", "Lampung", "Bandar Lampung", "Sukarame");
    Stasiun.Insert(3, "Antasari", "Lampung", "Bandar Lampung", "Antasari");
    Stasiun.Insert(4, "Way Halim", "Lampung", "Bandar Lampung", "Perumnas Way Halim");
    Stasiun.Insert(5, "Tanjung Senang", "Lampung", "Bandar Lampung", "Tanjung Senang");
    Stasiun.Insert(6, "Ambar", "Lampung", "Pesawaran", "Mbuh");
    Stasiun.Insert(7, "Cimanggis", "Lampung", "Bandar Lampung", "Perumnas Way Halim");
    single_list::jdl b = {"20191203", "20:00"};
    Kereta.insert("12002", "ITERA", "KORPRI", "Ekonomi", 5, 200, 0, b, "100.000");
	//insert(&Kereta, "12002", "ITERA", "KORPRI", "Ekonomi", 5, 200, 0, {"20191130", "16:00"}, "100.000");
	Kereta.insert("12003", "ITERA", "KORPRI", "Ekonomi", 5, 200, 0, b, "100.000");
	Kereta.insert("12004", "ITERA", "KORPRI", "Ekonomi", 5, 200, 0, b, "100.000");
	Kereta.insert("12005", "ITERA", "KORPRI", "Ekonomi", 5, 200, 0, b, "100.000");
	Kereta.insert("24001", "KORPRI", "Way Halim", "Ekonomi", 5, 200, 0, b, "100.000");
	Kereta.insert("67002", "Ambar", "Cimanggis", "Ekonomi", 5, 200, 0, b, "100.000");
	Kereta.insert("35004", "Antasari", "Tanjung Senang", "Ekonomi", 5, 200, 0, b, "100.000");
	//Tiket.insert("Bambang", ++(Tiket.id), "12003", "ITERA", "KORPRI", "20191203", "16:00", "100.000", "Ekonomi");
	//Tiket.insert("Bambang", ++(Tiket.id), "12003", "ITERA", "KORPRI", "20191203", "16:00", "100.000", "Ekonomi");
	//Tiket.insert("Bambang", ++(Tiket.id), "12003", "ITERA", "KORPRI", "20191203", "16:00", "100.000", "Ekonomi");
	//Tiket.insert("Bambang", ++(Tiket.id), "12003", "ITERA", "KORPRI", "20191203", "16:00", "100.000", "Ekonomi");
    unsigned short pilihan;
    int nmenu = 6;
    string menu[nmenu] = {"Cari Tiket",
                         "Pesan Tiket",
                         "Ubah Tiket",
                         "Tampilkan Tiket",
                         "Batalkan Tiket",
                         "Keluar"};
    while((pilihan = Tampilan.main(menu, nmenu)) != 5){
        switch (pilihan) {
            case 0: Tampilan.cari_tiket(Tiket, Kereta, Stasiun); break;
            case 1: Tampilan.pesan_tiket(Tiket, Kereta, Stasiun); break;
            case 2: Tampilan.ubah_tiket(Tiket, Kereta, Stasiun); break;
            case 3: Tampilan.tampilkan_tiket(Tiket); break;
            case 4: Tampilan.batalkan_tiket(Tiket, Kereta); break;
        }
        system("cls");
    }
	Tampilan.akhir();
	
    return 0;
}
