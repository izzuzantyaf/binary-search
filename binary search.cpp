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

	tengah = (awal + akhir) / 2;

	while (cari != data[tengah]) {

		for (i = awal; i < akhir; i++)
		{
			if (cari==data[i])
			{
				ada = 1;
				if (i > tengah)
				{
					awal = tengah + 1;
				}
				else if (i < tengah)
				{
					akhir = tengah - 1;
				}
			}
			
		}
		if (i == n && ada == 0)
		{
			break;
		}
		tengah = (awal + akhir) / 2;
	}

	if (ada == 1) {
		indexKetemu = tengah;
	}
	else {
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

	if (hasil != 0)
	{
		cout << cari << " ditemukan pada data ke-" << hasil + 1 << endl;
	}
	else {
		cout << "Data tidak ditemukan" << endl;
	}

	return 0;
}