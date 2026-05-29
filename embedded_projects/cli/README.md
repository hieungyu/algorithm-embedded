## Modular giả lập xử lý gói tin (Packet Frame) UART.


#### Trong thực tế thì làm việc với Linux Nhúng (như trên con LicheePi Nano), hệ thống luôn chia làm 2 phần:
1. Back-end: Các module xử lí gói tin (ví dụ như Xử lí gói tin UART như project này). Nó sẽ phân tích dữ liệu, tính toán mã lỗi (Checksum), đóng gói và bóc tách dữ liệu như 1 người công nhân trong nhà máy.
2. Front-end (User Interface): Chính là cái CLI (Command Line Interface). Nó đòng vai trò như quản đốc, khi gõ lệnh **Send_Temp 25** vào **Terminal**, CLI sẽ dịch các lệnh đó và sai anh công nhân UART đóng gói số 25 thành 1 Frame chuẩn để gửi đi.
---

#### Gói tin (Frame) UART là gì ? (Feynman Style)
- Có 1 vấn đề là nếu truyền dữ liệu qua UART bằng cách gửi từng chữ cái rời rạc (ví dụ: H, E, L, L, O), trên đường truyền nhiễu, chữ 'H' có thể biến mất, dẫn đễ bên nhận sẽ đọc thành 'ELLO' và hiểu sai hoàn toàn.
- Vì vậy lúc này ta cần đóng gói dữ liệu vào một cái "Thùng hàng" gọi là **Frame**.
- Cấu trúc của Frame:

1. **Băng dính niêm phong (Start Byte/Header):** Dấu hiệu cho biết "À, đây là bắt đầu một gói hàng mới". (Thường dùng mã HEX đặc biệt như **0xAA** hoặc **0x55**).

2. **Tem ghi chú kích thước (Length):** Báo cho bên nhận biết trong hộp có bao nhiêu món đồ, để họ không bị lấy thiếu.

3. **Phân loại hàng (Command ID):** Mã cho biết gói hàng này chứa gì (Ví dụ: **0x01** là dữ liệu Nhiệt độ, **0x02** là Bật đèn ).

4. **Món đồ bên trong (Payload/Data):** Dữ liệu thực tế sẽ gửi (Ví dụ: **25** độ C ).

5. **Chữ ký xác nhận (Checksum/CRC)**: Một con số toán học đặc biệt cộng trừ tất cả các món đồ trên. Bên nhận được sẽ tự tính lại, nếu nó khớp với chữ kí thì chứng tỏ hàng nguyên vẹn, không bị bóp meo dọc đường do nhiễu từ trường.