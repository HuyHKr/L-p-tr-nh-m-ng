# Bài tập về nhà môn Lập trình mạng
## 17/3/2024
1. Viết chương trình tcp_client, kết nối đến một máy chủ xác định bởi địa chỉ IP và cổng. Sau đó nhận dữ liệu từ bàn phím và gửi đến server. Tham số được truyền vào từ dòng lệnh có dạng
tcp_client <địa chỉ IP> <cổng>
2. Viết chương trình tcp_server, đợi kết nối ở cổng xác định bởi tham số dòng lệnh. Mỗi khi có client kết nối đến, thì gửi xâu chào được chỉ ra trong một tệp tin xác định, sau đó ghi toàn bộ nội dung client gửi đến vào một tệp tin khác được chỉ ra trong tham số dòng lệnh
tcp_server <cổng> <tệp tin chứa câu chào> <tệp tin lưu nội dung client gửi đến>
3. Viết chương trình sv_client, cho phép người dùng nhập dữ liệu là thông tin của sinh viên bao gồm MSSV, họ tên, ngày sinh, và điểm trung bình các môn học. Các thông tin trên được đóng gói và gửi sang sv_server. Địa chỉ và cổng của server được nhập từ tham số dòng lệnh.
4. Viết chương trình sv_server, nhận dữ liệu từ sv_client, in ra màn hình và đồng thời ghi vào file sv_log.txt.  Dữ liệu được ghi trên một dòng với mỗi client, kèm theo địa chỉ IP và thời gian client đã gửi. Tham số cổng và tên file log được nhập từ tham số dòng lệnh.
Ví dụ dữ liệu trong file log:
127.0.0.1 2023-04-10 09:00:00 20201234 Nguyen Van A 2002-04-10 3.99
127.0.0.1 2023-04-10 09:00:10 20205678 Tran Van B 2002-08-18 3.50

## Ảnh minh hoạ
![image](https://github.com/HuyHKr/L-p-tr-nh-m-ng/assets/148759236/8a841fa6-7cc0-4095-adca-ebd2ff536aa8)
![image](https://github.com/HuyHKr/L-p-tr-nh-m-ng/assets/148759236/251bb315-3a30-405b-b5f3-719f44894ddd)

