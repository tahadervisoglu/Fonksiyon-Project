#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;


int main() {
	setlocale(LC_ALL, "Turkish"); // Yorum satýlarýndaki türkçe harfler hata verme ihtimaline karþý türkçe kütüphane
	float a, b, n, t,e,x,d,y; //Bu satýrda tüm deðerleri float türünden atýyoruzki ilerde tamsayý sonuçlarý almayalým.
	float lhf, rhf, mf, lhft, rhft, mft; //Bu satýrda tüm deðerleri float türünden atýyoruzki ilerde tamsayý sonuçlarý almayalým.
	lhft = 0;// tüm lhf  deðerlerini toplamadan önce 34. satýrda  hata almasýn diye 0 deðeri veriyorum.
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
	cout << "---------------------------------------------------------------------------------------"<<endl;// burada kadar inputlarýmýzý aldýk ve güzel bir görüntü için biraz þekillendirdik.
	d = (b - a) / n;// Deltayý hesapladýk.

	for (float i = 1; i < n+1; i++) {     //Döngüyü tekrarý için n+1 e kadar for döngüsü kullandýrttým.
		x = (a + ((i - 1) * d));           //X_i yi resimdeki gibi bulduk.
		y = a + (i) * d;                   //Bu y deðeri rhf kýsmýný alabilmesi için (i-1) kýsmý olmadan yazdýk.
		e = x + (d / 2);                   // Epsilonu resimde verdiði gibi hesapladýk.
		
		rhf = (y * y * y + 4 * y) * d;     //gelen deðerleri fonksiyonlarda yerlerine yazdýrdýk ve sonrasýnda alaný alabilmesi için d(delta) ile çarptýrdýk.
		lhf = (x * x * x + 4 * x) * d;
		mf = (e * e * e + 4 * e)*d ;

		cout <<setw(10)<<i<<setw(13)<< x<<setw(16)<< e <<setw(15)<<lhf<<setw(13)<<rhf<<setw(13)<<mf<< endl; // sonuçlarý ekrana yazdýrýyoruz.
		lhft = lhft + lhf;// her döngü tamamlandýðýnda lhft deðeri kendini ve lhf deðeri ile toplayarak toplam deðeri aldýrýcak.
		rhft = rhft + rhf;
		mft = mft + mf;
	}

	cout << "----------------------------------------------"<<endl;   
	cout << "---------------  INTEGRAL RESULTS  -----------"<<endl;
	cout << "f(x)=x^3 + 4x from[" << a << "," << b << "] with " <<endl<< n << " intervals"; // sonuçlarý ekrana yazdýrýyoruz
	cout << "----------------------------------" << endl;
	cout << "MIDPOINT RULE                   : " << mft << endl;               
	cout << "LEFT HAND RULE                  : " << lhft << endl;
	cout << "RIGHT HAND  RULE                : " << rhft << endl;
	cout << "----------------------------------------------" << endl;  //son
}

