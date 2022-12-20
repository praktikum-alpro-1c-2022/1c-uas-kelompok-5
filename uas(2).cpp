#include <iostream>
#include <ctime>

using namespace std;

struct pesanan{
    int tipe_kamar, total_harga, malam, uang_pembayaran, uang_kembalian;
    string nama;
};

void tipeKamar();
void spesifikasiKamar(int pilihan, pesanan obj);
void konfirmasiPesanan(int tipe_kamar, int malam, string nama, pesanan obj);
void strukPesanan(pesanan obj);
int main();

int main() {
    pesanan obj;
    int tipe_kamar;
    string kamar[2] = { "Standart Room", "Family Room" };

    hotel:

        tipeKamar();

        cout << "\nMasukkan Pilihan Tipe Kamar (1-" << *(&kamar + 1) - kamar << ") : ";
        cin >> tipe_kamar;

        switch (tipe_kamar) {

            case 1:

                spesifikasiKamar(1, obj);

                break;

            case 2:

                spesifikasiKamar(2, obj);

                break;

            default:

                cout << "Pilihan anda tidak ada didalam daftar list." << endl;
                system("cls");
                goto hotel;

        }

}

void tipeKamar() {

    string kamar[3] = { "Standart Room", "Family Room" };

    cout << "\n=========================" << endl;
    cout << "        Tipe Kamar        " << endl;
    cout << "=========================" << endl << endl;

    for(int i =0; i <= 1; i++) {

        cout << i+1 << ". " << kamar[i] << endl;

    }

}

void spesifikasiKamar(int pilihan, pesanan obj) {

    int t_nginap;
    string v_booking, nama;

    if (pilihan == 1) {

        system("cls");

        cout << "\n=========================" << endl;
        cout << "    Spesifikasi Kamar        " << endl;
        cout << "=========================" << endl << endl;

        cout << "1. Memiliki 2 Kasur Dewasa" << endl;
        cout << "2. Memiliki AC" << endl << endl;
        cout << "* Kamar dengan tipe Standart Room memiliki harga Rp 2.700.000 per Malam." << endl;
        cout << "Apakah anda ingin melanjutkan pembookingan kamar? (Y/T) : ";
        cin >> v_booking;

        if (v_booking == "y" || v_booking == "Y") {


            cout << "Nama Pembooking : ";
            cin >> nama;
            cout << "Berapa Malam anda menginap ? : ";
            cin >> t_nginap;

            system("cls");

            obj.nama = nama;
            obj.malam = t_nginap;

            konfirmasiPesanan(1, t_nginap, nama, obj);

        } else {

            system("cls");
            main();

        }

    } else if (pilihan == 2) {

        system("cls");

        cout << "\n=========================" << endl;
        cout << "    Spesifikasi Kamar        " << endl;
        cout << "=========================" << endl << endl;

        cout << "1. Memiliki 3 Kasur Dewasa" << endl;
        cout << "2. Memiliki 2 Kasur Anak-Anak" << endl;
        cout << "3. Memiliki AC" << endl;
        cout << "\n* Kamar dengan tipe Standart Room memiliki harga Rp 4.200.000 per Malam." << endl;
        cout << "Apakah anda ingin melanjutkan pembookingan kamar? (Y/T) : ";
        cin >> v_booking;

        if (v_booking == "y" || v_booking == "Y") {

            cout << "Nama Pembooking : ";
            cin >> nama;
            cout << "Berapa Malam anda menginap ? : ";
            cin >> t_nginap;

            system("cls");

            obj.nama = nama;
            obj.malam = t_nginap;

            konfirmasiPesanan(2, t_nginap, nama, obj);


        } else {

            system("cls");
            main();

        }


    } else {

        cout << "Pilihan anda tidak ada didalam list." << endl;
        system("cls");
        main();

    }

}

