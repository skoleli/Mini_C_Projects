# CSV TO JSON

## Table of Contents

- [About](#about)
- [Usage](#usage)

## About <a name = "about"></a>

Bu projenin amaci CSV formatli bir dosyayi, JSON formatina cevirmektir.

Tamamen C programlama dili  ile yazilmistir. 

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