#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

struct Pelanggan {
    char nama[30];
    char alamat[50];
    char noHP[15];
    char kategoricucian[30];
    char jenis[50];
};

struct Pesanan {
    Pelanggan pelanggan;
    double totalberat;
    double hargaPerKg;
    double subtotal;
    double diskon;
    double totalbayar;
    double jumlahbayar;
    double uangkembalian;
};

bool IsEmpty(const queue<Pesanan>& q) {
    return q.empty();
}

void inputDataPelanggan(Pesanan& pesanan) {
    cout << "-----------------------------------------------------------------" << endl;
    cout << "                      Input Data Pelanggan                       " << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Nama Pelanggan : ";
    cin.ignore();
    cin.getline(pesanan.pelanggan.nama, sizeof(pesanan.pelanggan.nama));
    cout << "Alamat         : ";
    cin.getline(pesanan.pelanggan.alamat, sizeof(pesanan.pelanggan.alamat));
    cout << "No Handphone   : ";
    cin.getline(pesanan.pelanggan.noHP, sizeof(pesanan.pelanggan.noHP));
    system("pause");
}

void cetakStruk(const Pesanan& pesanan) {
    cout << "=================================================================" << endl;
    cout << "                       LOVELY LAUNDRY                        " << endl;
    cout << "=================================================================" << endl;
    cout << "                      Struk Pembayaran                        " << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Nama Pelanggan    : " << pesanan.pelanggan.nama << endl;
    cout << "Alamat            : " << pesanan.pelanggan.alamat << endl;
    cout << "No Handphone      : " << pesanan.pelanggan.noHP << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Kategori Cucian   : " << pesanan.pelanggan.kategoricucian << endl;
    cout << "Jenis Cucian      : " << pesanan.pelanggan.jenis << endl;
    cout << "Berat Cucian      : " << pesanan.totalberat << " kg" << endl;
    cout << "Harga per Kg      : Rp. " << pesanan.hargaPerKg << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Subtotal          : Rp. " << pesanan.subtotal << endl;
    cout << "Diskon            : Rp. " << pesanan.diskon << endl;
    cout << "Total Bayar       : Rp. " << pesanan.totalbayar << endl;
    cout << "Tunai             : Rp. " << pesanan.jumlahbayar << endl;
    cout << "Kembalian         : Rp. " << pesanan.uangkembalian << endl;

    cout << "\nTerima kasih telah menggunakan jasa laundry kami!" << endl;
    system("pause");
}