void konfirmasiPesanan(int tipe_kamar, int malam, string nama, pesanan obj) {

    string v_pesanan;

    int total_harga, uang_pembayaran, uang_kembalian;

    if (tipe_kamar == 1) {

        total_harga = 2700000 * malam;

        cout << "===================================" << endl;
        cout << "          Pesanan Anda             " << endl;
        cout << "===================================" << endl << endl;

        cout << "Nama Pembooking : " << nama << endl;
        cout << "1. Kamar dengan tipe standart room." << endl;
        cout << "2. Harga kamar permalam Rp 2.700.000 x " << malam << endl;
        cout << "3. Total harga : Rp " << total_harga << endl << endl;
        cout << "Apakah pesanan sudah sesuai ? (Y/T) : ";
        cin >> v_pesanan;

        if (v_pesanan == "y" || v_pesanan == "Y") {

            pembayaran_1:

                cout << "\nTotal yang anda harus bayar adalah Rp " << total_harga << "." << endl;
                cout << "Masukkan uang pembayaran anda : ";
                cin >> uang_pembayaran;

                if (uang_pembayaran < total_harga) {

                    cout << "Uang anda tidak mencukupi untuk pembayaran." << endl << endl;

                    goto pembayaran_1;

                } else {

                    uang_kembalian = uang_pembayaran - total_harga;

                    system("cls");

                    obj.total_harga = total_harga;
                    obj.uang_pembayaran = uang_pembayaran;
                    obj.uang_kembalian = uang_kembalian;
                    obj.tipe_kamar = tipe_kamar;

                    strukPesanan(obj);

                }

        } else {

            system("cls");
            spesifikasiKamar(tipe_kamar, obj);

        }

    } else {

        total_harga = 4200000 * malam;

        cout << "===================================" << endl;
        cout << "          Pesanan Anda             " << endl;
        cout << "===================================" << endl << endl;

        cout << "Nama Pembooking : " << nama << endl;
        cout << "1. Kamar dengan tipe standart room." << endl;
        cout << "2. Harga kamar permalam Rp 4.200.000 x " << malam << endl;
        cout << "3. Total harga : Rp " << total_harga << endl << endl;
        cout << "Apakah pesanan sudah sesuai ? (Y/T) : ";
        cin >> v_pesanan;

        if (v_pesanan == "y" || v_pesanan == "Y") {

            pembayaran_2:

                cout << "\nTotal yang anda harus bayar adalah Rp " << total_harga << "." << endl;
                cout << "Masukkan uang pembayaran anda : ";
                cin >> uang_pembayaran;

                if (uang_pembayaran < total_harga) {

                    cout << "Uang anda tidak mencukupi untuk pembayaran." << endl << endl;

                    goto pembayaran_2;

                } else {

                    uang_kembalian = uang_pembayaran - total_harga;

                    system("cls");

                    obj.total_harga = total_harga;
                    obj.uang_pembayaran = uang_pembayaran;
                    obj.uang_kembalian = uang_kembalian;
                    obj.tipe_kamar = tipe_kamar;

                    strukPesanan(obj);

                }

        } else {

            system("cls");
            spesifikasiKamar(tipe_kamar, obj);

        }

    }

}

void strukPesanan(pesanan obj) {

    time_t t_now = time(0);
    char* dt = ctime(&t_now);

    switch(obj.tipe_kamar) {

        case 1:

            cout << "===================================" << endl;
            cout << "          Struk Pesanan             " << endl;
            cout << "===================================" << endl << endl;

            cout << "Nama Pembooking    : " << obj.nama << endl << endl;
            cout << "1. Tipe Kamar      : Standart Room." << endl;
            cout << "2. Lama Inap       : " << obj.malam << " Malam" << endl;
            cout << "3. Uang Pembayaran : Rp " << obj.uang_pembayaran << endl;
            cout << "4. Uang Kembalian  : Rp " << obj.uang_kembalian << endl << endl;
            cout << "Waktu Booking      : " << dt << endl << endl;

            cout << "===================================" << endl;
            cout << "            Terimakasih             " << endl;
            cout << "===================================" << endl << endl;

            break;

        case 2:

            cout << "===================================" << endl;
            cout << "          Struk Pesanan             " << endl;
            cout << "===================================" << endl << endl;

            cout << "Nama Pembooking    : " << obj.nama << endl << endl;
            cout << "1. Tipe Kamar      : Family Room." << endl;
            cout << "2. Lama Inap       : " << obj.malam << " Malam" << endl;
            cout << "3. Uang Pembayaran : Rp " << obj.uang_pembayaran << endl;
            cout << "4. Uang Kembalian  : Rp " << obj.uang_kembalian << endl << endl;
            cout << "Waktu Booking      : " << dt << endl << endl;

            cout << "===================================" << endl;
            cout << "            Terimakasih             " << endl;
            cout << "===================================" << endl << endl;

            break;

    }

}
