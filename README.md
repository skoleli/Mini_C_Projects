# CSV TO JSON

## Table of Contents

- [About](#about)
- [Usage](#usage)

## About <a name = "about"></a>

Bu projenin amaci CSV formatli bir dosyayi, JSON formatina cevirmektir.

Tamamen C programlama dili  ile yazilmistir. 

Program calistirilirken bir ```header``` parametresi girilir ve bu parametre, ilk kolonlarin JSON formatli dosyada kolon ismi olarak kullanilip kullanilmayacagini belirler.

## Usage <a name = "usage"></a>

### Uygulama Kullanimi

Uygulama calistirilirken asagidaki format izlenmelidir:

```
CSV2JSON <CSV dosya adı> <json dosya adı> <header=ON | OFF>
```

Ornek kullanimi asagidaki gibidir:

```
C:\> CSV2JSON.exe deneme.csv sonuc.json header=OFF
```

### Uyarilar

Eger uygulama kendi icinde hatalar alirsa, cesitli uyari mesajlari verir.

Ilk calistirirken yeterli arguman verilmezse asagidaki hatayi gonderir:

```
PS C:\> .\main.exe a b c d e                        

Hatali kullanim!

##################################################

Ornek kullanim formati:
CSV2JSON.exe kaynak.csv sonuc.json header=OFF

##################################################
```

Basarili bir sekilde calistirildiysa ama verilen dosya isimlerinde bir sorun varsa asagidaki sekilde uyari vererek programi sonlandirir:

```
C:\Users\silak\Desktop\csvtojson> .\main.exe dosya.csv sonuc.json header=ON   
dosya.csv dosyasi acilamadi!
```

Programa arguman sayisi dogru verilip dosyalari acmada bir problem yasanmadiysa ama header parametresinde kullanim kontrol edilir. Yanlissa asagidaki uyari verilir ve program sonlandirilir:

```
C:\> .\main.exe 0.csv sonuc.json header=of       
header parametresini gozden gecirin!
dogru kullanim: header=ON
```

### Ornek calisma:

Asagidaki bilgileri iceren CSV formatli bir dosya,

```
OKULNO,AD,SOYAD,BOLUM
1,ayse,yilmaz,ogretmen
2,fatma,yilmaz,muhendis
3,hayriye,yilmaz,siyaset
4,ahmet,korkmaz,ekonomi
```

programa ```header=ON``` parametresiyle girildiginde asagidaki gibi gorunur:

```
{
	"satir1" : {
		"OKULNO":"1",
		"AD":"ayse",
		"SOYAD":"yilmaz",
		"BOLUM":"ogretmen"
	},
	"satir2" : {
		"OKULNO":"2",
		"AD":"fatma",
		"SOYAD":"yilmaz",
		"BOLUM":"muhendis"
	},
	"satir3" : {
		"OKULNO":"3",
		"AD":"hayriye",
		"SOYAD":"yilmaz",
		"BOLUM":"siyaset"
	},
	"satir4" : {
		"OKULNO":"4",
		"AD":"ahmet",
		"SOYAD":"korkmaz",
		"BOLUM":"ekonomi"
	}
}
```