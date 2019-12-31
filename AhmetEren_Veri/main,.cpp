

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

void ara(string txt, string word, string pdf, string html, string arananKelime) {

	string okunan;
	string txtDosya, wordDosya, pdfDosya, htmlDosya;
	int txtSayac = 0, wordSayac = 0, pdfSayac = 0, htmlSayac = 0;

	float txtSure, wordSure, pdfSure, htmlSure;

	clock_t ilk, son;

	/////////////////////////////////////////////////

	ifstream file(txt);
	
	if (file.is_open()) {
		while (!file.eof())
		{
			getline(file, okunan);
			txtDosya += okunan;
		}
		file.close();
	}
	else {
		cout << "Text dosyasý bulunamadý." << endl;
	}
	file.close();
	
	/////////////////////////////////////////////////

	file.open(word);

	if (file.is_open()) {
		while (!file.eof())
		{
			getline(file, okunan);
			wordDosya += okunan;
		}
		file.close();
	}
	else {
		cout << "Word dosyasi bulunamadý." << endl;
	}
	file.close();

	/////////////////////////////////////////////////

	file.open(pdf);
	if (file.is_open()) {
		while (!file.eof())
		{
			getline(file, okunan);
			pdfDosya += okunan;
		}
		file.close();
	}
	else {
		cout << "PDF dosyasi acilamadi." << endl;
	}
	file.close();

	/////////////////////////////////////////////////

	file.open(html);
	if (file.is_open()) {
		while (!file.eof())
		{
			getline(file, okunan);
			htmlDosya += okunan;
		}
		file.close();
	}
	else {
		cout << "HTML dosyasi acilamadi." << endl;
	}


	ofstream sonuc("aramaSonuc.txt", ios::out);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	ilk = clock();
	for (int i = 0; i <= txtDosya.length() - arananKelime.length(); i++) 
	{
		int j = 0;

		while (j < arananKelime.length() && arananKelime[j] == txtDosya[i + j]) 
		{
			j++;
		}
		if (j == arananKelime.length())
		{
			txtSayac++;
			sonuc << i << ". kelime " << endl;
		}
	}
	son = clock();

	txtSure = ((float)son - ilk) / CLOCKS_PER_SEC;


	sonuc << endl << endl << "Text dosyasýnda " << txtSure << " saniyede " << txtSayac << " adet sonuc bulundu." << endl << endl;
	sonuc << "///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////";

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	string pdfSonuc = "";

	ilk = clock();
	for (int i = 0; i <= pdfDosya.length() - arananKelime.length(); i++) 
	{
		int j = 0;

		while (j < arananKelime.length() && arananKelime[j] == pdfDosya[i + j]) 
		{
			j++;
		}
		if (j == arananKelime.length())
		{
			pdfSayac++;
			sonuc << i << ". kelime " << endl;

		}
	}
	son = clock();

	pdfSure = ((float)son - ilk) / CLOCKS_PER_SEC;

	sonuc << endl << endl << "PDF dosyasýnda " << pdfSure << " saniyede " << pdfSayac << " adet sonuc bulundu." << endl << endl;
	sonuc << "///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////";

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	string wordSonuc = "";

	ilk = clock();
	for (int i = 0; i <= wordDosya.length() - arananKelime.length(); i++) 
	{
		int j = 0;

		while (j < arananKelime.length() && arananKelime[j] == wordDosya[i + j]) 
		{
			j++;
		}
		if (j == arananKelime.length())
		{
			wordSayac++;
			sonuc << i << ". kelime " << endl;

		}
	}
	son = clock();

	wordSure = ((float)son - ilk) / CLOCKS_PER_SEC;

	sonuc << endl << endl << "Word dosyasýnda " << wordSure << " saniyede " << wordSayac << " adet sonuc bulundu." << endl << endl;
	sonuc << "///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////";

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	string htmlSonuc = "";

	ilk = clock();
	for (int i = 0; i <= htmlDosya.length() - arananKelime.length(); i++) 
	{
		int j = 0;

		while (j < arananKelime.length() && arananKelime[j] == htmlDosya[i + j]) 
		{
			j++;
		}
		if (j == arananKelime.length())
		{
			htmlSayac++;
			sonuc << i << ". kelime " << endl;

		}
	}
	son = clock();

	htmlSure = ((float)son - ilk) / CLOCKS_PER_SEC;

	sonuc << endl << endl << "HTML dosyasýnda " << htmlSure << " saniyede " << htmlSayac << " adet sonuc bulundu." << endl << endl;
	sonuc << "///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////";

	sonuc.close();

	system("notepad aramaSonuc.txt");
}


int main()
{
	string txt_dosyasi = "textveri.txt";
	string word_dosyasi = "wordveri.docx";
	string pdf_dosyasi = "pdfveri.pdf";
	string html_dosyasi = "htmlveri.html";

	string arananKelime;

	cout << "Aranacak Kelimeyi Giriniz :";   
	getline(cin, arananKelime);

	//arananKelime = " " + arananKelime + " ";    //Sadece aranan kelimenin bulunmasý için baþýna ve sonuna boþluk konuldu.

	ara(txt_dosyasi, word_dosyasi, pdf_dosyasi, html_dosyasi, arananKelime);


	system("pause");

	return 0;
}


