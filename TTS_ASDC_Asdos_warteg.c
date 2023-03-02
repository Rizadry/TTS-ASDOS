#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

main(){
    login();
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

typedef struct User User;



int login() {
    system("cls");
    User users[MAX_USERS];
    int user_count = 0;

    int pilihan_menu;
    bool login_berhasil = false;
    char username_terlogin[MAX_USERNAME_LENGTH];

    do {
        printf("\n=== MENU UTAMA ===\n");
        if (login_berhasil) {
            printf("1. Logout\n");
            printf("2. Menu Lain\n");
        } else {
            printf("1. Login\n");
            printf("2. Register\n");
        }
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan_menu);

        switch (pilihan_menu) {
            case 1:
                system("cls");
                if (login_berhasil) {
                    printf("Anda berhasil logout\n");
                    system("pause > null");
                    system("cls");
                    login_berhasil = false;
                    strcpy(username_terlogin, "");
                } else {
                    char username[MAX_USERNAME_LENGTH];
                    char password[MAX_PASSWORD_LENGTH];
                    printf("\n=== LOGIN ===\n");
                    printf("Username: ");
                    scanf("%s", username);
                    printf("Password: ");
                    scanf("%s", password);
                    bool user_ditemukan = false;
                    for (int i = 0; i < user_count; i++) {
                        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                            user_ditemukan = true;
                            break;
                        }
                    }
                    if (user_ditemukan) {
                        printf("Login berhasil\n");
                        system("pause > null");
                        system("cls");
                        login_berhasil = true;
                        strcpy(username_terlogin, username);
                        menu();
                    } else {
                        printf("Maaf, username atau password salah\n");
                        system("pause > null");
                        system("cls");
                    }
                }
                break;
            case 2:
                system("cls");
                if (login_berhasil) {
                    printf("Menu lain akan ditampilkan di sini\n");
                } else {
                    char username[MAX_USERNAME_LENGTH];
                    char password[MAX_PASSWORD_LENGTH];
                    printf("\n=== REGISTER ===\n");
                    printf("Username: ");
                    scanf("%s", username);
                    printf("Password: ");
                    scanf("%s", password);
                    if (user_count == MAX_USERS) {
                        printf("Maaf, sudah mencapai batas jumlah user\n");
                    } else {
                        bool user_ada = false;
                        for (int i = 0; i < user_count; i++) {
                            if (strcmp(users[i].username, username) == 0) {
                                user_ada = true;
                                break;
                            }
                        }
                        if (user_ada) {
                            printf("Maaf, username sudah terdaftar\n");
                        } else {
                            strcpy(users[user_count].username, username);
                            strcpy(users[user_count].password, password);
                            user_count++;
                            printf("Registrasi berhasil\n");
                            system("pause > null");
                            system("cls");
                        }
                    }
                }
                break;
            case 0:
                printf("Terima kasih sudah menggunakan program ini\n");
                break;
            default:
                printf("Maaf, pilihan menu tidak tersedia\n");
                system("pause > null");
                system("cls");
                break;
        }
    } while (pilihan_menu != 0);

    return 0;
}



void border()
{
    int garis = 205;

    for(int i=0; i<=50; i++)
    {
        printf("%c", garis);
    }
}


//ngilangin kursor
void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

typedef struct {
    int id;
    char name[25];
    int harga;
} Makanan;

typedef struct {
    Makanan makan;
    int quantity;
} Order;


void printMenu(Makanan *makanan, int n) {
    printf("          W  A  R  T  E  G                \n\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - Rp%d\n", makanan[i].id, makanan[i].name, makanan[i].harga);
    }
}

void printOrder(Order *orders, int n) {
    printf("Pesanan anda:\n");
    for (int i = 0; i < n; i++) {
        printf("%d porsi %s - Rp%d\n", orders[i].quantity, orders[i].makan.name, orders[i].makan.harga * orders[i].quantity);
    }
}


void garis(){
    int garis = 186;
    printf("%c", garis);
}


