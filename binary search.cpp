#include <iostream>

using namespace std;

// deklarasi fungsi pencarian dengan algoritma binary search
int binarySearch(int cari, int data[], int n) {

	// deklarasi variabel
	int awal = 0,
		tengah,
		akhir = n,
		indexKetemu,
		ada=0,
		i;

	// tengah adalah indeks tengah dari array data[]
	tengah = (awal + akhir) / 2;

	// selama data yang dicari belum ketemu
	while (cari != data[tengah]) {

		// cek satu per satu dari elemen awal sampai elemen akhir
		for (i = awal; i < akhir; i++)
		{
			// jika data yang dicari ada
			if (cari==data[i])
			{
				// isi variabel ada dengan nilai 1
				ada = 1;
				// jika indeks data yang dicari lebih dari nilai tengah
				if (i > tengah)
				{
					// ubah nilai awal menjadi nilai tengah ditambah 1
					awal = tengah + 1;
				}
				// jika indeks data yang dicari lebih dari nilai tengah
				else if (i < tengah)
				{
					// ubah nilai akhir menjadi nilai tengah dikurangi 1
					akhir = tengah - 1;
				}
			}
			
		}
		// jika pengecekan sudah mencapai indeks terakhir dan data yang dicari tidak ketemu
		if (i == n && ada == 0)
		{
			// hentikan pencarian (keluar dari pengulangan while)
			break;
		}
		// ubah nilai tengah menjadi
		tengah = (awal + akhir) / 2;
	}

	// jika data yang dicari ketemu
	if (ada == 1) {
		// simpan indeks data yang dicari ke dalam indexKetemu
		indexKetemu = tengah;
	}
	else {
		// jika tidak ketemu maka isi indexKetemu dengan NULL
		indexKetemu = NULL;
	}

	return indexKetemu;
}

int main()
{
    // deklarasi array dan variabel
	int n,
		cari,
		hasil,
		data[20];

	// input banyaknya data dari user
	cout << "Masukkan jumlah data yang anda inginkan : "; cin >> n;

	// mendefinisikan jumlah elemen data[] sesuai yang user inputkan
	data[n];

	// input nilai-nilai data dari user
	cout << endl << "Masukkan data-data anda" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Data ke-" << i + 1 << ": "; cin >> data[i];
	}

	// input nilai yang ingin dicari
	cout << endl << "Data yang anda cari : "; cin >> cari;

	// melakukan pencarian dengan algoritma biary search
	hasil = binarySearch(cari, data, n);

	// jika yang dicari ada
	if (hasil != 0)
	{
		// tampilkan data yang dicari pada indeks ke berapa
		cout << cari << " ditemukan pada data ke-" << hasil + 1 << endl;
	}
	else {
		// jika tidak ketemu tampilkan pesan ini
		cout << "Data tidak ditemukan" << endl;
	}

	return 0;
}