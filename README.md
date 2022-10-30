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

### Format Hakkinda

Eger uygulama kendi icinde hatalar alirsa, cesitli uyari mesajlari verir.

Ornegin calisma esnasinda yeterli arguman verilmezse asagidaki hatayi gonderir:

```
PS C:\> .\main.exe a b c d e                        

Hatali kullanim!

##################################################

Ornek kullanim formati:
CSV2JSON.exe kaynak.csv sonuc.json header=OFF

##################################################
```

