#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;


int main() {
	setlocale(LC_ALL, "Turkish"); // Yorum sat�lar�ndaki t�rk�e harfler hata verme ihtimaline kar�� t�rk�e k�t�phane
	float a, b, n, t,e,x,d,y; //Bu sat�rda t�m de�erleri float t�r�nden at�yoruzki ilerde tamsay� sonu�lar� almayal�m.
	float lhf, rhf, mf, lhft, rhft, mft; //Bu sat�rda t�m de�erleri float t�r�nden at�yoruzki ilerde tamsay� sonu�lar� almayal�m.
	lhft = 0;// t�m lhf  de�erlerini toplamadan �nce 34. sat�rda  hata almas�n diye 0 de�eri veriyorum.
	rhft = 0;
	mft = 0;

	cout << "a  :  ";
	cin >> a;
	cout << "b  :  ";
	cin >> b;
	cout << "n  :  ";
	cin >> n;
	cout << "---------------------------------------------------------------------------------------";
	cout << endl << setw(10) << "i" << setw(14) << "x[i]" << setw(19) << "epsilon[i]" << setw(12) << "LHF" << setw(12) << "RHF" << setw(12) << "MF" << endl;
	cout << "---------------------------------------------------------------------------------------"<<endl;// burada kadar inputlar�m�z� ald�k ve g�zel bir g�r�nt� i�in biraz �ekillendirdik.
	d = (b - a) / n;// Deltay� hesaplad�k.

	for (float i = 1; i < n+1; i++) {     //D�ng�y� tekrar� i�in n+1 e kadar for d�ng�s� kulland�rtt�m.
		x = (a + ((i - 1) * d));           //X_i yi resimdeki gibi bulduk.
		y = a + (i) * d;                   //Bu y de�eri rhf k�sm�n� alabilmesi i�in (i-1) k�sm� olmadan yazd�k.
		e = x + (d / 2);                   // Epsilonu resimde verdi�i gibi hesaplad�k.
		
		rhf = (y * y * y + 4 * y) * d;     //gelen de�erleri fonksiyonlarda yerlerine yazd�rd�k ve sonras�nda alan� alabilmesi i�in d(delta) ile �arpt�rd�k.
		lhf = (x * x * x + 4 * x) * d;
		mf = (e * e * e + 4 * e)*d ;

		cout <<setw(10)<<i<<setw(13)<< x<<setw(16)<< e <<setw(15)<<lhf<<setw(13)<<rhf<<setw(13)<<mf<< endl; // sonu�lar� ekrana yazd�r�yoruz.
		lhft = lhft + lhf;// her d�ng� tamamland���nda lhft de�eri kendini ve lhf de�eri ile toplayarak toplam de�eri ald�r�cak.
		rhft = rhft + rhf;
		mft = mft + mf;
	}

	cout << "----------------------------------------------"<<endl;   
	cout << "---------------  INTEGRAL RESULTS  -----------"<<endl;
	cout << "f(x)=x^3 + 4x from[" << a << "," << b << "] with " <<endl<< n << " intervals"; // sonu�lar� ekrana yazd�r�yoruz
	cout << "----------------------------------" << endl;
	cout << "MIDPOINT RULE                   : " << mft << endl;               
	cout << "LEFT HAND RULE                  : " << lhft << endl;
	cout << "RIGHT HAND  RULE                : " << rhft << endl;
	cout << "----------------------------------------------" << endl;  //son
}

