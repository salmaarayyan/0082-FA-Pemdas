/**
 * @mainpage Penilaian Kelulusan Mata Kuliah
 * 
 * @section intro_sec Pendahuluan
 * Penilaian kelulusan mata kuliah adalah sebuah program yang dapat menampilkan informasi kelulusan mata kuliah berdasarkan nilai presensi, activity, exercise, dan tugas akhir
 * 
 * @section note_sec Struktur Program
 * Program ini terdiri dari 1 base class dan 2 derived class.
 * - \b MataKuliah : kelas dasar yang berisi informasi mata kuliah.
 * - \b Pemprograman : kelas turunan yang menangani nilai pemprograman.
 * - \b Jaringan : kelas turunan yang menangani nilai jaringan.
 */
/**
 * @file UASPemdas.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class MataKuliah
 * @brief Kelas dasar yang berisi informasi mata kuliah
 * 
 */
class MataKuliah {
private:
    float Presensi;
    float Activity;
    float Exercise;
    float tugasAkhir;

public:
    /**
     * @brief konstruktor untuk mata kuliah
     * 
     */
    MataKuliah() {
        Presensi = 0.0;
        Activity = 0.0;
        Exercise = 0.0;
        tugasAkhir = 0.0;  
    }
    
    virtual string namaMataKuliah() {return ""; }
    virtual void inputNilai() {}
    virtual float hitungNilaiAkhir() {return 0.0;}
    virtual void cekKelulusan() {}

    void setPresensi(float nilai1) {  
        this->Presensi = nilai1;
    }
    float getPresensi() {
        return Presensi;
    }

    void setActivity(float nilai2) {
        this->Activity = nilai2;
    }
    float getActivity() {
        return Activity;
    }

    void setExercise(float nilai3) {
        this->Activity = nilai3;
    }
    float getExercise() {
        return Exercise;
    }

    void settugasAkhir(float nilai4) {
        this->Activity = nilai4;
    }
    float gettugasAkhir() {
        return tugasAkhir;
    }
};

/**
 * @class Pemprograman 
 * 
 */
//membuat class pemprograman, turunan dari class matakuliah (inheritance)
class Pemprograman : public MataKuliah {
public:
    string namaMataKuliah() {
        return "Pemprograman";
    }

    void inputNilai() {
        cout << "Masukkan nilai presensi : ";
        float nilPresensi;
        cin >> nilPresensi;
        setPresensi(nilPresensi); 
        cout << "Masukkan nilai activity : ";
        float nilActivity;
        cin >> nilActivity;
        setActivity(nilActivity);

        cout << "Masukkan nilai exercise : ";
        float nilExercise;
        cin >> nilExercise;
        setExercise(nilExercise);

        cout << "Masukkan nilai tugas Akhir : ";
        float niltugasAkhir;
        cin >> niltugasAkhir;
        settugasAkhir(niltugasAkhir);
    }

    float hitungNilaiAkhir() {
        return (getPresensi() * 0.1) + (getActivity() * 0.2) + (getExercise() * 0.3) + (gettugasAkhir() * 0.4);
    }

    void cekKelulusan() {
        float nilaiAkhir = hitungNilaiAkhir();
        cout << "Nilai akhir : " << nilaiAkhir << endl;
        if (nilaiAkhir >= 75) { 
            cout << "Selamat anda dinyatakan Lulus" << endl;
        }
        else {
            cout <<"Anda dinyatakan Tidak Lulus" << endl;
        }
    }   
};

/**
 * @class Jaringan 
 * 
 */
class Jaringan : public MataKuliah {
public:
    string namaMataKuliah() {
        return "Jaringan";
    }
    void inputNilai() {
        cout << "Masukkan nilai activity : ";
        float nilActivity;
        cin >> nilActivity;
        setActivity(nilActivity);

        cout << "Masukkan nilai exercise : ";
        float nilExercise;
        cin >> nilExercise;
        setExercise(nilExercise);
    }
    float hitungNilaiAkhir() {
        return (getActivity() * 0.2) + (getExercise() * 0.3);
    }
    void cekKelulusan() {
        float nilaiAkhir = hitungNilaiAkhir();
        cout << "Nilai akhir : " << nilaiAkhir << endl;
        if (nilaiAkhir >= 75) {
            cout << "Selamat anda dinyatakan Lulus" << endl;
        }
        else {
            cout <<"Anda dinyatakan Tidak Lulus" << endl;
        }
    }   
};

int main() {
    char pilih;
    MataKuliah* mataKuliah;
    Pemprograman pemprograman; 
    Jaringan jaringan;

    cout << "Pilih Mata Kuliah : " << endl;
    cout << "1. Pemprograman" << endl;
    cout << "2. Jaringan" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> pilih;

    switch (pilih) {
        case '1':
            mataKuliah = &pemprograman;
            cout << "Mata Kuliah " << mataKuliah->namaMataKuliah() << endl;
            pemprograman.inputNilai();
            mataKuliah->cekKelulusan();
            break;
        case '2':
            mataKuliah = &jaringan;
            cout << "Mata Kuliah " << mataKuliah->namaMataKuliah() << endl;
            mataKuliah->inputNilai();
            mataKuliah->cekKelulusan();
            break;
        case '3':
            cout << "Keluar dari program" << endl;
            return 0;
        default:
        cout << "Pilihan tidak valid" << endl;
        break;
    }
}