#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string nama;
    string nrp;
    int usia;
    string jenisKelamin;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(const Mahasiswa mahasiswas[], int jumlahData) {
    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Mahasiswa ke-" << (i + 1) << endl;
        cout << "NRP: " << mahasiswas[i].nrp << endl;
        cout << "Nama: " << mahasiswas[i].nama << endl;
        cout << "Usia: " << mahasiswas[i].usia << endl;
        cout << "Jenis Kelamin: " << mahasiswas[i].jenisKelamin << endl;
        cout << endl;
    }
}

int main() {
    const int maksimalMahasiswa = 10; // Jumlah maksimum mahasiswa yang dapat disimpan
    Mahasiswa mahasiswas[maksimalMahasiswa]; // Array untuk menyimpan data mahasiswa
    int jumlahData = 0; // Jumlah data mahasiswa yang sudah disimpan

    while (true) {
        cout << "Pilih operasi yang ingin dilakukan:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data Mahasiswa" << endl;
        cout << "3. Hapus Data Mahasiswa" << endl;
        cout << "4. Ubah Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1: // Menampilkan data mahasiswa
                if (jumlahData == 0) {
                    cout << "Tidak ada data mahasiswa yang tersimpan.\n" << endl;
                } else {
                    tampilkanData(mahasiswas, jumlahData);
                }
                break;

            case 2: // Menambah data mahasiswa baru
                if (jumlahData < maksimalMahasiswa) {
                    cout << "Masukkan NRP Mahasiswa: ";
                    cin >> mahasiswas[jumlahData].nrp;
                    cout << "Masukkan Nama Mahasiswa: ";
                    cin.ignore(); // Menghapus karakter newline (\n) dari buffer sebelum membaca input
                    getline(cin, mahasiswas[jumlahData].nama);
                    cout << "Masukkan Usia Mahasiswa: ";
                    cin >> mahasiswas[jumlahData].usia;
                    cout << "Masukkan Jenis Kelamin Mahasiswa (L/P): ";
                    cin >> mahasiswas[jumlahData].jenisKelamin;
                    jumlahData++;
                    cout << "Data mahasiswa berhasil ditambahkan.\n" << endl;
                } else {
                    cout << "Batas maksimum data mahasiswa telah tercapai." << endl;
                }
                break;

            case 3: // Menghapus data mahasiswa
                if (jumlahData == 0) {
                    cout << "Tidak ada data mahasiswa yang tersimpan." << endl;
                } else {
                    cout << "Masukkan NRP Mahasiswa yang ingin dihapus: ";
                    string nrpHapus;
                    cin >> nrpHapus;

                    bool ditemukan = false;
                    for (int i = 0; i < jumlahData; ++i) {
                        if (mahasiswas[i].nrp == nrpHapus) {
                            // Menggeser data ke kiri untuk menghapus
                            for (int j = i; j < jumlahData - 1; ++j) {
                                mahasiswas[j] = mahasiswas[j + 1];
                            }
                            jumlahData--;
                            ditemukan = true;
                            cout << "Data mahasiswa berhasil dihapus.\n" << endl;
                            break;
                        }
                    }

                    if (!ditemukan) {
                        cout << "NRP Mahasiswa tidak ditemukan.\n" << endl;
                    }
                }
                break;

            case 4: // Mengubah data mahasiswa
                if (jumlahData == 0) {
                    cout << "Tidak ada data mahasiswa yang tersimpan.\n" << endl;
                } else {
                    cout << "Masukkan NRP Mahasiswa yang ingin diubah: ";
                    string nrpUbah;
                    cin >> nrpUbah;

                    bool ditemukan = false;
                    for (int i = 0; i < jumlahData; ++i) {
                        if (mahasiswas[i].nrp == nrpUbah) {
                            cout << "Masukkan Nama Mahasiswa yang baru: ";
                            cin.ignore();
                            getline(cin, mahasiswas[i].nama);
                            cout << "Masukkan Usia Mahasiswa yang baru: ";
                            cin >> mahasiswas[i].usia;
                            cout << "Masukkan Jenis Kelamin Mahasiswa yang baru (L/P): ";
                            cin >> mahasiswas[i].jenisKelamin;
                            ditemukan = true;
                            cout << "Data mahasiswa berhasil diubah.\n" << endl;
                            break;
                        }
                    }

                    if (!ditemukan) {
                        cout << "NRP Mahasiswa tidak ditemukan." << endl;
                    }
                }
                break;

            case 5: // Keluar dari program
                cout << "Program selesai.\n" << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
        }
    }

    return 0;
}