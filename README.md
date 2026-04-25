# Smart Parking System - UTS Mikrokontroler

---

## 👤 Identitas Mahasiswa
* **Nama:** Intan Rizky Yuniar
* **NIM:** 24090620034
* **Mata Kuliah:** Praktek Mikrokontroller
* **Program Studi:** D4 Teknik Elektronika

---

## 📝 Deskripsi Proyek
**Smart Parking System** merupakan solusi prototipe untuk digitalisasi lahan parkir. Sistem ini menggunakan sensor dan mikrokontroler untuk mengatur alur kendaraan masuk, memberikan informasi ketersediaan slot secara visual, dan mengelola sirkulasi udara di dalam area parkir untuk meningkatkan kenyamanan serta efisiensi manajemen lahan.

## 🛠️ Implementasi Materi Praktikum
Proyek ini mengintegrasikan berbagai konsep inti dari praktikum mikrokontroler:
* **Input Analog:** Potensiometer sebagai simulator sensor pembaca kapasitas kendaraan.
* **Input Digital:** Push Button sebagai pemicu (trigger) instruksi pembukaan pintu.
* **Output PWM:** Motor Servo untuk penggerak palang pintu dengan sudut yang presisi.
* **Komunikasi I2C:** LCD 16x2 untuk efisiensi pin data dalam menampilkan informasi sistem.
* **Aktuator DC:** Motor DC sebagai simulasi sistem ventilasi udara otomatis.

## 🚀 Cara Kerja Sistem
1. **Monitoring Kapasitas:** Potensiometer digunakan untuk mensimulasikan jumlah kendaraan. Data ini diolah oleh Arduino dan ditampilkan secara real-time pada **LCD 16x2**.
2. **Indikator Visual (LED):**
   - **LED Hijau:** Slot parkir masih banyak tersedia.
   - **LED Kuning:** Slot parkir mulai penuh (Waspada).
   - **LED Merah:** Kapasitas parkir sudah penuh.
3. **Kendali Akses (Servo & LCD):** - Pengendara menekan **Push Button** untuk meminta akses masuk.
   - Jika slot tersedia, **LCD** menampilkan pesan "Silakan Masuk" dan **Servo** berputar 90° untuk membuka palang.
   - Jika penuh, **LCD** menampilkan "Parkir Penuh" dan **Servo** tetap terkunci (0°), meskipun tombol ditekan.
4. **Sistem Ventilasi:** **Motor DC** akan aktif secara otomatis sebagai kipas sirkulasi udara jika terdeteksi adanya kendaraan di dalam area parkir.

## 🔌 Rangkaian (Wiring)
| Komponen | Pin Arduino | Fungsi |
| :--- | :--- | :--- |
| **Push Button** | D2 | Input Tombol Buka Palang |
| **Motor Servo** | D9 | Output Penggerak Palang |
| **LCD 16x2 I2C** | A4 (SDA), A5 (SCL) | Display Informasi Utama |
| **Potensiometer** | A0 | Input Simulasi Kapasitas |
| **LED Hijau** | D13 | Indikator Tersedia |
| **LED Kuning** | D11 | Indikator Waspada |
| **LED Merah** | D12 | Indikator Penuh |
| **Motor DC** | D3 | Output Kipas Sirkulasi |

---
## 📸 Dokumentasi & Demo
### Video Demonstrasi
[![Video Demo Smart Parking](https://img.youtube.com/vi/AW9QHFLfN3U/0.jpg)](https://www.youtube.com/watch?v=AW9QHFLfN3U)
* **Simulasi Tinkercad:** https://www.tinkercad.com/things/4OfHwppKm3U-cool-blorr/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=DKbZeGkXEC2trWeNreHmRA693tiOKtRsmGbn7QqQP0o
* **Video Demo (YouTube):** https://youtu.be/AW9QHFLfN3U
---
*Dibuat untuk memenuhi syarat UTS Praktikum Mikrokontroler.*
