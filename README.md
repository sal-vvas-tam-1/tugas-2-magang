# tugas-2-magang
tugas kali ini adalah "Buatlah program yang menggunakan turtlesim untuk menggambar sesuatu. (Bebas apa aja ^.^) "
untuk tugas ini saya menggunakan prinsip quadratic bezier curve untuk menggambar beberapa garis lengkung(kurva) yang dapat disusun menjadi huruf atau gambar
quadratic bezier curve sendiri adalah kurva yang dihasilkan dari 3 titik pada bidang kartesius P0 untuk titik awal P1 untuk titik kontrol dan P2 untuk titik akhir dengan menggunakan interpolasi linear (mencari nilai atau titik diantara 2 nilai atau titik yang telah diketahui)
interpolasi linear antara dua nilai bisa ditulis sebagai:
(1-t)A + t*B = Lerp(A,B,t)
A= nilai 1, B = Nilai 2, t = persentase dari 0-1
quadratic bezier curve menggunakan 3 interpolasi linear
Lerp(p0,p1,t), Lerp(p1,p2,t) dan nested Lerp(Lerp(p0,p1,t),Lerp(p1,p2,t),t) yang akan menghasilkan kurva B
Lerp(P0,P1,t) =(1-t)P0 + t*P1,  Lerp(P1,P2,t) =(1-t)P1 + t*P2
Lerp(Lerp(p0,p1,t),Lerp(p1,p2,t),t) = Lerp((1-t)P0 + t*P1,(1-t)P1 + t*P2,t)= (1-t)(1-t)P0 + (1-t)t*P1 + t((1-t)P1 + t*P2) = P0(1-t)^2 + 2t(1-t)P1 + (t^2) * P2
sehingga B = P0((1-t)^2) + 2t(1-t)P1 + (t^2) * P2
untuk koordinat kartesius 2 dimensi P(x,y) sehingga
X(t) = X0((1-t)^2) + 2t(1-t)X1 + (t^2) * X2
y(t) = y0((1-t)^2) + 2t(1-t)y1 + (t^2) * y2
namun fungsi diatas hanyalah fungsi x dan y terhadap persen t paada bidang kartesius
sedangkan saya membuat node yang publish ke /turtle1/cmd_vel yang msg nya adalah "{linear: {x, y, z}, angular: {x, y, z}}" dan karena limitasi turtlesim hanya menggunakan linear x dan angular z relatif ke turtle1 sendiri bukan global grid turtle simnya sehingga fungsi x(t) dan y(t) harus di konversi menjadi linear x dan angular z
menerapkan transformasi kinematic kita bisa mendapatkan linearx= sqrt((dx/dt * dx/dt) + (dy/dt*dy/dt)) dan angular z = ((dx/dt * ddy/dt) - (dy/dt * ddx/dt)) / ((dx/dt * dx/dt) + (dy/dt *dy/ dt))
untuk implementasi dalam node saya membuat function beziertoturtlelinear() dan beziertoturtleang() untuk dipakai pada timer_callback()
timer_callback() bekerja setiap 10 ms berisi variable t yang bertambah 0.01 setiap timer_callback() sehingga t menjadi sama dengan hitungan detik t di ubah menjadi nilai desimal < 1 untuk function berzier
untuk menulis huruf huruf dibagi menjadi beberapa kurva seperti s menjadi 2 kurva untuk lengkungan atas dan bawah
lalu cari P0 P1 dan P2 dari kurva tersebut 
masukan pada beziertoturtlelinear() dan beziertoturtleang() dan publish ke /turtle1/cmd_vel sebagai linear x dan angular z
gabungkan kurva kurva menjadi huruf pada timer_callback()

link video: https://drive.google.com/file/d/1q7LyHpPxwz6gmTHiM4AoJhMFP3T8ZF_I/view?usp=drivesdk