int main() {
    queue<Pesanan> pesananQueue;
    double hargaPerKg[] = {8000, 15000, 25000, 18000, 60000};

    char pilihMenu;
    do {
        system("cls");
        cout << "=================================================================" << endl;
        cout << "                       LOVELY LAUNDRY                        " << endl;
        cout << "=================================================================" << endl;
        cout << "                            MENU                             " << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "                   1. Input Data Pelanggan                 " << endl;
        cout << "                   2. Kategori Cucian                      " << endl;
        cout << "                   3. Pembayaran                           " << endl;
        cout << "                   4. Struk Pembayaran                     " << endl;
        cout << "                   0. Keluar                               " << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Pilih menu: ";
        cin >> pilihMenu;
        system ("cls");

        switch (pilihMenu) {
            case '1': {
                Pesanan pesanan;
                inputDataPelanggan(pesanan);
                pesananQueue.push(pesanan);
                break;
            }
            case '2': {
                if (IsEmpty(pesananQueue)) {
                    cout << "Belum ada pesanan yang dimasukkan. Silakan masukkan data pelanggan terlebih dahulu." << endl;
                    system("pause");
                } else {
                    Pesanan& pesanan = pesananQueue.back();
                    int kategori;
                    do {
                        system("cls");
                        cout << "-----------------------------------------------------------------" << endl;
                        cout << "                      Kategori Cucian                        " << endl;
                        cout << "-----------------------------------------------------------------" << endl;
                        cout << "             Kategori                 Harga per(kg)" << endl;
                        cout << "-----------------------------------------------------------------" << endl;
                        cout << "1. Cuci Komplet Reguler (2-3 hari)      Rp. 8000" << endl;
                        cout << "2. Cuci Komplet Kilat (1 hari)          Rp. 15000" << endl;
                        cout << "3. Cuci Kering Express (8 jam)          Rp. 25000" << endl;
                        cout << "4. Cuci Kering Kilat (1 hari)           Rp. 18000" << endl;
                        cout << "5. Cuci Karpet (4 hari)                 Rp. 60000" << endl;
                        cout << "-----------------------------------------------------------------" << endl;
                        cout << "Pilih kategori : ";
                        cin >> kategori;
                        system("pause");

                        if (kategori == 1) {
                            strcpy(pesanan.pelanggan.kategoricucian, "Cuci Komplet Reguler (2-3 hari)");
                            pesanan.hargaPerKg = hargaPerKg[0];
                        } else if (kategori == 2) {
                            strcpy(pesanan.pelanggan.kategoricucian, "Cuci Komplet Kilat (1 hari)");
                            pesanan.hargaPerKg = hargaPerKg[1];
                        } else if (kategori == 3) {
                            strcpy(pesanan.pelanggan.kategoricucian, "Cuci Kering Express (8 jam)");
                            pesanan.hargaPerKg = hargaPerKg[2];
                        } else if (kategori == 4) {
                            strcpy(pesanan.pelanggan.kategoricucian, "Cuci Kering Kilat (1 hari)");
                            pesanan.hargaPerKg = hargaPerKg[3];
                        } else if (kategori == 5) {
                            strcpy(pesanan.pelanggan.kategoricucian, "Cuci Karpet (4 hari)");
                            pesanan.hargaPerKg = hargaPerKg[4];
                        } else {
                            cout << "Kategori tidak valid. Silakan masukkan angka 1-5." << endl;
                            system("pause");
                        }
                    } while (kategori != 1 && kategori != 2 && kategori != 3 && kategori != 4 && kategori != 5);
                }
                break;
            }
            case '3': {
                if (IsEmpty(pesananQueue)) {
                    cout << "Belum ada pesanan yang dimasukkan. Silakan masukkan data pelanggan terlebih dahulu." << endl;
                    system("pause");
                } else {
                    Pesanan& pesanan = pesananQueue.back();

                    system("cls");
                    cout << "-----------------------------------------------------------------" << endl;
                    cout << "                      Pembayaran                        " << endl;
                    cout << "-----------------------------------------------------------------" << endl;
                    cout << "Jenis Cucian      : ";
                    cin.ignore();
                    cin.getline(pesanan.pelanggan.jenis, sizeof(pesanan.pelanggan.jenis));
                    cout << "Kategori Cucian   : " << pesanan.pelanggan.kategoricucian << endl;
                    cout << "Berat Cucian (kg) : ";
                    cin >> pesanan.totalberat;

                    pesanan.subtotal = pesanan.totalberat * pesanan.hargaPerKg;

                    if (pesanan.totalberat >= 10) {
                        pesanan.diskon = 0.1 * pesanan.subtotal;
                    } else {
                        pesanan.diskon = 0;
                    }

                    pesanan.totalbayar = pesanan.subtotal - pesanan.diskon;

                    cout << "Total Bayar       : Rp. " << pesanan.totalbayar << endl;
                    do {
                        cout << "Tunai             : Rp. ";
                        cin >> pesanan.jumlahbayar;
                        if (pesanan.jumlahbayar < pesanan.totalbayar) {
                            cout << "Jumlah uang kurang. Mohon masukkan jumlah uang yang sesuai." << endl;
                        }
                    } while (pesanan.jumlahbayar < pesanan.totalbayar);

                    pesanan.uangkembalian = pesanan.jumlahbayar - pesanan.totalbayar;
                    cout << "Uang Kembalian    : " << pesanan.uangkembalian << endl;
                    system("pause");
                }
                break;
            }
            case '4': {
                if (IsEmpty(pesananQueue)) {
                    cout << "Belum ada pesanan yang dimasukkan. Silakan masukkan data pelanggan terlebih dahulu." << endl;
                    system("pause");
                } else {
                    Pesanan& pesanan = pesananQueue.back();
                    cetakStruk(pesanan);
                    system("pause");
                }
                break;
            }
            case '0': {
                cout << "Terima kasih sudah memakai layanan kami. Sampai jumpa lagi!!!" << endl;
                system("pause");
                break;
            }
            default:
                cout << "Menu tidak valid. Silakan masukkan angka 0-4." << endl;
                system("pause");
        }
        system("cls");
    } while (pilihMenu != '0');

    return 0;
}