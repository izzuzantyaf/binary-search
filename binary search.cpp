#include <iostream>

using namespace std;

// deklarasi fungsi pengurutan menggunakan algoritma bubble sort
int bubbleSort(int data[], int n) {

	// deklarasi variabel untuk iterator
	int i, j;

	// deklarasi variabel sementara pembantu pengurutan
	int temp;

	/////////// ALGORITMA BUBBLE SORT
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < (n - i - 1); j++) {
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	/////////// akhir dari ALGORITMA BUBBLE SORT
	return 0;
}

// deklarasi fungsi pencarian dengan algoritma binary search
int binarySearch(int cari, int data[], int n) {

	int awal = 0,
		tengah,
		akhir = n,
		indexKetemu;

	tengah = (awal + akhir) / 2;

	while (cari != data[tengah]) {

		for (int i = 0; i < n; i++)
		{
			if (cari==data[i])
			{
				indexKetemu = i;
				if (indexKetemu > tengah)
				{
					awal = tengah + 1;
				}
				else if (indexKetemu < tengah)
				{
					akhir = tengah - 1;
				}
			}
		}
		tengah = (awal + akhir) / 2;
	}

	return tengah;
}

int main()
{
    // deklarasi array dan variabel
	int data[20],
		n,
		cari,
		hasil;

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
	cout << "Data yang anda cari : "; cin >> cari;

	// melakukan pencarian dengan algoritma biary search
	hasil = binarySearch(cari, data, n);

	cout << cari << " ditemukan pada data ke-" << hasil+1 << endl;

	return 0;
}