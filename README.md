# Epoch Zaman Farkı Hesaplama Programı

Bu proje, kullanıcının girdiği iki farklı tarih ve saat arasındaki farkı *epoch* zamanı üzerinden hesaplayan bir C programıdır. Program, struct ve union veri yapılarını kullanarak tarih ve saat bilgilerini saklar ve mktime() fonksiyonunu kullanarak epoch zamanına çevirir.

## Kullanılan Teknolojiler
- *C Programlama Dili*
- *Struct ve Union Kullanımı*
- **Zaman Kütüphanesi (time.h)**

## Epoch Nedir?
Epoch, *1 Ocak 1970 00:00:00 UTC* tarihinden itibaren geçen saniye sayısını ifade eden bir zaman birimidir. Bilgisayar sistemlerinde zaman hesaplamalarında yaygın olarak kullanılır.

## Kodun Çalışma Mantığı
1. Kullanıcıdan iki farklı tarih ve saat bilgisi alınır.
2. Girilen tarih ve saat bilgileri struct ve union yardımıyla saklanır.
3. Tarihler epoch zamanına çevrilir.
4. İki epoch zamanının farkı alınarak aralarındaki saniye cinsinden fark hesaplanır.
5. Sonuç ekrana yazdırılır.

## Kullanım

Programı derlemek ve çalıştırmak için:
bash
gcc epoch_time_diff.c -o epoch_time_diff
./epoch_time_diff


### Örnek Giriş ve Çıkış
*Giriş:*

Birinci tarihi giriniz (GG.AA.YYYY SS:DD:SS): 01.01.2024 12:00:00
Ikinci tarihi giriniz (GG.AA.YYYY SS:DD:SS): 02.01.2024 12:00:00


*Çıkış:*

Epoch zamanlari:
Tarih 1: 1704100800
Tarih 2: 1704187200
Iki tarih arasindaki fark (saniye): 86400 saniye

(Bu fark, tam olarak *1 gün* eder.)

## Lisans
Bu proje herhangi bir lisans altında yayınlanmamıştır, ancak ödev amacıyla kullanılabilir.
