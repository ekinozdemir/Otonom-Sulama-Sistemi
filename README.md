### 📂 Proje İçeriği
* [Arduino Kodlarını İncele (sulama.ino)](sulama.ino)
* [Sistem Çalışma Videosu (Drive)](https://drive.google.com/file/d/1iGchyq1bho7j1GyjtyOFza2EJ55QMSk7/view?usp=sharing)
* [Fotoğraflar için (Drive)](https://drive.google.com/file/d/1eyNff31AjC-5EL4xWh41ZqYzUfl8t8Y3/view?usp=sharing)
* [TÜBİTAK'tan (Drive)](https://drive.google.com/file/d/1YM__MukgRLUYw378LGSfpkoJjjnMwlVK/view?usp=sharing)
## 💧 Otonom Akıllı Sulama Sistemi

Bu proje, tarımda ve ev bitkilerinde su israfını önlemek ve bitki sağlığını korumak amacıyla geliştirilmiş **akıllı bir otomasyon sistemidir.** ### 🚀 Projenin Amacı
Geleneksel sulama yöntemlerinde bitkiler ya çok fazla sulanarak çürümekte ya da susuz kalarak kurumaktadır. Bu sistem, toprağın ihtiyacını anlık olarak analiz ederek **sadece gerektiğinde** sulama yapar.

### 🛠️ Nasıl Çalışır?
1. **Veri Toplama:** Toprak nem sensörü, bitkinin kök bölgesindeki nem oranını ölçer.
2. **Karar Verme:** Arduino Uno, gelen veriyi işler. Eğer nem oranı belirlenen eşik değerin (örn. %30) altına düşerse sistemi tetikler.
3. **Uygulama:** 5V Röle modülü su pompasını çalıştırır ve LCD ekran üzerinden kullanıcıya "Sulama Yapılıyor" bilgisini verir.
4. **Durdurma:** Nem seviyesi ideal noktaya ulaştığında sistem otomatik olarak durur.

### 📈 Öne Çıkan Özellikler
* **Su Tasarrufu:** Sadece ihtiyaç anında sulama yaparak su kaynaklarını korur.
* **Bitki Sağlığı:** Aşırı sulamanın önüne geçerek bitki köklerinin oksijensiz kalmasını engeller.
* **Tam Otomatik:** İnsan müdahalesine gerek duymadan 7/24 çalışabilir.

---
*Bu proje TÜBİTAK 4006 Bilim Şenliği kapsamında Ekin Özdemir, Nisanur Tangör, Ahmet Deniz Doğan tarafından geliştirilmiştir.*

### Ne Yaptık?
Arduino Uno USB yolu ile bilgisayara bağlanarak COM7 den aktif edilir ve bağlantı sağlanır (Öncesinde arduinoyu tanıması için bilgisayara program indirilir sonra da Arduino İMD kullanılır.) Sonra toprak nem sensörünün uçları, nem sensörünün yanında gelen mavi karta bağlanır. O mavi karttan VDD 5V GND GND'ye bağlanır A0 A0'a bağlanır. LCD Ekranın VCC kısmı arduino 5V'a, GND kısmı GND'ye, SCL ve SDD kısmı da sıraıyla A4 ve A5 pinine takılır. Bu işlem bittikten sonra röle bağlantısını kurmak için VDD 5V'a GND GND'ye ve kalan tel de 8. pine takılır (Söylediğimiz pinler öncesinde arduino imd de yazılımsal olarak aktif edilir.). Röle bağlantısından sonra pompa için ya 6V adaptör ya da 9V pil kullanılır. Biz 6V adaptör kullandık. Adaptörün ucu kesilir ve "+" ve "-" kutuplar ortaya çıkar. Kablolar soyulur ve "+" ucu röledeki COM girişine takılır. Pompanın da kırmızı ucu röledeki NO ya takılır. Daha sonra kalan adaptör "-" ucu ile pompanın siyah ucu yani bakır teller birbirine lehimlenir bu şekilde adaptörü fişe taktığımızda pompa çalışır. Bu işlemler yapıldıktan sonra (sulama.ino) klasörümüzdeki yazılımları arduino imd'ye geçirilir ve sol üstteki "ok" işaretine basılır. Bu şekilde lcd.print yazılımlarımız sayesinde LCD ekranda sulama ile ilgili bilgiler verilir (İsterseniz nem değerlerini yansıtabilirsiniz yazılımı kullanarak ancak biz parazitlenmeden dolayı son dakika buna çevirdik.), nem değeri toprağa koyduğunuz nem sensörü verilerine göre arduinoya iletilir ve yazılıma yazdığınız eşik değere göre röle açılır ya da kapanır, bu şekilde pompa da açılır ya da kapanır. Bu sistem nem değeri düştüğünde pompanın açılmasını, yükseldiğinde pompanın kapanmasını sağlar ve bitki otonom sulanır.