void menu(){
    hidecursor();

    Makanan makanan[] = {
        {1, "Gulai Ayam                    ", 2500},
        {2, "Ayam Goreng                   ", 5000},
        {3, "Tempe Orek                    ", 1000},
        {4, "Perkedel Kentang              ", 1500},
        {5, "Telor Balado                  ", 3000},
        {6, "Telor Dadar                   ", 3000},
        {7, "Galantin Goreng               ", 1000},
        {8, "Bihun Goreng                  ", 2000},
        {9, "Tumis Kangkung                ", 1500},
        {10, "Sayur Bayam                 ", 1500},
        {11, "Sambel Goreng Kentang       ", 2000},
        {12, "Semur Jengkol               ", 5000},
        {13, "Mangut Lele                 ", 7000},
        {14, "Semur Daging                ", 7000},
        {15, "Tongkol Balado              ", 7000},
        {16, "Cumi Asin Pedas             ", 9000},
        {17, "Tumis Buncis                ", 2000},
        {18, "Terong Balado               ", 3000},
        {19, "Tempe&Tahu Goreng           ", 2000},
        {20, "Oseng Usus Bacem            ", 2000},
    };
    int n = sizeof(makanan) / sizeof(makanan[0]);//buat ngehitung ukuran operan

    printf("Tekan tombol panah ke atas atau ke bawah untuk memilih menu\n");
    printf("Tekan tombol panah ke kanan atau ke kiri untuk menambah atau mengurangi jumlah pesanan\n");
    printf("Tekan Enter untuk mengkonfirmasi pesanan\n");

    Order orders[n];
    int numOrders = 0;
    int menu = 0; // menu awal yg muncul gulai ayam
    int quantity = 1; // jumlah pesanan awal 1

    while (1) {
        system("cls");
        printMenu(makanan, n);
        printOrder(orders, numOrders);

        //nampilin menu yang dipilih dan kuantitasnya
        printf("\nAnda memesan %d porsi %s   -    Rp%d\n", quantity, makanan[menu].name, makanan[menu].harga * quantity);

        char ch = getch();
        switch (ch) {
            case 72:  // tombol panah ke atas
                if (menu > 0) {
                    menu--;
                }
                break;
            case 80:  // tombol panah ke bawah
                if (menu < n - 1) {
                    menu++;
                }
                break;
            case 77:  // tombol panah ke kanan
                quantity++;
                break;
            case 75:  // tombol panah ke kiri
                if (quantity > 1) {
                    quantity--;
                }
                break;
            case 13:  // tombol Enter
                orders[numOrders].makan = makanan[menu];
                orders[numOrders].quantity = quantity;
                numOrders++;
                menu = 0; // reset menu 1
                quantity = 1; // reset kuantitas ke 1
                break;
            default:
                getch();
                break;
        }

    }

}


void bill()
{
    fflush(stdin);
    system("cls");
    system("COLOR F8");
    int lagi;
    int item =quantity+quantity;
    char tanggal;
    float sumproduct=quantity*makanan[menu].harga * quantity;
    float harga=sumproduct+sumproduct;
    float bayar;
    float kembalian=harga-bayar;
    gotoxy(35,2);
    border();
    gotoxy(35,4);
    printf("     W A R T E G   M B A H   J E P     ");
    printf("\n\n\t\t\t\t Jl. Parikesit, Kel. Dukuh, Kec. Sidomukti, Kota Salatiga ");
    gotoxy(35,7);
    border();
    puts("");
    printf("\n\nTanggal : ");
    scanf("%[^\n]s", &tanggal);
    puts("========================================================================================================");
    puts("Daftar Pesanan Anda : ");
    printf("%d porsi %s   -    Rp%d\t\t\t\t\t%.2f\n", quantity, makanan[menu].name, makanan[menu].harga * quantity, sumproduct);
    puts("========================================================================================================");
    printf("Total Pesanan\t: %d\n", item);
    printf("Total Harga\t: %.2f\n", harga);
    kurang :
    printf("Silahkan Bayar Keseluruhan Pesanan : ");
    scanf("%f", &bayar);
    if(harga<=bayar)
    {
        puts("========================================================================================================");
        printf("Kembalian Anda\t : %.2f", kembalian);
        getch;
        home :
        printf("\nApakah Anda Ingin Memesan Lagi (y/t) : ");
        scanf("%d", &lagi);
        lagi=getchar();
        if(lagi=='y'||'Y')
        {
            main();
        }
        else if(lagi=='n'||'N')
        {
            puts("\t\tSelamat Menikmati Pesanan Anda");
            puts("\t\tTerimakasih Atas Kunjungannya");
        }
        else
        {
            system("cls");
            home();
        }
    }

    else if(bayar<harga)
    {
        puts("Mohon Maaf Uang Anda Tidak Cukup");
        puts("Silahkan Kembali Membayar Pesanan Anda");
        goto kurang;
    }
}
